#include<stdio.h>
#include<stdlib.h>

typedef struct _No{
    int chave;
    struct _No *ant, *prox;
}No;

typedef struct _Lista{
    No *inicio, *fim;
}Lista;

int push(Lista *lista, No no){
    No *aux, *auxp;
    
    if(lista->inicio == NULL){ // Inserindo no inicio da lista
        lista->inicio = malloc(sizeof(No));
        *lista->inicio = no;
        lista->inicio->ant = lista->inicio;
        lista->inicio->prox = lista->inicio;
        lista->fim = lista->inicio;
        return 1;
    
    } else {
        
        // Inserindo antes do inicio da lista
        if(no.chave < lista->inicio->chave){
            aux = malloc(sizeof(No));
            *aux = no;
            aux->ant = lista->fim;
            aux->prox = lista->inicio;
            lista->inicio->ant = aux;
            lista->fim->prox = aux;
            lista->inicio = aux;
            return 1;
            
        } else {
            
            //Inserindo depois do final da lista
            if(no.chave > lista->fim->chave){
                aux = malloc(sizeof(No));
                *aux = no;
                aux->ant = lista->fim;
                aux->prox = lista->inicio;
                lista->fim->prox = aux;
                lista->fim = aux;
                lista->fim->ant = aux;
                return 1;
            
            } else {
                
                    // Busca para localizar onde serao inseridos os proximos valores.                
                    auxp = lista->inicio->prox;

                    do{ 
                        // Inserindo no meio da lista
                        if(no.chave < auxp->chave){
                            aux = (No *) malloc(sizeof(No));
                            *aux = no;
                            aux->ant = auxp->ant;
                            aux->prox = auxp;
                            auxp->ant->prox = aux;
                            auxp->ant = aux;
                            return 1;
                        }
                                    
                        auxp = auxp->prox;    
                    }while(auxp != lista->fim);
            }
        }
    }
    return 0;
}


int pop(Lista *lista, int val){
    
    No *aux, *auxp;
    
    // Removendo no inicio
    if(val == lista->inicio->chave){
        
        aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->prox->ant = lista->fim;
        lista->inicio->ant->prox = lista->inicio->prox;
        
        free(aux);
        return 1;
    
    } else {
        
        // Removendo no final
        if(val == lista->fim->chave){
            
            aux = lista->fim;
            lista->fim->ant = lista->fim;
            lista->fim->prox->ant = lista->fim;
            lista->fim->ant->prox = lista->fim;
            
            
            free(aux);
            return 1;
            
            
        } else {
            
            // Removendo no meio da lista
            auxp = lista->inicio->prox;
            while(auxp != lista->fim->prox){
                
                if(val == auxp->chave){
                    
                    aux = auxp;
                    auxp->ant->prox = auxp->prox;
                    auxp->prox->ant = auxp->ant;
                    
                    free(aux);
                    return 1;
                }
                
                auxp = auxp->prox;
            }

        }
    }

    return 0;
}


void print(Lista *lista){
    No *aux = lista->inicio;
    
    if(lista->inicio != NULL){
        do{
            printf("%d\n", aux->chave);
            aux = aux->prox;
        }while(aux != lista->fim->prox);
    }
    
}


int main() {
    
    Lista lista;
    No no;
    int i, N;
    
    lista.inicio = NULL;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d",&no.chave);
        push(&lista, no);
    }
    
    print(&lista);
    
    if(!pop(&lista, 5)){
        printf("\n\nNumero nao encontrado\n\n");
    }
    return 0;
}

