# Iris K-NN Classifier in C

This project implements a k-Nearest Neighbors (k-NN) classifier in C for the Iris dataset. The code reads the Iris data from a CSV file, shuffles the data, divides it into training and testing sets, and applies the k-NN algorithm to predict the class of the flowers.

## Project Structure

The project is organized into several files, each responsible for a specific part of the implementation:

- `main.c`: Contains the main function that coordinates the execution of the program. 
  - Reads the data from the `iris.csv` file.
  - Fills the `Flor` structures with the read data.
  - Initializes and shuffles the data.
  - Calls the `knn` function to apply the k-NN algorithm.
  - Calculates and prints the accuracy, balanced accuracy, and confusion matrix.

- `iris.h`: Declaration of the structures and functions used in the project.
  - Defines the `Flor` structure to represent the attributes of the Iris flowers.
  - Defines the `Plano` structure to represent the planes in a four-dimensional space.
  - Declares the functions used to manipulate the data, such as `ColocaClasse`, `IniciaPlano`, `embaralhar`, among others.

- `iris.c`: Implementation of the data initialization and manipulation functions.
  - Implements the `ColocaClasse` function to assign the numeric class based on the variety of the flower.
  - Implements the `IniciaPlano` function to initialize the `Plano` structure.
  - Implements the `embaralhar` function to shuffle the data before applying k-NN.

- `knn.c`: Implementation of the k-NN algorithm and auxiliary functions.
  - Implements the `knn` function that applies the k-NN algorithm to the data.
  - Includes auxiliary functions such as `DistanciaEuclidiana` to calculate the distance between points and `DescobreClasse` to determine the class of a point based on its nearest neighbors.
  - Calculates the accuracy and balanced accuracy of the results.
  - Generates and prints the confusion matrix to evaluate the model's performance.

## How to Compile and Run

1. **Compile:**
   
```sh
   gcc -o iris_knn main.c iris.c knn.c -lm
```

2. **Run:**

```sh
   ./iris_knn
```

## Data Structure

### Flor Structure

The Flor structure represents the attributes of the Iris flowers:

````c
typedef struct
{
    float sepal_length; // Sepal length
    float sepal_width;  // Sepal width
    float petal_length; // Petal length
    float petal_width;  // Petal width
    char variety[20];   // Variety of the Iris flower
    int classe;         // Class assigned after executing the k-NN
} Flor;
````

### Plano Structure

The Plano structure represents the planes in a four-dimensional space used by the k-NN algorithm:

````c
typedef struct
{
    float x; // x value, maps to sepal_length in the k-NN context
    float y; // y value, maps to sepal_width
    float z; // z value, maps to petal_length
    float h; // h value, maps to petal_width
} Plano;
````

## Contributions

Feel free to contribute with improvements or new features for this project. Send a pull request or open an issue on the GitHub repository.

## Licença

This project is licensed under the [MIT License.](https://opensource.org/licenses/MIT)


---

# Iris K-NN Classificador em C

Este projeto implementa um classificador k-Nearest Neighbors (k-NN) em C para o conjunto de dados Iris. O código lê os dados do Iris a partir de um arquivo CSV, embaralha os dados, divide-os em conjuntos de treinamento e teste, e aplica o algoritmo k-NN para prever a classe das flores.

## Estrutura do Projeto

O projeto está organizado em vários arquivos, cada um responsável por uma parte específica da implementação:

- `main.c`: Contém a função principal que coordena a execução do programa. 
  - Lê os dados do arquivo `iris.csv`.
  - Preenche as estruturas `Flor` com os dados lidos.
  - Inicializa e embaralha os dados.
  - Chama a função `knn` para aplicar o algoritmo k-NN.
  - Calcula e imprime a acurácia, acurácia balanceada e a matriz de confusão.

- `iris.h`: Declaração das estruturas e funções utilizadas no projeto.
  - Define a estrutura `Flor` para representar os atributos das flores Iris.
  - Define a estrutura `Plano` para representar os planos em um espaço de quatro dimensões.
  - Declara as funções usadas para manipular os dados, como `ColocaClasse`, `IniciaPlano`, `embaralhar`, entre outras.

- `iris.c`: Implementação das funções de inicialização e manipulação dos dados.
  - Implementa a função `ColocaClasse` para atribuir a classe numérica baseada na variedade da flor.
  - Implementa a função `IniciaPlano` para inicializar a estrutura `Plano`.
  - Implementa a função `embaralhar` para embaralhar os dados antes de aplicar o k-NN.

- `knn.c`: Implementação do algoritmo k-NN e funções auxiliares.
  - Implementa a função `knn` que aplica o algoritmo k-NN nos dados.
  - Inclui funções auxiliares como `DistanciaEuclidiana` para calcular a distância entre pontos e `DescobreClasse` para determinar a classe de um ponto baseado em seus vizinhos mais próximos.
  - Calcula a acurácia e a acurácia balanceada dos resultados.
  - Gera e imprime a matriz de confusão para avaliar o desempenho do modelo.

## Como Compilar e Executar

1. **Compilar:**
   
```sh
   gcc -o iris_knn main.c iris.c knn.c -lm
```
2. **Executar:**

```sh
   ./iris_knn
```

## Estrutura dos Dados

### Estrutura Flor

A estrutura Flor representa os atributos das flores Iris:

````c
typedef struct
{
    float sepal_length; // Comprimento da sépala
    float sepal_width;  // Largura da sépala
    float petal_length; // Comprimento da pétala
    float petal_width;  // Largura da pétala
    char variety[20];   // Variedade da flor Iris
    int classe;         // Classe atribuída após a execução do k-NN
} Flor;
````

### Estrutura Plano

A estrutura Plano representa os planos em um espaço de quatro dimensões usados pelo algoritmo k-NN:

````c
typedef struct
{
    float x; // Valor x, mapeia para sepal_length no contexto do k-NN
    float y; // Valor y, mapeia para sepal_width
    float z; // Valor z, mapeia para petal_length
    float h; // Valor h, mapeia para petal_width
} Plano;
````

## Contribuições

Sinta-se à vontade para contribuir com melhorias ou novas funcionalidades para este projeto. Envie um pull request ou abra uma issue no repositório do GitHub.

## Licença

Este projeto é licenciado sob a [MIT License.](https://opensource.org/licenses/MIT)