#include <stdio.h>
#define N 5

struct TipoNodo
{
    int codigo;
    char nome[10];
};

typedef struct TipoNodo TipoNodo;

int menu();
int adicionar(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int remover(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL);
int mostrarPrimeiro (TipoNodo LL[], int *IL);
int mostrarUltimo (TipoNodo LL[], int *FL);
int quantidadeElementos(int *IL, int *FL);

int main()
{
    TipoNodo LL[N], infoNodo;
    int opcao, IA = 0, FA = N - 1, IL = -1, FL = -1; 
    int quantidade = 0;
    int i=0;
    
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\n>> Adicionar <<\n");
            printf("\nCódigo...: ");
            scanf("%d", &infoNodo.codigo);
            printf("\nNome.....: ");
            scanf("%s", infoNodo.nome);
            if (adicionar(LL, IA, FA, &IL, &FL, infoNodo))
                printf(">>> Lista cheia, não foi possível adicionar!\n");
            else
                printf(">>> Adicionado com sucesso!\n");
            break;
        case 2:
            if(remover(LL, IA, FA, &IL, &FL, infoNodo))
                printf(">>> A lista não possui elementos para exclusão!\n");
            else 
                printf(">>> Removido com sucesso!\n");
            break;
        case 3:
            printf("\n>>>>>> Quantidade <<<<<\n");
            printf("Quantidade de elementos: %d\n", quantidadeElementos(&IL, &FL)); 
            break;
        case 4:
            printf("\n>>>>>> Primeiro Elemento <<<<<\n");
            mostrarPrimeiro(LL, &IL);
            break;
        case 5:
            printf("\n>>>>>> Ultimo Elemento <<<<<\n");
            mostrarUltimo(LL, &FL);
            break;
        case 6:
            printf("\n>>>>>> Mostrar Lista <<<<<\n");
            mostrar(LL, IA, FA, IL, FL);
            break;
        case 0:
            printf(">>>>>> Tchau! <<<<<<\n");
            break;
        default:
            printf(">>>>>> Opção inválida! <<<<<\n");
            break;
        }
    } while (opcao != 0);
}
int menu()
{
    int opcao;
    printf("\n******** M E N U ********\n");
    printf("[1] Adicionar\n");
    printf("[2] Remover\n");
    printf("[3] Quantidade de elementos\n");
    printf("[4] Primeiro da lista\n");
    printf("[5] Ultimo da lista\n");
    printf("[6] Mostrar\n");
    printf("[0] Sair\n");
    printf("***************************\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}
int adicionar(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    if (IA == *IL && FA == *FL)
        return 1;
    else
    {
        if (*IL == -1)
            *IL = *FL = IA;
        else if (*FL < FA)
            *FL = *FL + 1;
        else
        {
            for (int i = *IL; i >= *FL; i++)
                LL[i - 1] = LL[i];
            *IL = *IL - 1;
        }
        LL[*FL] = infoNodo;
        return 0;
    }
}
int remover(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    
    if(*IL == -1)
        return 1;
    else {
    TipoNodo vazio;
    LL[*IL] = vazio;
    
    for (int i = *IL; i <= *FL; i++)
        LL[i] = LL[i + 1];
    *FL = *FL - 1;
    return 0;
    mostrar(LL, IA, FA, IL, FL);
    }
    
}
int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL)
{
    for (int i = IA; i <= FA; i++)
    {
        if (i >= IL && i <= FL)
            printf("%4d - %s\n", LL[i].codigo, LL[i].nome);
        else
            printf("--- ----\n");
    }
    return 0;
}

int quantidadeElementos(int *IL, int *FL){
    int quantidade;
    return quantidade = (*FL - *IL) + 1;
}

int mostrarPrimeiro (TipoNodo LL[], int *IL){
    int i;
    i = *IL;
    return printf("Primeiro elemento: %4d - %s\n ", LL[i].codigo, LL[i].nome);
}

int mostrarUltimo (TipoNodo LL[], int *FL){
    int i;
    i = *FL;
    return printf(" Ultimo elemento: %4d - %s\n ", LL[i].codigo, LL[i].nome);
}