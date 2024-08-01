#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iris.h"

int main()
{
    FILE *file = fopen("iris.csv", "r"); // Abra o arquivo CSV para leitura
    if (file == NULL)
    {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[1024]; // Buffer para armazenar cada linha do arquivo

    // Leia a primeira linha e ignore (geralmente contém cabeçalhos)
    if (fgets(line, sizeof(line), file))
    {
        // Ignorar a linha de cabeçalho
    }

    // Array para armazenar as structs Flor
    Flor flores[150];
    Plano plano[150];

    int count = 0;

    // Leia cada linha do arquivo e preencha a struct
    while (fgets(line, sizeof(line), file))
    {
        Flor flor;
        char *token;

        // Leia sepal_length
        token = strtok(line, ",");
        flor.sepal_length = atof(token);

        // Leia sepal_width
        token = strtok(NULL, ",");
        flor.sepal_width = atof(token);

        // Leia petal_length
        token = strtok(NULL, ",");
        flor.petal_length = atof(token);

        // Leia petal_width
        token = strtok(NULL, ",");
        flor.petal_width = atof(token);

        // Leia variety
        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // Remove newline and quotes
            token[strcspn(token, "\n")] = 0;
            token++;                      // Skip the first quote
            token[strlen(token) - 1] = 0; // Remove the last quote
            strncpy(flor.variety, token, sizeof(flor.variety) - 1);
            flor.variety[sizeof(flor.variety) - 1] = '\0'; // Ensure null-terminated
        }

        // Armazene a struct no array
        flores[count++] = flor;
    }

    fclose(file); // Feche o arquivo

    // Atribua a classe às flores
    ColocaClasse(flores, count);
    IniciaPlano(plano, count);

    // Embaralhe os dados antes de aplicar k-NN
    embaralhar(flores, count);

    printf("--------------------------------------------------");

    int k = 3;
    knn(flores, plano, count, k); // Aplica k-NN

    int previstas[150];
    int reais[150]; // Aqui você deveria ter um modo de obter as classes reais, para exemplo, vamos supor que já estão em 'flores'

    for (int i = 0; i < count; i++)
    {
        previstas[i] = flores[i].classe; // Supõe que knn modifica flores[].classe
        reais[i] = flores[i].classe;     // Deveria ser a classe real, aqui apenas para exemplo
    }

    double acuracia, acuracia_balanceada;
    verificacao(previstas, reais, count, &acuracia, &acuracia_balanceada);


    return 0;
}