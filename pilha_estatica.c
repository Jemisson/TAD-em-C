#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

//Implementacao de pilha estática com busca por string.

typedef struct _TipoItem{
    int chave;
    char nome[51];
}TipoItem;

typedef struct _TipoPilha{
    TipoItem itens[MAX];
    int tam;
    int topo;
}TipoPilha;


void inicializarPilha(TipoPilha *pilha){
    pilha->topo = -1;
    pilha->tam = MAX;
}

int pilhaVazia(TipoPilha *pilha){
    if(pilha->topo == -1){
        return 1;
    } else {
        return 0;
    }
}

int pilhaCheia(TipoPilha *pilha){
    if(pilha->topo == pilha->tam-1){
        return 1;
    } else {
        return 0;
    }
}


TipoItem pop(TipoPilha *pilha){
    
    TipoItem item;
    
    item.chave = -1;
    strcpy(item.nome, "Vazio");
    
    if(!pilhaVazia(pilha)){
        
        item.chave = pilha->itens[pilha->topo].chave;
        strcpy(item.nome, pilha->itens[pilha->topo].nome);
        //pilha->itens[pilha->topo] =  NULL;
        pilha->topo--;
        return item;
    }
    
    return item;
}



int push(TipoPilha *pilha, TipoItem item){
    
    if(!pilhaCheia(pilha)){
        
        pilha->topo++;
        pilha->itens[pilha->topo] = item;
        
        return 1;
    }
    
    return 0;
}


TipoItem buscaPorNome(TipoPilha *aux, char nome[51]){
    
    TipoItem item;
    
    item.chave = -1;
    strcpy(item.nome, "nao encontrado");
    
    while(!pilhaVazia(aux)){
        
        item = pop(aux);
        
        if(strcmp(item.nome, nome) == 0){
            return item;
        }
    }
    
    
    return item;
}



int main() {
   
   TipoPilha pilha, aux;
   TipoItem item, busca;
   int i, N;
   char nome[51];
   
   //busca por um nome qualquer
   strcpy(nome, "palavra_teste");
   
   //inicializando a piha estática
   inicializarPilha(&pilha);
   
   //obtendo a quantidade de itens para inserir
   scanf("%d", &N);
   
   //inserindo itens na pilha
   for(i=0; i<N; i++){
       scanf("%d %s", &item.chave, item.nome);
       
       if(!push(&pilha, item)){
           break;
       }
   }
   
   aux = pilha;
   //buscando por nome informado anteriormente
   busca = buscaPorNome(&aux, nome);
   printf("\n%d %s\n\n", busca.chave, busca.nome);
   
   
   //desempilhando
   while(!pilhaVazia(&pilha)){
       item = pop(&pilha);
       printf("Desempilhado %d, %s\n", item.chave, item.nome);
   }
   
   return 0;
}

