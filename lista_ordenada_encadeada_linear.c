#include<stdio.h>
#include<stdlib.h>


typedef struct _No{
    int id, esq, dir;
    struct _No *prox;
}No;

typedef struct _lista{
    No *inicio, *fim;
}Lista;


void inicializa(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

int ehVazia(Lista *lista){
    if(lista->inicio == NULL)
        return 1;
    return 0;
}

void print(Lista *lista){
    No *aux = lista->inicio;
    
    while(aux){
        printf("%d: dir: %d, esq: %d\n", aux->id, aux->esq, aux->dir);
        aux = aux->prox;
    }
}

void push(Lista *lista, No no){
    
    No *aux, *auxp, *auxs;
    
    if(ehVazia(lista)){
        lista->inicio = malloc(sizeof(No));
        *lista->inicio = no;
        lista->inicio->prox = NULL;
        lista->fim = lista->inicio;
        printf("inicio %d - fim %d\n", lista->inicio->id, lista->fim->id);
    } else {
        
        aux = malloc(sizeof(No));
        *aux = no;
        
        if(aux->id < lista->inicio->id){ // antes do inicio
            aux->prox = lista->inicio;
            lista->inicio = aux;
            printf("inicio %d - fim %d\n", lista->inicio->id, lista->fim->id);
        } else {
            
            if(aux->id > lista->fim->id){ // depois do final
                aux->prox = NULL;
                lista->fim->prox = aux;
                lista->fim = aux;
                printf("inicio %d - fim %d\n", lista->inicio->id, lista->fim->id);
            } else {
                
                auxs = lista->inicio->prox;
                auxp = lista->inicio;
                while(auxs != NULL){
                    if(auxs->id > aux->id){
                        aux->prox = auxs;
                        auxp->prox = aux;
                    }
                    auxp = auxs;
                    auxs = auxs->prox;
                }
                
            }
        }
    }
}

int main() {
   
   int i, qtd;
   Lista lista;
   No no;
   
   inicializa(&lista);
   
   scanf("%d", &qtd);
   
   for(i=0; i<qtd; i++){
       scanf("%d %d %d", &no.id, &no.esq, &no.dir);
       push(&lista, no);
       
   }
   
   print(&lista);
   
   
   return 0;
}

