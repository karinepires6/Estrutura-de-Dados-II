/* DISCIPLINA: ESTRUTURA DE DADOS II
ALUNA: KARINE PIRES DE ARAUJO */
#include <stdio.h>
#include <string.h>
int main(){
    char url[]="arquivo.txt";
    char str[100];
    char info[100];
    char b[100] = "";
    FILE *arq;
    int op;

    //ABRE PARA LEITURA E ESCRITA DO ARQUIVO, ESCREVE OS DADOS NO FINAL DO ARQUIVO SE O MESMO EXISTIR
    arq = fopen(url, "a+");

    if(arq == NULL)
        printf("\nImpossivel abrir o arquivo\n");

    //MOSTRA AS OPCOES PARA O USUARIO E O PROGRAMA EXECUTA ATÉ QUE A OPÇÃO DE SAIDA SEJA INFORMADA
    printf("\n---Opcoes---\n");
    printf("1 - Escrever informacoes no arquivo\n2 - Pesquisar no arquivo\n3 - Sair do programa\nInforme A OPCAO DESEJADA: ");
    scanf("%i", &op);
    do {
        //PERMITE QUE O USUARIO UMA STRING E A MESMA É SALVA SEMPRE NO FINAL DO ARQUIVO
        if(op == 1){
            printf("\n\nInforme uma string de ate 100 caracteres para gravar no arquivo: ");
            fflush(stdin);
            gets(str);
            arq = fopen(url, "a+");
            fprintf(arq, "%s\n", str);
            fclose(arq);
        }
        //PERMITE QUE O USUARIO INFORME UMA STRING E A MESMA É PROCURADA NO ARQUIVO
        else if(op == 2){
            strcpy(b, "");
            printf("\n\nInforme uma string para buscar no arquivo: ");
            fflush(stdin);
            gets(info);

            //"REABRE" O ARQUIVO TODA VEZ QUE O USUARIO QUEIRA PROCURAR ALGUMA INFORMAÇÃO COM A OPÇÃO 2
            arq = fopen(url, "r");

            while((fscanf(arq, "%s\n", b)) != EOF ){
                if(strcmp(b, info) == 0){
                    printf("A string '%s' foi encontrada no arquivo.\n", b);
                    break;
                }
            }
            fclose(arq);
        }
        else if(op == 3){
            printf("\nSaindo do programa...\n");
            return 0;
        }
        printf("\n---Opcoes---\n");
        printf("1 - Escrever informacoes no arquivo\n2 - Pesquisar no arquivo\n3 - Sair do programa\nInforme A OPCAO DESEJADA: ");
        fflush(stdin);
        scanf("%i", &op);
    } while(op != 3);

    fclose(arq);
    return 0;
}
