// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>
#include <stdlib.h>

// Configs
#define INPUT_SELECTION_INSERT 1
#define INPUT_SELECTION_CONSULT 2
#define INPUT_SELECTION_CHANGE 3
#define INPUT_SELECTION_REMOVE 4
#define INPUT_SELECTION_LIST 5
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

    printf("[ %d ] Inserir\n", INPUT_SELECTION_INSERT);
    printf("[ %d ] Consultar\n", INPUT_SELECTION_CONSULT);
    printf("[ %d ] Alterar\n", INPUT_SELECTION_CHANGE);
    printf("[ %d ] Remover\n", INPUT_SELECTION_REMOVE);
    printf("[ %d ] Listar\n", INPUT_SELECTION_LIST);

    printf("\n[ %d ] Sair\n\n", EXIT_INPUT_SELECTION);
    printf("---------------------------\n\n");
    printf("[ ? ] Opcao: ");
    scanf("%d", &option);
    printf("\n---------------------------\n\n");

    switch (option)
    {
    case INPUT_SELECTION_INSERT:
      printf("[ + ] Digite o valor a ser inserido: ");
      scanf("%d", &value);
      insert(&head, value);
      break;

    case INPUT_SELECTION_CONSULT:
      printf("[ * ] Consultar ");
      scanf("%d", &value);
      // TODO: Buscar
      break;

    case INPUT_SELECTION_CHANGE:
      printf("[ * ] Alterar ");
      scanf("%d", &value);
      // TODO: Alterar
      break;

    case INPUT_SELECTION_REMOVE:
      printf("[ - ] Remover ");
      scanf("%d", &value);
      // TODO: Apagar
      break;

    case INPUT_SELECTION_LIST:
      printf("[ * ] Listar ");
      scanf("%d", &value);
      // TODO: Listar
      break;

    case EXIT_INPUT_SELECTION:
      printf("[ * ] Saindo...\n");
      break;

    default:
      printf("[ ! ] Opcao invalida. Tente novamente.\n");
    }

  } while (option != EXIT_INPUT_SELECTION);

  return 0;
}
