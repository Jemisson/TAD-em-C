#include<stdio.h>
#include<stdlib.h>
#define ALOCA_TAM 10

//Lista dinamica sequencial sem pop()

typedef struct{
    int chave;
    char nome[50];
}TipoItem;

typedef struct{
    TipoItem *itens;
    int ultimo;
    int tamanho;
}ListaLinear;

int inicializaLista(ListaLinear *lista){
    lista->ultimo == 0;
    lista->tamanho == ALOCA_TAM;
    lista->itens = malloc(ALOCA_TAM*sizeof(TipoItem));
    if(lista->itens == NULL){
        return -1;
    }
    return 0;
}

void imprime(ListaLinear *lista){
    int i;
    for(i=0; i<lista->ultimo; i++){
        printf("%d %s\n", lista->itens[i].chave, lista->itens[i].nome);
    }
}

int push(ListaLinear *lista, TipoItem item){
    int i, pos = lista->ultimo;
    if(pos == lista->tamanho){
        TipoItem *aux = lista->itens;
        TipoItem *novaLista = malloc((lista->tamanho+ALOCA_TAM)*sizeof(TipoItem));
        
        if(novaLista == NULL) return -1;
        for(i=0; i<pos; i++){
            novaLista[i] = lista->itens[i];
        }
        lista->itens = novaLista;
        lista->tamanho += ALOCA_TAM;
        if(aux!=NULL){
            free(aux);
        }
    }
    lista->itens[pos] = item;
    lista->ultimo++;
    
    return 0;
}

int main() {
   
   int i, N;
   ListaLinear lista;
   TipoItem item;
   
   if(inicializaLista(&lista) < 0){
       printf("Nao foi possivel alocar memória");
       exit(1);
   }
   
   inicializaLista(&lista);
   scanf("%d", &N);
   for(i=0; i<N; i++){
       scanf("%d %s", &item.chave, item.nome);
       push(&lista, item);
   }
       
    imprime(&lista);
    
    return 0;
}

