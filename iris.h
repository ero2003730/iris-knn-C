#ifndef IRIS_H
#define IRIS_H

// Definição da estrutura para representar os atributos das flores Iris
typedef struct
{
    float sepal_length; // Comprimento da sépala
    float sepal_width;  // Largura da sépala
    float petal_length; // Comprimento da pétala
    float petal_width;  // Largura da pétala
    char variety[20];   // Variedade da flor Iris
    int classe;         // Classe atribuída após a execução do k-NN
} Flor;

// Estrutura para representar os planos em um espaço de quatro dimensões
typedef struct
{
    float x; // Valor x, mapeia para sepal_length no contexto do k-NN
    float y; // Valor y, mapeia para sepal_width
    float z; // Valor z, mapeia para petal_length
    float h; // Valor h, mapeia para petal_width
} Plano;

// Declarações de funções que devem ser definidas em outro lugar no projeto
void ColocaPlanoTreinamento(Flor flores[], Plano plano[], int count);
void knn(Flor flores[], Plano plano[], int count, int k);
void verificacao(int previstas[], int reais[], int tamanho, double *acuracia, double *acuracia_balanceada);
void ColocaClasse(Flor flores[], int count); // Função para inicializar/corrigir a classe de cada Flor, se necessário
void IniciaPlano(Plano plano[], int count);  // Função para inicializar os planos com base nos dados de flor
void embaralhar(Flor flores[], int count);   // Função para embaralhar os dados

#endif // IRIS_H