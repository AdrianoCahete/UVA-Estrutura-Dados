// Também disponivel em https://github.com/AdrianoCahete/UVA-Estrutura-Dados :)

#include <stdio.h>

// Main
int main()
{
  int option;

  do
  {
    printf("\nEscolha uma operação:\n");

    printf("1. Inserir\n");
    printf("2. Consultar\n");
    printf("3. Alterar\n");
    printf("4. Remover\n");
    printf("5. Listar\n");

    printf("\n0. Sair\n");
    printf("Opcao: ");
    scanf("%d", &option);
  } while (option != 6);

  return 0;
}
