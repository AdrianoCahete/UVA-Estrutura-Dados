// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>
#include <stdlib.h>

// Configs
#define EXIT_INPUT_SELECTION 0

// Estrutura do nó
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Cria um novo nó
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
  {
    printf("[ ! ] Erro de alocação de memória.\n");
    exit(1);
  }

  return newNode;
}

// Insere um novo nó
void insert(Node **head, int data)
{
  Node *newNode = createNode(data);
  printf("    [ + ] Valor '%d' inserido na lista.\n", data);
}

// Main
int main()
{
  Node *head = NULL;
  int option, value, newValue;

  do
  {
    printf("\n---------------------------\n");
    printf("\nEscolha uma operacao:\n\n");

    printf("[ 1 ] Inserir\n");
    printf("[ 2 ] Consultar\n");
    printf("[ 3 ] Alterar\n");
    printf("[ 4 ] Remover\n");
    printf("[ 5 ] Listar\n");

    printf("\n[ %d ] Sair\n\n", EXIT_INPUT_SELECTION);
    printf("---------------------------\n\n");
    printf("[ ? ] Opcao: ");
    scanf("%d", &option);
    printf("\n---------------------------\n");

    switch (option)
    {
    case 1:
      printf("[ + ] Digite o valor a ser inserido: ");
      scanf("%d", &value);
      insert(&head, value);
      break;

    case 2:
      printf("[ * ] Constular ");
      scanf("%d", &value);
      // TODO: Buscar
      break;

    case 3:
      printf("[ * ] Alterar ");
      scanf("%d", &value);
      // TODO: Alterar
      break;

    case 4:
      printf("[ - ] Remover ");
      scanf("%d", &value);
      // TODO: Apagar
      break;

    case 5:
      printf("[ * ] Listar ");
      scanf("%d", &value);
      // TODO: Listar
      break;

    case EXIT_INPUT_SELECTION:
      printf("\n[ * ] Saindo...\n");
      break;

    default:
      printf("\n[ ! ] Opcao invalida. Tente novamente.\n");
    }

  } while (option != EXIT_INPUT_SELECTION);

  return 0;
}
