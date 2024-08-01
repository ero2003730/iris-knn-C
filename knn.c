// knn.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "iris.h"

void ColocaPlanoTreinamento(Flor flores[], Plano plano[], int count)
{
    int treinamento = (int)(count * 0.8); // Casting necessário para evitar perda de precisão

    for (int i = 0; i < treinamento; i++)
    {
        plano[i].x = flores[i].sepal_length;
        plano[i].y = flores[i].sepal_width;
        plano[i].z = flores[i].petal_length;
        plano[i].h = flores[i].petal_width;
    }
}

double DistanciaEuclidiana(double x1, double x2, double y1, double y2, double z1, double z2, double h1, double h2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    double dh = h1 - h2;
    return sqrt(dx * dx + dy * dy + dz * dz + dh * dh);
}

int returnClass(Flor flores[], int k, int vet[])
{
    int class0 = 0, class1 = 0, class2 = 0;
    for (int i = 0; i < k; i++)
    {
        if (flores[vet[i]].classe == 0)
            class0++;
        else if (flores[vet[i]].classe == 1)
            class1++;
        else if (flores[vet[i]].classe == 2)
            class2++;
    }
    if (class0 >= class1 && class0 >= class2)
        return 0;
    else if (class1 >= class0 && class1 >= class2)
        return 1;
    else
        return 2;
}

int DescobreClasse(Flor flores[], Plano plano[], int treinamento, int i, int k)
{
    int vetPos[k];
    double vetDis[k];
    double dist;

    // Inicializar os vetores com valores iniciais extremos
    for (int j = 0; j < k; j++)
    {
        vetDis[j] = DBL_MAX;
        vetPos[j] = -1;
    }

    for (int j = 0; j < treinamento; j++)
    {
        dist = DistanciaEuclidiana(plano[j].x, flores[i].sepal_length, plano[j].y, flores[i].sepal_width, plano[j].z, flores[i].petal_length, plano[j].h, flores[i].petal_width);

        // Encontrar a posição para inserir esta distância nos k menores
        for (int l = 0; l < k; l++)
        {
            if (dist < vetDis[l])
            {
                for (int m = k - 1; m > l; m--)
                {
                    vetDis[m] = vetDis[m - 1];
                    vetPos[m] = vetPos[m - 1];
                }
                vetDis[l] = dist;
                vetPos[l] = j;
                break;
            }
        }
    }

    return returnClass(flores, k, vetPos);
}

void knn(Flor flores[], Plano plano[], int count, int k)
{
    ColocaPlanoTreinamento(flores, plano, count);

    int treinamento = (int)(count * 0.8);
    int teste = count - treinamento; // Corrigido para garantir que 20% dos dados são usados para teste

    int previstas[teste];
    int reais[teste];
    int idx = 0;

    for (int i = treinamento; i < count; i++)
    {
        previstas[idx] = DescobreClasse(flores, plano, treinamento, i, k);
        reais[idx] = flores[i].classe;

        printf("Predito: %d, Real: %d\n", previstas[idx], reais[idx]); // Imprime predito vs real
        idx++;
    }

    double acuracia, acuracia_balanceada;
    verificacao(previstas, reais, teste, &acuracia, &acuracia_balanceada);

    printf("Acurácia: %.2f\n", acuracia);
    printf("Acurácia Balanceada: %.2f\n", acuracia_balanceada);

    // Calcula e imprime a matriz de confusão
    int matriz_confusao[3][3] = {0};

    for (int i = 0; i < teste; i++)
    {
        matriz_confusao[reais[i]][previstas[i]]++;
    }

    printf("Matriz de Confusão:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz_confusao[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular acurácia e acurácia balanceada
void verificacao(int previstas[], int reais[], int tamanho, double *acuracia, double *acuracia_balanceada)
{
    int tp[3] = {0, 0, 0}; // Verdadeiro positivo para cada classe
    int tn[3] = {0, 0, 0}; // Verdadeiro negativo para cada classe
    int fp[3] = {0, 0, 0}; // Falso positivo para cada classe
    int fn[3] = {0, 0, 0}; // Falso negativo para cada classe

    // Calcula tp, tn, fp, fn para cada classe
    for (int i = 0; i < tamanho; i++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (reais[i] == c)
            {
                if (previstas[i] == c)
                {
                    tp[c]++;
                }
                else
                {
                    fn[c]++;
                }
            }
            else
            {
                if (previstas[i] == c)
                {
                    fp[c]++;
                }
                else
                {
                    tn[c]++;
                }
            }
        }
    }

    // Calcula acurácia
    int total_acertos = tp[0] + tp[1] + tp[2];
    *acuracia = (double)total_acertos / tamanho;

    // Calcula sensibilidade (recall) e especificidade para cada classe
    double sensibilidade[3];
    double especificidade[3];
    for (int c = 0; c < 3; c++)
    {
        sensibilidade[c] = tp[c] / (double)(tp[c] + fn[c]);
        especificidade[c] = tn[c] / (double)(tn[c] + fp[c]);
    }

    // Calcula acurácia balanceada
    *acuracia_balanceada = (sensibilidade[0] + sensibilidade[1] + sensibilidade[2] +
                            especificidade[0] + especificidade[1] + especificidade[2]) /
                           6.0;
}