/** Tarefa desenvolvida pelo grupo :
Guilherme Yamamoto Kato
João Pedro Padoan
Caio Brito
Walison Pitombeira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
  char RRN[4];
  char nome[26];
  char rua[26];
  char cidade[21];
  char UF[3];

}cadastro;

int tamStr(char *s)
{
    int i=0;
    while(s[i]!='\0')
         i++;
    return i;
}

int cortaEspaco(char *s)
{
    int casa;
     int j,i;
     j=tamStr(s);
     for(i=j-1;i>=0;i--){
       if(s[i]!=' ') break;

     }
    s[i+1]='\0';
    casa = i;
    return casa+1;
}

int main(){
  FILE *arq;
  arq = fopen("cadastro.txt", "r");
  if(arq == NULL){
    printf("Erro ao abrir arq\n");
    exit(1);
  }
  FILE *arq2;
  arq2 = fopen("cad_delimitador.txt", "w");
  if(arq2 == NULL){
    printf("Erro ao abrir arq2\n");
    exit(1);
  }
  FILE *arq3;
  arq3 = fopen("cad_ind_tamanho.txt", "w");
  if(arq3 == NULL){
    printf("Erro ao abrir arq2\n");
    exit(1);
  }

  cadastro a;
  char ch;
  int v[3];
  while(ch!=EOF){

    if(fgets(a.RRN, sizeof(a.RRN), arq)!=NULL){
        printf( "RRN:   %s\n", a.RRN );
        fgets(a.nome, sizeof(a.nome), arq);
        //printf( "Nome:  %s\n", a.nome );
        fgets(a.rua, sizeof(a.rua), arq);
        //printf( "Rua:  %s\n", a.rua );
        fgets(a.cidade, sizeof(a.cidade), arq);
        //printf( "cidade: %s\n", a.cidade );
        fgets(a.UF, sizeof(a.UF), arq);
        //printf( "UF: %s\n", a.UF );
        printf( "\n" );
        ch=fgetc(arq);

        v[0]=cortaEspaco(a.nome);
        v[1]=cortaEspaco(a.rua);
        v[2]=cortaEspaco(a.cidade);
        fprintf(arq2,"%s|%s|%s|%s|%s|\n",a.RRN,a.nome,a.rua,a.cidade,a.UF);
        fprintf(arq3,"03%s%02d%s%02d%s%02d%s02%s\n",a.RRN,v[0],a.nome,v[1],a.rua,v[2],a.cidade,a.UF);

    }else{
        break;
    }
  }


  if(fclose(arq) == 0){
      printf("arq fechado com sucesso\n");
  } else {
    printf("Erro ao fechar arq\n");
    exit(1);
  }
  if(fclose(arq2) == 0){
      printf("arq2 fechado com sucesso\n");
  } else {
    printf("Erro ao fechar arq2\n");
    exit(1);
  }
  if(fclose(arq3) == 0){
      printf("arq3 fechado com sucesso\n");
  } else {
    printf("Erro ao fechar arq3\n");
    exit(1);
  }
  return 0;
}
