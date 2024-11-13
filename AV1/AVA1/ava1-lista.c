// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>

// Estrutura do nó
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Função para inserir um nó no final da lista
void insert(Node **head, int data)
{
  Node *newNode = createNode(data);
  printf("Valor %d inserido na lista.\n", data);
}

// Main
int main()
{

  int option;

  do
  {
    printf("\nEscolha uma operacao:\n\n");

    printf("[ 1 ] Inserir\n");
    printf("[ 2 ] Consultar\n");
    printf("[ 3 ] Alterar\n");
    printf("[ 4 ] Remover\n");
    printf("[ 5 ] Listar\n");

    printf("\n[ 0 ] Sair\n");
    printf("---------------------------\n");
    printf("Opcao: ");
    scanf("%d", &option);
    printf("---------------------------\n");

  } while (option != 0);

  return 0;
}
