#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct no{
    struct no *ant;
    struct aluno dados;
    struct no *prox;
};

typedef struct no No;

Lista* criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

int esvazia_lista(Lista* li){

    if (li != NULL){
        No *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
    }
    else
        return 0;
    return 1;
}

int liberar_lista(Lista* li){
    if(!lista_vazia(li)){
        return 0;
    }
    else{
        free(li);
        return 1;
    }
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return 0;
    int cont = 0;
    No* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if( li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

int inserir_lista(Lista* li, struct aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if(lista_vazia(li)){
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        *li = novo_no;
        return 1;
    }else{
        No *anterior, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            novo_no->ant = NULL;
            (*li)->ant = novo_no;
            novo_no->prox = (*li);
            *li = novo_no;
        }else{
            novo_no->prox = anterior->prox;
            novo_no->ant = anterior;
            anterior->prox = novo_no;
            if (atual != NULL)
                atual->ant = novo_no;
        }
        return 1;
    }
}

int remover_lista(Lista* li, int mat){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *no = *li;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;

    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    return 1;
}

int busca_lista_nome(Lista* li, char* nome, struct aluno *al,int aux){
    int j=0;
    if(li == NULL){
        return 0;
    }
    No *no= *li;
    while(j!=aux){
        no= no->prox;
        j++;
    }
    if(strcmp(no->dados.nome,nome)==0){
        *al=no->dados;
        return 1;
    }
    return 0;
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al){
    if (li == NULL)
        return 0;
    No *no = *li;
    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int busca_lista_nota(Lista* li, float nota, struct aluno *al,int aux){
    int j=0;
    if(li == NULL){
        return 0;
    }
    No *no= *li;
    while(j!=aux){
        no= no->prox;
        j++;
    }
    if(no->dados.nota==nota){
        *al=no->dados;
        return 1;
    }
    return 0;
}

int listar_itens(Lista* li, struct aluno *al ,int aux){
    int j=0;
    if(li == NULL){
        return 0;
    }
    No *no= *li;
    while(no->prox!=NULL&&j<aux){
        no= no->prox;
        j++;
    }
    if (no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    };

}
