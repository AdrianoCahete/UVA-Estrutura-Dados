// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>

// Main
int main()
{
  // Estrutura do nó
  typedef struct Node
  {
    int data;
    struct Node *next;
  } Node;

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

  } while (option != 6);

  return 0;
}
