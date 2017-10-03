#include<stdio.h>
#include<stdlib.h>

typedef struct _No{
    int chave;
    struct _No *prox;
}No;

typedef struct _fila{
    No *inicio;
    No *fim;
}Fila;

void push(Fila *fila, No no){
    
    No *aux;
    
    if(fila->inicio == NULL){
        fila->inicio = malloc(sizeof(No));
        *fila->inicio = no;
        fila->inicio->prox = fila->fim;
        fila->fim = fila->inicio;
    } else {
        aux = malloc(sizeof(No));
        *aux = no;
        aux->prox = NULL;
        fila->fim->prox = aux;
        fila->fim = aux;
        
    }
}

int pop(Fila *fila){
    No *aux = fila->inicio;
    
    if(aux != NULL){
        fila->inicio = fila->inicio->prox;
        free(aux);
        return 1;
    }
    return 0;
}

void print(Fila *fila){
    
    No *aux;
    aux = fila->inicio;
    
    while(aux != NULL){
        printf("%d\n", aux->chave);
        aux = aux->prox;
    }
}

int main() {
    
    Fila fila;
    No no;
    int i, N;
    
    fila.inicio = NULL;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d", &no.chave);
        push(&fila, no);
    }

    print(&fila);
    
    if(!pop(&fila)){
        printf("Nao foi possivel remover\n\n");
    }
    printf("\n\n");
    print(&fila);
}

