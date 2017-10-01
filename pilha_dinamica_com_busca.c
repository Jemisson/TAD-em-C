#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _no{
    int chave;
    char nome[51];
    struct _no *prox;
}No;

typedef struct _pilha{
    No *topo;
}Pilha;

void inicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha){
    if(pilha->topo == NULL){
        return 1;
    } else {
        return 0;
    }
}

void push(Pilha *pilha, No no){
    
    No *aux;
    
    if(pilhaVazia(pilha)){
        pilha->topo = malloc(sizeof(No));
        (*pilha->topo) = no;
        pilha->topo->prox = NULL;
    
    } else {
        
        aux = malloc(sizeof(No));
        *aux = no;
        aux->prox = pilha->topo;
        pilha->topo = aux;
    }
}

No pop(Pilha *pilha){
    
    No *aux, no;
    
    if(!pilhaVazia(pilha)){
        aux = pilha->topo;
        no.chave = aux->chave;
        strcpy(no.nome, aux->nome);
        pilha->topo = pilha->topo->prox;
        free(aux);
    } else {
        no.chave = -1;
    }
    
    return no;
}

void buscaPorNome(Pilha *pilha, char nome[51]){
    No *no = pilha->topo;
    int F = 0;
    
    while(no != NULL){
        if(strcmp(no->nome, nome) == 0){
            printf("Encontrado: %d %s\n", no->chave, no->nome);
            F = 1;
        }
        no = no->prox;
    }
    if(F == 0){
        printf("Não encontrado");
    }
}


void imprimePilha(Pilha *pilha){
    No *no = pilha->topo;
    
    while(no != NULL){
        printf("%d %s\n", no->chave, no->nome);
        no = no->prox;
    }
}

int main() {
   
   Pilha pilha;
   No no, item;
   int i, N;
   char nome[51];
   
   strcpy(nome, "palavra_para_busca");
   
   inicializaPilha(&pilha);
   
   scanf("%d", &N);
   
   //Empilhando
   for(i=0; i<N; i++){
       scanf("%d %s", &no.chave, no.nome);
       push(&pilha, no);
   }
   
   imprimePilha(&pilha);
   
   //Busca por String
   buscaPorNome(&pilha, nome);
    
   //Desempilhado
    while(!pilhaVazia(&pilha)){
        item = pop(&pilha);
        printf("\nDesempilhando %d %s\n", item.chave, item.nome);
    }

   return 0;
}

