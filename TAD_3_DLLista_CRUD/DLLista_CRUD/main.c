//TAD3 - Estrutura de Dados I - Ciência da Computação
//por José Florêncio e Vinicius Cerveira

#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

Lista* minha_lista;

struct aluno al;

void deletar(Lista* minha_lista,struct aluno *al){
  int del=0;
  printf("\nNome: %s\nMatricula: %d\nNota: %.2f\n\n",(*al).nome,(*al).matricula,(*al).nota);
  printf("Digite 1 para deletar: ");
  scanf("%d",&del);
  if(del==1){
    printf("A matrícula %d será deletada.",(*al).matricula);
    remover_lista(minha_lista,(*al).matricula);
  }else
    printf("Procurando outros alunos");
}

int main()
{
    char nome[30];
    int op,opC,opR,mat;
    float nota;

    do{
    printf("1 - Criar Lista\n");
    printf("2 - Inserir elementos\n");
    printf("3 - Listar elementos\n");
    printf("4 - Consultar elementos\n");
    printf("5 - Remover um elemento\n");
    printf("6 - Esvaziar Lista\n");
    printf("7 - Destruir Lista\n");
    printf("0 - Encerrar Programa\n");
    scanf("%d", &op);

    switch (op){

        case 1:
            if(minha_lista==NULL){
                minha_lista=criar_lista();
                printf("Lista alocada");
            }else
                printf("Lista ja alocada");
            break;

        case 2:
            if (minha_lista == NULL){
                printf("Lista nao alocada\n");
                break;
            }

            while(getchar() != '\n');
            printf("Digite o nome do aluno: ");
            gets(al.nome);

            printf("Informe numero de matricula do aluno: ");
            scanf("%d", &al.matricula);

            printf("Insira a nota: ");
            scanf("%f",&al.nota);
            if(busca_lista_mat(minha_lista,al.matricula,&al)!=1)
              inserir_lista(minha_lista,al);
            else{
                printf("Matricula já existente");
              break;
            }

            printf("\nAluno: %s\nMatricula: %d\n Cadastro realizado", al.nome, al.matricula);
            break;

        case 3:
            if (minha_lista == NULL){
                printf("Lista nao alocada\n");
                break;
            }

            if (tamanho_lista(minha_lista) == 0){
                printf("Sem alunos para exibir");
                break;
            }
            for(int i=0;i<tamanho_lista(minha_lista);i++){
               if(listar_itens(minha_lista,&al,i))
               printf("Nome: %s\nMatricula: %d\nNota: %.2f\n\n",al.nome,al.matricula,al.nota);
            }
            break;

        case 4:
          if (minha_lista == NULL){
                printf("Lista nao alocada\n");
                break;
          }

          if (tamanho_lista(minha_lista) == 0){
                printf("Sem alunos para consultar");
                break;
          }

          if (minha_lista != NULL){
            if (tamanho_lista>0){
              printf("\nO que voce busca?\n");
              printf("1 - Pesquisar nome de aluno\n");
              printf("2 - Pesquisar matricula de aluno\n");
              printf("3 - Pesquisar nota de aluno\n");
              printf("Opcao: ");
              scanf("%d", &opC);

              switch(opC){

                case 1:
                    printf("\nDigite o nome do aluno: ");
                    fflush(stdin);
                    gets(nome);
                    for(int i=0;i<tamanho_lista(minha_lista);i++){
                      if(busca_lista_nome(minha_lista,&nome,&al,i))
                        printf("Nome: %s\nMatricula: %d\nNota: %.2f\n\n",al.nome,al.matricula,al.nota);
                    }
                break;

                case 2:
                  printf("\nDigite a matricula do aluno: ");
                  scanf("%d", &mat);
                  if(busca_lista_mat(minha_lista,mat,&al))
                    printf("Nome: %s\nMatricula: %d\nNota: %.2f\n\n",al.nome,al.matricula,al.nota);
                  break;

                case 3:
                  printf("\nDigite a nota do aluno: ");
                  scanf("%f", &nota);
                    for(int i=0;i<tamanho_lista(minha_lista);i++){
                      if(busca_lista_nota(minha_lista,nota,&al,i))
                        printf("Nome: %s\nMatricula: %d\nNota: %.2f\n\n",al.nome,al.matricula,al.nota);
                    }
                  break;
                }
             }
             break;
          }

        case 5:
          if (minha_lista == NULL){
                printf("Lista nao alocada\n");
                break;
          }

          if (tamanho_lista(minha_lista) == 0){
                printf("Sem alunos para consultar");
                break;
          }
          if (minha_lista != NULL){
            if (tamanho_lista(minha_lista)> 0){
              printf("\nO que voce busca?\n");
              printf("1 - Pesquisar nome de aluno\n");
              printf("2 - Pesquisar matricula de aluno\n");
              printf("3 - Pesquisar nota de aluno\n");
              printf("Opcao: ");
              scanf("%d", &opR);

              switch(opR){

                case 1:
                  printf("\nDigite o nome do aluno: ");
                  fflush(stdin);
                  gets(nome);
                  for(int i=0;i<tamanho_lista(minha_lista);i++){
                    if(busca_lista_nome(minha_lista,nome,&al,i)==1){
                        deletar(minha_lista,&al);
                    }
                  }
                break;

                case 2:
                  printf("\nDigite a matricula do aluno: ");
                  scanf("%d", &mat);
                  if(busca_lista_mat(minha_lista,mat,&al)==1)
                    deletar(minha_lista,&al);
                break;

                case 3:
                  printf("\nDigite a nota do aluno: ");
                  scanf("%f", &nota);
                  for(int i=0;i<tamanho_lista(minha_lista);i++){
                    if(busca_lista_nota(minha_lista,nota,&al,i)==1){
                        deletar(minha_lista,&al);
                      }
                    break;
                  }
                break;
              }
              break;
            }
            break;
          }
        case 6:
            if (minha_lista == NULL){
                printf("Lista nao alocada");
                break;
            }else{
                esvazia_lista(minha_lista);
                printf("Quantidade de itens: %d", tamanho_lista(minha_lista));
            }
        break;

        case 7:
            if (minha_lista == NULL){
                printf("Lista nao alocada");
                break;
            }
            if (liberar_lista(minha_lista)){
                printf("Lista Destruida");
                break;
            }
            else{
                printf("Primeiro esvazie a lista");
                break;
            }

        default:
          printf("Programa encerrado!");

        }
        printf("\nPressione ENTER para continuar\n");
        while (getchar() != '\n');
        getchar();
        system("CLS||clear");
    }
    while(op!=0);
}
