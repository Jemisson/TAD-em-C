#include<stdio.h>
#include<stdlib.h>

typedef struct _TipoItem{
    int chave;
    struct _TipoItem *prox;
}TipoItem;

typedef struct _Lista{
    TipoItem *ultimo;
    int tamanho;
}Lista;

void inicializaLista(Lista *lista){
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void print(Lista *lista){
    TipoItem *aux = lista->ultimo;
    if(aux != NULL){
        do{
            aux=aux->prox;
            printf("%d\n", aux->chave);
        }while(aux != lista->ultimo);
    }
}

void pushEnd(Lista *lista, TipoItem item){
    TipoItem *novoNo;
    
    novoNo = malloc(sizeof(TipoItem));
    *novoNo = item;
    
    if(lista->ultimo == NULL){
        novoNo->prox = novoNo;
        lista->ultimo = novoNo;
    } else {
        novoNo->prox = lista->ultimo->prox;
        lista->ultimo->prox = novoNo;
        lista->ultimo = novoNo;
    }
    lista->tamanho++;
}

int pop(Lista *lista, int item){
    TipoItem *aux, *auxp;
    
    aux = lista->ultimo->prox;
    auxp = NULL;
    
    do{
        auxp = aux;
        aux = aux->prox;
    }while((aux != lista->ultimo->prox) && (aux->chave != item));
    
    if(aux->chave == item){
        if(aux == lista->ultimo){
            auxp->prox = lista->ultimo->prox;
            lista->ultimo = auxp;
            free(aux);
            return 1;
        } else {
            auxp->prox = aux->prox;
            free(aux);
            return 1;
        }
    } else {
        return -1;
    }
    
}

int main() {

    Lista lista;
    TipoItem item;
    int i, N;
    
    // Inicia uma lista vazia
    inicializaLista(&lista);

    // Lê a quantidade de itens para inserir
    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d", &item.chave);
        pushEnd(&lista, item);
    }

    // Exibe a lista
    print(&lista);
    
    //verifica se a solicitação de remocao foi atendida
    if(pop(&lista, 3)){
        printf("\n\nO numero solicitado foi removido\n\n");
    } else {
        printf("\n\nNumero nao encontrado\n\n");
    }
    
    print(&lista);
    return 0;
}

