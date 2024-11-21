// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>
#include <stdlib.h>

// Configs

#define INPUT_SELECTION_INSERT            1 // Incluir nó
#define INPUT_SELECTION_REMOVE            2 // Remover nó
#define INPUT_SELECTION_SEARCH_PRE_ORDER  3 // Buscar pré-ordem
#define INPUT_SELECTION_SEARCH_ORDER      4 // Buscar em ordem
#define INPUT_SELECTION_SEARCH_POST_ORDER 5 // Buscar pós-ordem

#define EXIT_INPUT_SELECTION 0

// Estrutura do nó
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Cria um novo nó
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
  {
    printf("[ ! ] Erro de alocacao de memoria.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

Node *insert(Node *head, int data)
{
  if (head == NULL) {
      printf("    [ * ] Valor '%d' inserido na arvore.\n", data);
      return createNode(data);
  }

  if (data < head->data) {
      head->left = insert(head->left, data);
  } else if (data > head->data) {
      head->right = insert(head->right, data);
  } else {
    printf("    [ ! ] Valor '%d' ja existe na arvore.\n", data);
  }

  return head;
}

// Remover nó
void delete(Node **head, int data)
{
  printf("    [ * ] Valor '%d' removido da lista.\n", data);
}

// Buuscar nó pre-ordem
void searchPreOrder(Node *head, int data)
{
}

// Buuscar nó pre-ordem
void searchOrder(Node *head, int data)
{
}

// Buuscar nó pre-ordem
void searchPostOrder(Node *head, int data)
{
}

int main()
{
  Node *head = NULL;
  int option, value, newValue;

  do

  // Incluir nó
  // Remover nó
  // Buscar pré-ordem
  // Buscar em ordem
  // Buscar pós-ordem

  {
    printf("\n-------------------------------------------------------\n");
    printf("\nEscolha uma operacao:\n\n");

    printf("[ %d ] Inserir\n", INPUT_SELECTION_INSERT); // Op 1
    printf("[ %d ] Remover\n", INPUT_SELECTION_REMOVE); // Op 2

    printf("[ %d ] [ Buscar ] Pre-ordem\n", INPUT_SELECTION_SEARCH_PRE_ORDER);  // Op 3
    printf("[ %d ] [ Buscar ] em ordem\n", INPUT_SELECTION_SEARCH_ORDER); // Op 4
    printf("[ %d ] [ Buscar ] Pos-ordem\n", INPUT_SELECTION_SEARCH_POST_ORDER); // Op 5

    printf("\n[ %d ] Sair\n\n", EXIT_INPUT_SELECTION); // Op 0
    printf("\n-------------------------------------------------------\n");

    printf("[ ? ] Opcao: ");

    if (scanf("%d", &option) != 1)
    {
      printf("[ ! ] Entrada invalida. Digite um numero.\n");
      while (getchar() != '\n')
        ;
      option = -1;
    }
    else if (option < EXIT_INPUT_SELECTION || option > INPUT_SELECTION_SEARCH_POST_ORDER)
    {
      printf("[ ! ] Selecione uma opcao valida (entre %d - %d).\n", EXIT_INPUT_SELECTION, INPUT_SELECTION_SEARCH_POST_ORDER);
      option = -1;
    }

    switch (option)
    {
    case INPUT_SELECTION_INSERT: // Opt 1
      printf("[ + ] Adicionar \n");
      printf("[ + ] Digite o valor que quer adicionar: ");
      scanf("%d", &value);
      head = insert(head, value);
      break;

    case INPUT_SELECTION_REMOVE: // Opt 2
      printf("[ - ] Apagar \n");
      // printf("[ * ] Estes são os valores atuais: ");
      // display(head); TODO: Add busca e listagem pra melhorar o DX/UX
      printf("[ - ] Digite o valor que quer apagar: ");
      scanf("%d", &value);
      delete (&head, value);
      break;

    case INPUT_SELECTION_SEARCH_PRE_ORDER: // Opt 3
      printf("[ * ] Buscar PRÉ ORDEM \n");
      printf("[ * ] Digite o valor que quer buscar: ");
      scanf("%d", &value);
      searchPreOrder(head, value);
      break;

    case INPUT_SELECTION_SEARCH_ORDER: // Opt 4
      printf("[ * ] Buscar EM ORDEM \n");
      printf("[ * ] Digite o valor que quer buscar: ");
      scanf("%d", &value);
      searchOrder(head, value);
      break;

    case INPUT_SELECTION_SEARCH_POST_ORDER: // Opt 5
      printf("[ * ] Buscar PÓS ORDEM \n");
      printf("[ * ] Digite o valor que quer buscar: ");
      scanf("%d", &value);
      searchPostOrder(head, value);
      break;

    case EXIT_INPUT_SELECTION: // Opt 0
      printf("[ * ] Saindo...\n");
      break;

    default: // Opt 6 - ∞ (hehehe)
      printf("[ ! ] Tente novamente.\n");
    }

  } while (option != EXIT_INPUT_SELECTION);

  return 0;
}
