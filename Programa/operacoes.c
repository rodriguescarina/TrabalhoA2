/* ============================ */
/* opera��es - arquivo operacoes.c */
/* ============================ */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/*------------------------------------------------*/
/*			Funcao - Inicializa o Vetor 		  */	
void inicializaVetor(Pib *p){
			// *p = ponteiro para dadosPib
    
    int i;
			
	//Abrindo arquivo txt para a leitura dos dados
	FILE *arqEnt;
	arqEnt = fopen("economia.txt", "r");
	
	//Nao existe o arquivo economia.txt, ou nao foi encontrado:
	if(arqEnt == NULL){
		printf("Nao foi possivel abrir o arquivo economia.txt \n");
		getchar();
		exit(0);
	}
			
	for(i=0; i<TAM; i++){
		
		//Lendo arquivos do txt
		
		fscanf(arqEnt,"%d %f",&p[i].ano, &p[i].indice);	//Atribuindo os dados do txt para variaveis aqui no programa
	}//fim for
} 
/*		Fim da Funcao - Inicializa o Vetor 	   */
/*---------------------------------------------*/



/*-------------------------------------------*/
/*		Funcao - imprime o Vetor de Struct 	*/		
void imprime(Pib *p){
	
	int i;

	//Exibindo os dados
	printf("-----------------------------------------------------\n");
	printf("\t\tDados sendo exibidos...\n");
	printf("------------------------------------------------------\n\n");
	printf("ANO:\t INDICE:\n\n");	
	
	for(i=0; i<TAM; i++){
		printf(" %d \t %.1f\n\n\n", p[i].ano, p[i].indice);
	}
}
/*		Fim da Funcao - imprime o Vetor de Struct		 */
/* ------------------------------------------------------*/



/*-----------------------------------------*/
/*		Funcao - Ordena com QuickSort	   */				
void ordena(Pib *vetor, int esquerda, int direita){
	
	int i, j;
	int pivo;
	Pib aux;
	
	i = esquerda;
	j = direita;
	
	//Se os dados j� est�o um pouco ordenados:
	//Eh melhor come�ar do meio.
	pivo = (esquerda + direita) / 2 ; //usando indice do meio como pivo
	
	while(i <= j){
		while(vetor[i].ano < vetor[pivo].ano && i < direita){
			i++;
		}
		
		while(vetor[j].ano > vetor[pivo].ano && j > esquerda){
			j--;
		}
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;	
			i++;
			j--;
		}
	}
	
	if (j > esquerda){
		ordena(vetor, esquerda, j);
	}
	
	if(i < direita){
		ordena(vetor, i, direita);
	}
}
/*		Fim da Funcao - Ordena com QuickSort		 */
/*---------------------------------------------------*/



/*-----------------------------------------*/
/*			Funcao - Busca Binaria	      */	
int buscaBinaria(Pib *dadosPib, int inicio, int fim, int busca) {
  
	int i, meio;
	
	meio = (int) (inicio+fim)/2;
	
	if(dadosPib[meio].ano == busca)
	return meio;
	
	if(inicio >= fim)
	return -1; //representa que n�o encontrou o ANO buscado na estrutura
	
	if(busca < dadosPib[meio].ano){	
		buscaBinaria(dadosPib, inicio, meio-1, busca);
	}
	else{
		buscaBinaria(dadosPib, meio+1, fim, busca);
	}
}
/*	    	Fim da Funcao - Busca Binaria  		 */
/*-----------------------------------------------*/



/*--------------------------------------*/
/*		Funcao - inicializa a LISTA 	*/	
void inicializaLista (Pib **lista) {

    *lista = NULL;

}
/*		Fim da Funcao - inicializa a LISTA		 */
/*-----------------------------------------------*/



/*---------------------------------------------------*/
/*		Funcao - verifica se a LISTA esta vazia 	*/	
int listaVazia (Pib *lista) {

    if (lista == NULL)
        return 1;

    return 0;

}
/*		Fim da Funcao - verifica se a LISTA esta vazia		 */
/*-----------------------------------------------------------*/



/*------------------------------------------------------*/
/*		Funcao - insere elemento no inicio da LISTA 	*/	
void insereInicio (Pib **lista, int ano) {
    
    Pib *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (Pib*) malloc (sizeof(Pib));
    novo->ano = ano;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaVazia(*lista))
        novo->proximo = NULL;

    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

}
/*		Fim da Funcao - insere elemento no inicio da LISTA		 */
/*---------------------------------------------------------------*/



/*----------------------------------*/
/*		Funcao - imprime a LISTA 	*/	
void imprimeLista(Pib *lista){  //*lista = inicio
	
	Pib *atual = lista; //ponteiro auxiliar para andar na lista
	
	if(listaVazia(lista)){ 
		printf("A lista esta vazia!\n");
		return;
	}
	
	printf("-----------------------------------------------------\n");
	printf("\t\tLISTA sendo exibida...\n");
	printf("------------------------------------------------------\n\n");
	printf("Lista: [ ");
	while(atual != NULL){
		printf("%d ", atual->ano);
		atual = atual->proximo;
	}	
	printf("]\n\n\n");
}
/*		Fim da Funcao - imprime a LISTA		 */
/*-------------------------------------------*/
