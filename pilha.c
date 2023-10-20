#include <stdio.h>
#include <stdlib.h>

struct TipoNodo {
    int dado;
    struct TipoNodo *prox;
};

typedef struct TipoNodo TipoNodo;

struct Pilha {
    TipoNodo *topo;
    int contador;
};

typedef struct Pilha Pilha;

int menu();
void inicializarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
int vazia(Pilha *pilha);
int desempilhar(Pilha *pilha);
void quantidadeElementos(Pilha *pilha);
void exibirTopo(Pilha *pilha);
void mostrar(Pilha *pilha);

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao, codigo;
    
    do {
        
        opcao = menu();
        
        switch (opcao) {
            case 0:
                printf("\n>>Tchau!");
                return 0;
            case 1:
                printf("Codigo: ");
                scanf("%d", &codigo);
                empilhar(&pilha, codigo);
                printf(">>Empilhado com sucesso!\n");
                break;
            case 2:
                desempilhar(&pilha);
                break;
            case 3:
                quantidadeElementos(&pilha);
                break;
            case 4:
                exibirTopo(&pilha);
                break;
            case 5:
                mostrar(&pilha);
            default:
                printf(">>Opção inválida!\n");
        }
    } while(opcao != 0);
}

int menu() {
    
    int opcao;
    
    printf("\n******** M E N U ********\n");
    printf("[1] Adicionar\n");
    printf("[2] Remover\n");
    printf("[3] Quantidade de elementos\n");
    printf("[4] Topo da lista\n");
    printf("[5] Mostrar\n");
    printf("[0] Sair\n");
    printf("***************************\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    
    return opcao;

}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->contador = 0;
}

int vazia(Pilha *pilha) {
    return pilha -> topo == NULL;
}

void empilhar(Pilha *pilha, int valor) {
    TipoNodo *novoNo = (TipoNodo*)malloc(sizeof(TipoNodo));
    novoNo->dado = valor;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->contador++;
}

int desempilhar(Pilha *pilha) {
    if (vazia(pilha)) {
      return printf(">>Pilha vazia!\n");
    } else{

    TipoNodo *memoria = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(memoria);
    pilha->contador--;
     return printf(">>Desempilhado com sucesso!\n");
    }
}

void quantidadeElementos(Pilha *pilha) {
    printf(">>Quantidade de elementos na pilha: %d\n", pilha->contador);
}

void exibirTopo(Pilha *pilha) {
    if (vazia(pilha)) {
        printf(">>Pilha vazia!\n");
        return;
    }
    printf(" >>Topo da pilha: %d\n", pilha->topo->dado);
}

void mostrar(Pilha *pilha) {
    if (vazia(pilha)) {
        printf(">>Pilha vazia!\n");
        return;
    }
    TipoNodo *noAtual = pilha->topo;
    while (noAtual != NULL) {
        printf(">>Codigo: %d\n", noAtual->dado);
        noAtual = noAtual->prox;
    }
    printf("\n");
}