#include <stdio.h>
#include <stdlib.h>

struct sNODE {
    int dado;
    struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ini(int dado) {
    struct sNODE *aux = malloc(sizeof(struct sNODE));
    aux->dado = dado;
    aux->prox = ini;

    if (ini == NULL) {
        fim = aux; // Se a lista estiver vazia, o novo nó será tanto o início quanto o fim.
    }

    ini = aux; // Atualiza o início da lista para o novo nó.
}

void inserir(int dado) {
    struct sNODE *aux = malloc(sizeof(struct sNODE));
    aux->dado = dado;
    aux->prox = NULL;

    if (ini == NULL) {
        ini = aux;
        fim = aux;
    } else {
        fim->prox = aux;
        fim = aux;
    }
}

struct sNODE *buscar(int dado) {
    struct sNODE *aux = ini;
    while (aux != NULL) {
        if (aux->dado == dado) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void remover(int dado) {
    struct sNODE *aux = ini;
    struct sNODE *ant = NULL; 
    while (aux != NULL) {
        if (aux->dado == dado) {
            if (aux == ini) {
                ini = aux->prox;
            } else if (aux == fim) {
                fim = ant;
                fim->prox = NULL;
            } else {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;    
    }
}

void apagar() {
    struct sNODE *aux = ini;
    struct sNODE *ant = NULL;

    while (aux != NULL) {
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL;
}

void imprimir() {
    struct sNODE *aux = ini;

    printf("[");

    while(aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

    printf("]\n");
}

int main(int dado) {
    int opcao;
    printf("-----Seja Bem Vindo Usuario-----");

    while (opcao != 7) {
        printf("\nDigite sua opcao:");
        printf("\n1.Inserir Dados na Lista");
        printf("\n2.Inserir dados com prioridade");
        printf("\n3.Buscar dados pelo index");
        printf("\n4.Remover dados da lista");
        printf("\n5.Imprimir lista");
        printf("\n6.Apagar lista");
        printf("\n7.Sair\n");

        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o dado que deve ser adicionado:\n");
            scanf("%d", &dado);
            inserir(dado);
            printf("Dado adicionado com sucesso!\n");

          
        } else if (opcao == 2) {
            printf("Digite o dado que deve ser adicionado (o dado ira ser adicionado com prioridade):\n");
            scanf("%d", &dado);
            inserir_ini(dado);
            printf("Dado adicionado com sucesso!\n");

          
        } else if (opcao == 3) {
            printf("Digite o dado que você quer encontrar na lista:\n");
            scanf("%d", &dado);
            struct sNODE *res = buscar(dado);
            if (res != NULL) {
                printf("Dado encontrado: %d\n", res->dado);
            } else {
                printf("Dado não encontrado.\n");
            }

          
        } else if (opcao == 4) {
            printf("Digite o dado que voce quer remover:\n");
            scanf("%d", &dado);
            remover(dado);

          
        } else if (opcao == 5) {
            imprimir();

          
        } else if (opcao == 6) {
            int esc;
            printf("Esta opcao ira deletar todos os elementos da lista, deseja prosseguir ? \n");
            printf("1 para sim, 0 para cancelar operacao\n");
            scanf("%d", &esc);
            if (esc == 1) {
                apagar();
            } else {
                printf("voltando para o menu\n");
            }
        }
    }

    return 0;
}
