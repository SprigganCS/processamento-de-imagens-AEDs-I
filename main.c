#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Processamento de imagens
* Disciplina: AEDs I
* Professor.: Paulo Bressan
* Aluno.....: Andre Neves Medeiros
* Data......: 23/10/2020
-------------------------------------------------------------*/
//escurecer
int brilho_menos(int it, int escala, int n)
{
	it=it-n;
	if (it<0) //condicional para evitar que os valores sejam menores que 0
	{
		it=0;
	}
	else
	{
	}
	return it;
}
//clarear
int brilho_mais(int it, int escala, int n)
{
	it=it+n;
	if (it>escala) //condicional para evitar que os valores sejam maiores que o parametro do arquivo(escala)
	{
		it=escala;
	}
	else
	{
	}
	return it;
}

//Binarizar
int binar(int it, int escala, int fat_binar) 
{
	if (it<fat_binar)
	{
		it=0;
	}
	else
	{
		it=escala;
	}
	return it;
}

//Escurecer bordas
int bordas(int it, int aux, int cont, int escala)
{
	it=it-aux+cont;
	if(it<=0)
	{
		it=0;
	}
	if(it>escala)
	{
		it=escala;
	}
	//printf("%d ", it);
	return it;
}

//Gerar Icone
int icone (int it, int cima, int baixo, int direita, int esquerda, int diag1, int diag2, int diag3, int diag4)
{
	int i;
	i=(it+cima+baixo+direita+esquerda+diag1+diag2+diag3+diag4)/9;
	it=i;
	return it;
}


