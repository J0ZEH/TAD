#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float nota;
};

typedef struct no* Lista;

Lista* criar_lista();
int esvazia_lista(Lista* li);
int liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista(Lista *li, struct aluno al);
int remover_lista(Lista* li, int mat);
int busca_lista_nome(Lista* li, char* nome, struct aluno *al,int aux);
int busca_lista_mat(Lista* li, int mat, struct aluno *al);
int busca_lista_nota(Lista* li, float nota, struct aluno *al,int aux);
int listar_itens(Lista* li, struct aluno *al ,int aux);
