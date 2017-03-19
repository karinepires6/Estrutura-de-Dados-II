/* DISCIPLINA: ESTRUTURA DE DADOS II
ALUNA: KARINE PIRES DE ARAUJO */
#include <stdio.h>
#define MAX 100 //ESTE DEFINE REFLETE O TAMANHO DO VETOR, CASO QUEIRA PODERÁ SER ALTERADO PARA QUANTOS ELEMENTOS FOR DESEJADO
void Ler_Elementos(int *vet1, double *vet2);
void Pesquisa_Elemento(int valor, int *vet1, double *vet2);
int main()
{
    int valor;
    int *vet1;
    double *vet2;

    //ALOCA OS VETORES DE INTEIRO E DOUBLE NAS RESPECTIVAS VARIAVEIS
    vet1 = (int *) malloc(sizeof(int)*MAX);
    vet2 = (double *) malloc(sizeof(double)*MAX);

    //CHAMADA DA FUNCAO QUE LÊ OS ELEMENTOS DOS VETORES
    Ler_Elementos(vet1, vet2);

    printf("INFORME UM VALOR INTEIRO: ");
    scanf("%i", &valor);

    //CHAMADA DA FUNCAO QUE PESQUISA E MOSTRA O RESULTADO DO ELEMENTO INFORMADO PELO USUARIO
    Pesquisa_Elemento(valor, vet1, vet2);

    //LIBERA A ALOCACAO DA MEMORIA
    free(vet1);
    free(vet2);
    return 0;
}
//FUNCAO QUE LÊ OS ELEMENTOS DOS VETORES
void Ler_Elementos(int *vet1, double *vet2)
{
    int i;

    //LÊ OS ELEMENTOS DO VETOR DE INTEIROS
    for(i=0;i<MAX;i++){
        printf("\nDigite o ELEMENTO %i DO VETOR DE INTEIROS: ", i+1);
        scanf("%i", &vet1[i]);
    }

    //LÊ OS ELEMENTOS DO VETOR DE DOUBLE
    for(i=0;i<MAX;i++){
        printf("\nDigite o ELEMENTO %i DO VETOR DE PONTO FLYTUANTE: ", i+1);
        scanf("%lf", &vet2[i]);
    }
}
//FUNCAO QUE PESQUISA E MOSTRA O RESULTADO DO ELEMENTO INFORMADO PELO USUARIO
void Pesquisa_Elemento(int valor, int *vet1, double *vet2){
    int i;

    //PESQUISA NO VETOR 1 SE O ELEMENTO EXISTE, CASO EXISTA EXIBE A POSICAO E O VALOR CORRESPONDENTE NO VETOR 2
    for(i=0;i<MAX;i++){
        if(vet1[i] == valor){
            printf("\nVALOR ENCONTRADO NA POSICAO %i DO VETOR 1!\nVALOR CORRESPONDE NO VETOR 2 EH: %lf\n", i, vet2[i]);
            break;
        }
    }

    //CASO O VALOR NAO EXISTA NO VETOR 1, MOSTRA ESTA MENSAGEM
    if(i >= MAX){
        printf("\nO VALOR INFORMADO NAO EXISTE NO VETOR :(\n");
    }
}
