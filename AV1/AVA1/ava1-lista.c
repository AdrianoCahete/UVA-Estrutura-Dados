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
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insere um novo nó
void insert(Node **head, int data)
{
  Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    Node *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  printf("    [ + ] Valor '%d' inserido na lista.\n", data);
}

// Update do nó
void update(Node *head, int oldValue, int newValue)
{
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == oldValue) // TODO: verificar se tenho como colar o while e o if no mesmo item
    {
      temp->data = newValue;
      printf("    [ * ] Valor %d alterado para %d.\n", oldValue, newValue);
      return;
    }
    temp = temp->next;
  }
  printf("    [ ! ] Valor %d não encontrado para alteração.\n", oldValue);
}

// Remover nó
void delete(Node **head, int data)
{
  Node *temp = *head;
  Node *prev = NULL;

  while (temp != NULL && temp->data != data)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("    [ ! ] Valor %d não encontrado para remoção.\n", data);
    return;
  }

  if (prev == NULL)
  {
    *head = temp->next;
  }
  else
  {
    prev->next = temp->next;
  }

  free(temp);
  printf("    [ * ] Valor %d removido da lista.\n", data);
}

// Listar nó
void display(Node *head)
{
  Node *temp = head;
  printf("    [ * ] Elementos na lista: ");

  while (temp != NULL)
  {
    printf("%d : ", temp->data);
    temp = temp->next;
  }
  printf("Nada");
}

// Biuscar nó
void search(Node *head, int data)
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("    [ * ] Valor %d encontrado na lista.\n", data);
    return;
  }
  printf("    [ ! ] Valor %d não encontrado na lista.\n", data);
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
    case INPUT_SELECTION_INSERT: // Opt 1
      printf("[ + ] Adicionar ");
      printf("[ + ] Digite o valor que quer adicionar: ");
      scanf("%d", &value);
      insert(&head, value);
      break;

    case INPUT_SELECTION_CONSULT: // Opt 2
      printf("[ * ] Consultar ");
      printf("[ * ] Digite o valor que quer buscar: ");
      scanf("%d", &value);
      search(head, value);
      break;

    case INPUT_SELECTION_CHANGE: // Opt 3
      printf("[ * ] Alterar ");
      printf("[ * ] Digite o valor que quer alterar ");
      scanf("%d", &value);

      printf("[ * ] Digite o novo valor: ");
      scanf("%d", &newValue);
      update(head, value, newValue);
      break;

    case INPUT_SELECTION_REMOVE: // Opt 4
      printf("[ - ] Remover ");
      printf("[ - ] Digite o valor que quer apagar: ");
      scanf("%d", &value);
      delete (&head, value);
      break;

    case INPUT_SELECTION_LIST: // Opt 5
      printf("[ * ] Listar ");
      display(head);
      break;

    case EXIT_INPUT_SELECTION: // Opt 0
      printf("[ * ] Saindo...\n");
      break;

    default: // Opt 7 - ∞ (hehehe)
      printf("[ ! ] Opcao invalida. Tente novamente.\n");
    }

  } while (option != EXIT_INPUT_SELECTION);

  return 0;
}
