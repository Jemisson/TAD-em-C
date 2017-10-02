#include<stdio.h>
#include<string.h>
#define MAX 1000

//implementçcao de fila linear serquencial com impressão da fila e busca por string;

typedef struct _no{
    int chave;
    char nome[50];
}No;

typedef struct _fila{
    No itens[MAX];
    int ultimo;
}fila;

void inicializafila(fila *fila){
    fila->ultimo = 0;
}

int filaCheia(fila *fila){
    if(fila->ultimo == MAX){
        return 1;
    }
    return 0;
}

int filaVazia(fila *fila){
    if(fila->ultimo == 0){
        return 1;
    }
    return 0;
}

void imprimefila(fila *fila){
    int i=0;
    
    for(i=0; i<fila->ultimo; i++){
        printf("%d %s\n", fila->itens[i].chave, fila->itens[i].nome);
    }
}

int buscaNome(fila *fila, char nome[50]){
    int i;
    
    for(i=0; i<fila->ultimo; i++){
        if(strcmp(fila->itens[i].nome, nome) == 0){
            return fila->itens[i].chave;
        }
    }
    return -1;
}

int push(fila *fila, No no){
    int pos = fila->ultimo;
    
    if(!filaCheia(fila)){
        fila->itens[pos] = no;
        fila->ultimo++;
    } else {
        return 0;
    }
    return 1;
}

int pop(fila *fila){
    int i;
    if(!filaVazia(fila)){ //usar função para verificação. (y)
        for(i=0; i<fila->ultimo; i++){
            fila->itens[i] = fila->itens[i+1];
        }
        fila->ultimo--;
    } else {
        return 0;
    }
    return 1;
}

int main() {

   int i, qtd;
   char nome[50];
   fila fila;
   No no;

   strcpy(nome, "palavra_teste");
   inicializafila(&fila);
   
   scanf("%d", &qtd);
   
   for(i=0; i<qtd; i++){
       scanf("%d %s", &no.chave, no.nome);
       if(!push(&fila, no)){
           printf("\nNao foi possivel inserir\n");
       }
   }

    imprimefila(&fila);
    
    if(!pop(&fila)){
       printf("impossivel remover.");
    }
    
    imprimefila(&fila);
     
    printf("\n\nvalor encontrado: %d", buscaNome(&fila, nome));

   return 0;
}

