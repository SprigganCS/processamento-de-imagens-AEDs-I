#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void imprime_matriz(int *mat, int lin, int col){
	for(int i=0; i<lin*col; i++){
		if(i%5==0 && i!=0){
			printf("\n");
		}
		printf("%d ", mat[i]);
	}
}

int reduz(char *comentario, int *mat, int lin, int col, int escala){ //se precisar vizinhos 4: aux = mat[i]+mat[i-1]+mat[i+1]+mat[i-col]+mat[i+col];//vizinhos 4
	int aux;
    //definir tamanho do salto
    int salto, j=0, i=0;
	salto = col/100;
	int newLine = lin/salto;
    int mat_saida[newLine*100];
	while(i<lin*col){
		mat_saida[j]=mat[i];
		i+=salto, j++;
	}

	//gerar_arquivo(&comentario[0], &mat_saida[0], lin, col, escala);
	return 0;
}

void gerar_arquivo(char *comentario, int *mat, int lin, int col, int escala){
    FILE *arq_saida;
    arq_saida = fopen("saida.pgm", "w");
    fputs("P2\n", arq_saida);
    fputs(comentario, arq_saida);
    fputs("\n", arq_saida);
    fprintf(arq_saida, "%d %d\n%d\n", col, lin, escala);
    for(int i=0; i<lin*col; i++){
        fprintf(arq_saida, "%d ", mat[i]);
    }
}


void gerar_menor(char *comentario, int *mat, int lin, int col, int escala){
    FILE *arq_saida;
    arq_saida = fopen("saida.pgm", "w");
    fputs("P2\n", arq_saida);
    fputs(comentario, arq_saida);
    fputs("\n", arq_saida);

	int jump = col/100;
    fprintf(arq_saida, "%d %d\n%d\n", col/jump, lin/jump, escala);

	int linsaida = lin/jump;
	int colsaida = col/jump;

	int imout[linsaida*colsaida];

	

    for(int i=0; i<linsaida; i++){
		for(int j=0; j<colsaida; j++){
			imout[i * colsaida + j] = mat[i*col*jump+j*jump];
			printf("%d ", i*jump+j*jump);
		}
	}

	for(int i = 0; i<linsaida*colsaida; i++){
		fprintf(arq_saida, "%d ", imout[i]);
	}
}


int main() 
{
	FILE *arq;
	int col, lin, escala;
	int aux;
	char tipo[3], comentario[100];
	
	//Leitura e armazenamento do arquivo inicial
	arq = fopen("imagem.pgm", "r");
	if (arq == NULL) 
	{
		printf("Falha ao abrir o arquivo");
		exit(1);
	}


    fgets(tipo, 3, arq);
    fscanf(arq, "%s", comentario);
    //printf("%s\n", tipo);
    //printf("%s\n", comentario);


	fscanf(arq, "%d", &col);
	fscanf(arq, "%d", &lin);
	fscanf(arq, "%d", &escala);
    //printf("%d %d %d", col, lin, escala);
	int mat[lin*col]; // alocar dinamicamente a memória depois
	
	for(int i=0; i<lin*col; i++)
	{
			fscanf(arq, "%d", &aux);
			mat[i]=aux;
	}
    fclose(arq);




	//imprime_matriz(&mat[0], lin, col);
	//reduz(&comentario[0], &mat[0], lin, col, escala);
    //gerar_arquivo(&comentario[0],&mat[0], lin, col, escala);
	gerar_menor(&comentario[0],&mat[0], lin, col, escala);
}