//Filtro Passa Baixo
int ruido (int it, int cima, int baixo, int  esquerda, int direita, int diag1, int diag2, int diag3, int diag4)
{
	it = ((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	cima=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	baixo=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	direita=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	esquerda=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	diag1=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	diag2=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	diag3=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	diag4=((it*4) + (cima*2) + (baixo*2) + (esquerda*2) + (direita*2) + (diag1) + (diag2) + (diag3) + (diag4))/16;
	return it, cima, baixo, esquerda, direita, diag1, diag2, diag3, diag4;
}



int main() 
{
	FILE *arq;
	FILE *arq_saida;
	int col, lin, escala;
	int i, j, n, a, cont, aux, auxc, auxl, b, x, k, opcao_selecionada, claro_escuro, gradiente_bordas;
	int cima, baixo, direita, esquerda, diag1, diag2, diag3, diag4;
	char tipo[2], comentario[100];
//	char altura[4], largura[4], profundidade[3];
	
	//Leitura e armazenamento do arquivo inicial
	arq = fopen("imagem.pgm", "r");
	if (arq == NULL) 
	{
		printf("Falha ao abrir o arquivo");
		exit(1);
	}
	fscanf(arq, "%s", &tipo);
	fscanf(arq, "%s", &comentario);
	fscanf(arq, "%d", &col);
	fscanf(arq, "%d", &lin);
	fscanf(arq, "%d", &escala);
	int mat[lin][col];
	
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			fscanf(arq, "%d", &aux);
			mat[i][j]=aux;;
		}
	}
    fclose(arq);
   
	
	//interação com o usuário
	printf("Menu de opcoes:\n1 - Escurecer ou clarear\n2 - Binarizar\n3 - Gerar icone\n4 - Escurecer bordas\n5 - Eliminar ruido (filtro Passa Baixa)\n6 - Sair\n");
	scanf("%d", &opcao_selecionada);
	switch (opcao_selecionada) 
	{
		int it=0;
		case 1:
			printf("Digite 1 para clarear ou 2 para escurecer\n");
			scanf("%d", &claro_escuro);
			if(claro_escuro != 1){
				if(claro_escuro != 2){
						printf("Valor digitado inválido, digite um novo valor: ");
						scanf("%d", &claro_escuro);
				}
			}
			printf("Digite o parametro desejado:");
			scanf("%d", &n);
			if (claro_escuro == 1)
			{
				for(i=0; i<lin; i++)
				{
					for(j=0; j<col; j++)
					{
						it=mat[i][j];	
						mat[i][j]=brilho_mais(it, escala, n);
					}
				}
				break; 
			}
			else if(claro_escuro == 2)
			{
				for(i=0; i<lin; i++)
				{
					for(j=0; j<col; j++)
					{
						it=mat[i][j];	
						mat[i][j]=brilho_menos(it, escala, n);
					}
				}
				break; 
			}
			else
			{
				printf("Valor digitado invalido");
			}
			break; 
		case 2:
			printf("Selecionado: Binarizar\n");
			int fat_binar;
			printf("Digite um fator de binarizacao entre 0 e %d (Dica: procure usar valores medios): ", escala);
			scanf("%d", &fat_binar);
			for(i=0; i<lin; i++)
				{
					for(j=0; j<col; j++)
					{
						it=mat[i][j];	
						mat[i][j]=binar(it, escala, fat_binar);
					}
				} 
			break;
		case 3:
			printf("Selecionado: Gerar icone\n");
			aux=0;
			auxl=lin/64;
			auxc=col/64;
			i=0;
			j=0;
			k=1;
			while((auxl*k)<(auxl*k)+1)
			{
				x=1;
				j=0;
				while((auxc*x)<(auxc*x)+1)
				{
					int a;
					a=1;
					while(a<(auxl/2)+1)
					{
						int b;
						b=1;
						while(b<(auxc/2)+1)
						{
							it=mat[auxl*k][auxc*x];
							
							cima=mat[auxl*k-a][auxc*x];
							baixo=mat[auxl*k+a][auxc*x];
							direita=mat[auxl*k][auxc*x+b];
							esquerda=mat[auxl*k][auxc*x-b];
							diag1=mat[auxl*k-a][auxc*x-b];
							diag2=mat[auxl*k-a][auxc*x+b];
							diag3=mat[auxl*k+a][auxc*x-b];
							diag4=mat[auxl*k+a][auxc*x+b];
							
							it=icone(it, cima, baixo, direita, esquerda, diag1, diag2, diag3, diag4);
							
							mat[auxl*k][auxc*x]=it;
					
							mat[auxl*k-a][auxc*x]=it;
							mat[auxl*k+a][auxc*x]=it;
							mat[auxl*k][auxc*x+b]=it;
							mat[auxl*k][auxc*x-b]=it;
							mat[auxl*k-a][auxc*x-b]=it;
							mat[auxl*k-a][auxc*x+b]=it;
							mat[auxl*k+a][auxc*x-b]=it;
							mat[auxl*k+a][auxc*x+b]=it;
							cont++;
							b++;
						}
						a++;	
					}
					x++;
					if(x>66)
					{
					break;
					}
					j++;
					if(j>64){
						j=64;
					}
				}
				k++;
				if(k>66){
					break;
				}		
				i++;
				if(i>64){
					i=64;
				}	
			}
			int o; //reorganizacao
			int p;
			o=0;
			p=0;
			k=1;
			while((auxl*k)<(auxl*k)+1)
			{ 
				x=1;
				p=0;
				while((auxc*x)<(auxc*x)+1)
				{
					mat[o][p]=mat[auxl*k][auxc*x];
					x++;
					
					if(x>66)
					{
					break;
					}
					
					p++;
					
					if(p>64){
						p=64;
					}
				}
				o++;
				k++;
				if(k>66){
					break;
				}	
				if(o>64){
					o=64;
				}
			}
			break;
		case 4:
			n=0;
			it=0;
			printf("Selecionado: Escurecer Bordas\n");
			printf("Digite um fator de escurecimento entre 1 e 1: (:D)\n");
			scanf("%d", &n);
			aux=col/5;
			//borda esquerda
			for(i=0; i<lin; i++) 
			{
				cont=0;
				for(j=0; j<aux; j++)
				{
					it = mat[i][j];
					mat[i][j] = bordas(it, aux, cont, escala);
					cont++;
				}	
			}
			//borda direita
			for(i=0; i<lin; i++) 
			{
				cont=0;
				for(j=col-1; j>col-aux+1; j--)
				{
					it = mat[i][j];
					mat[i][j] = bordas(it, aux, cont, escala);
					cont++;
				}
			}
			
			//borda inferior
			for(j=0; j<col; j++)
			{
				cont=0;
				for(i=lin-1; i>lin-aux; i--)
				{
					it = mat[i][j];
					mat[i][j] = bordas(it, aux, cont, escala);
					cont++;
				}
			}	

			//borda superior
			for(j=0; j<col; j++)
			{
				cont=0;
				for(i=0; i<aux; i++)
				{
					it = mat[i][j];
					mat[i][j] = bordas(it, aux, cont, escala);
					cont++;
				}
			}
			break;
		case 5:
			printf("Selecionado: Eliminar Ruido");
			int cima, baixo, direita, esquerda, diag1, diag2, diag3, diag4;
			for(i=2; i<lin-2; i++)
			{
				for(j=2; j<col-2; j++)
				{
					it=mat[i][j];
					cima=mat[i-1][j];
					baixo=mat[i+1][j];
					direita=mat[i][j+1];
					esquerda=mat[i][j-1];
					diag1=mat[i-1][j-1];
					diag2=mat[i-1][j+1];
					diag3=mat[i+1][j-1];
					diag4=mat[i+1][j+1];
					
					mat[i][j]=ruido(it, cima, baixo, direita, esquerda, diag1, diag2, diag3, diag4);
					mat[i-1][j]=cima;
					mat[i+1][j]=baixo;
					mat[i][j+1]=direita;
					mat[i][j-1]=esquerda;
					mat[i-1][j-1]=diag1;
					mat[i-1][j+1]=diag2;
					mat[i+1][j-1]=diag3;
					mat[i+1][j+1]=diag4;
				}
			}
			break;
		case 6:
			printf("PRESSIONE ENTER PARA SAIR");
			exit (0);
			break;
		default:
			printf("Valor de entrada invalido");
			break;	
	}
	
	
	//ESCRITA DO NOVO ARQUIVO
	if(opcao_selecionada!=3)
	{
		arq_saida = fopen("saida.pgm", "w");
	fprintf(arq_saida, "P2\n#_Criado_por:_André_Neves_Medeiros\n%d %d\n%d\n", col, lin, escala);
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			fprintf(arq_saida, "%d ", mat[i][j]);
		}
		fprintf(arq_saida, "\n");
	}
    fclose(arq);
	
	fclose(arq_saida);
	printf("\nArquivo gravado com sucesso!");
	}
	else
	{
		arq_saida = fopen("saida.pgm", "w");
	fprintf(arq_saida, "P2\n#_Criado_por:_André_Neves_Medeiros\n64 64\n255\n");
	for(i=0; i<64; i++)
	{
		for(j=0; j<64; j++)
		{
			fprintf(arq_saida, "%d ", mat[i][j]);
		}
		fprintf(arq_saida, "\n");
	}
    fclose(arq);
	
	fclose(arq_saida);
	printf("\nGravado com sucesso!");
	}
	}
	
	


