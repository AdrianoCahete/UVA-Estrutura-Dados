// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)
// Sim, copiado da AVA1, vou recriar do zero se já tenho a base, porque?

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

// Utils
Node *findMin(Node *root) {
  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

// Cria um novo nó
Node *create(int data)
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

// Insere nó
Node *insert(Node *root, int data)
{
  if (root == NULL) {
    printf("    [ * ] Valor '%d' inserido na arvore.\n", data);
    return create(data);
  }

  if (data < root -> data) {
    root -> left = insert(root -> left, data);
  } else if (data > root -> data) {
    root -> right = insert(root -> right, data);
  } else {
    printf("    [ ! ] Valor '%d' ja existe na arvore.\n", data);
  }

  return root;
}

// Remove nó
Node *delete(Node *root, int data) {
  if (root == NULL) {
      printf("[ ! ] Valor %d nao encontrado.\n", data);
      return NULL;
  }

  if (data < root -> data) {
      root -> left = delete(root -> left, data);
  } else if (data > root -> data) {
      root -> right = delete(root -> right, data);
  } else {
      if (root -> left == NULL && root -> right == NULL) {
          free(root);
          root = NULL;
      } else if (root -> left == NULL || root -> right == NULL) {
          Node *temp = root -> left ? root -> left : root -> right;
          free(root);
          root = temp;
      } else {
          Node *temp = findMin(root -> right);
          root -> data = temp -> data;
          root -> right = delete(root -> right, temp -> data);
      }

      printf("[ * ] Nó com valor %d removido.\n", data);
  }

  return root;
}

// TODO: Refazer as buscas usando só uma função, parametrizada ou deixar cada um com o seu dominio? Fica aí a duvida.
// Busca pre-ordem
void searchPreOrder(Node *root) {
  (printf("%d ", root -> data), searchPreOrder(root -> left), searchPreOrder(root -> right)); // TODO: Isso tá horrivel de ler, mas funciona. Isso que dá deixar pro ultimo dia.
}

// Busca ordem
void searchOrder(Node *root) {
  (searchOrder(root -> left), printf("%d ", root -> data), searchOrder(root -> right)); // TODO: Isso tá horrivel de ler, mas funciona. Isso que dá deixar pro ultimo dia.
}

// Busca  pós-ordem
void searchPostOrder(Node *root) {
  (searchPostOrder(root -> left), searchPostOrder(root -> right), printf("%d ", root -> data)); // TODO: Isso tá horrivel de ler, mas funciona. Isso que dá deixar pro ultimo dia.
}

int main()
{
  Node *root = NULL;
  int option, value;

  do {
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\nEscolha uma operacao:\n\n");

    printf("[ %d ] Inserir\n", INPUT_SELECTION_INSERT); // Op 1 - Incluir nó
    printf("[ %d ] Remover\n", INPUT_SELECTION_REMOVE); // Op 2 - Remover nó

    printf("[ %d ] [ Buscar ] pre-ordem\n", INPUT_SELECTION_SEARCH_PRE_ORDER);  // Op 3 - Buscar pré-ordem
    printf("[ %d ] [ Buscar ] em ordem\n", INPUT_SELECTION_SEARCH_ORDER); // Op 4 - Buscar em ordem
    printf("[ %d ] [ Buscar ] pos-ordem\n", INPUT_SELECTION_SEARCH_POST_ORDER); // Op 5 - Buscar pós-ordem

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
      // NOTE/TODO: Queria colcoar negrito em algumas coisas, mas tô no powershell e nao funciona direito. Vejo depois (eu acho).
      // ("TODO" adicionado pra eu pdoer achar no addon de todos)
      case INPUT_SELECTION_INSERT: // Op 1
        printf("\n[ + ] Adicionar\n");
        printf("[ + ] Digite o valor que quer adicionar: ");
        scanf("%d", &value);
        root = insert(root, value);
        break;

      case INPUT_SELECTION_REMOVE: // Op 2
        printf("\n[ - ] Apagar\n");
        printf("[ * ] Estes são os valores atuais: ");
        // display(root); TODO: Add busca e listagem pra melhorar o DX/UX
        searchOrder(root);
        printf("\n[ - ] Digite o valor que quer apagar: ");
        scanf("%d", &value);
        root = delete(root, value);
        break;

      case INPUT_SELECTION_SEARCH_PRE_ORDER: // Op 3
        printf("\n[ * ] Buscar PRE ORDEM \n");
        searchPreOrder(root);
        break;

      case INPUT_SELECTION_SEARCH_ORDER: // Op 4
        printf("\n[ * ] Buscar EM ORDEM \n");
        searchOrder(root);
        break;

      case INPUT_SELECTION_SEARCH_POST_ORDER: // Op 5
        printf("\n[ * ] Buscar POS ORDEM \n");
        searchPostOrder(root);
        break;

      case EXIT_INPUT_SELECTION: // Op 0
        printf("\n[ * ] Saindo...\n");
        break;

    default: // Op 6 - ∞ (hehehe)
      printf("\n[ ! ] Tente novamente.\n");
    }

  } while (option != EXIT_INPUT_SELECTION);

  return 0;
}

// TODO: Verificar porque o prettier nao tá corrigindo o arquivo no save.
