#include <stdio.h>
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

Principal vetorP[TAM];

void dobrar(int *x){
    *x = *x * 2;
}


/*
Objetivo: criar estrutura auxiliar na posi��o 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - j� tem estrutura na posi��o
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa�o de mem�ria
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){

    // se posi��o � um valor v�lido {entre 1 e 10}
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    	return POSICAO_INVALIDA;
	}else
	// a posicao pode j� existir estrutura auxiliar
		if(vetorP[posicao-1].aux == 1){
			return JA_TEM_ESTRUTURA_AUXILIAR;
	} else   // o tamanho nao pode ser menor que 1
    	if(tamanho < 1){
			return TAMANHO_INVALIDO;
		}else{
        	vetorP[posicao-1].vet = (int*)malloc(sizeof(int) *tamanho);
        	// o tamanho ser muito grande
			if(!vetorP[posicao-1].vet){
        		return SEM_ESPACO_DE_MEMORIA;
		}
    		// deu tudo certo, crie
		    vetorP[posicao-1].tamanho = tamanho;
		    vetorP[posicao-1].qtd = 0;
		    vetorP[posicao-1].aux = 1;
		    return SUCESSO;
		}
}

/*
Objetivo: inserir n�mero 'valor' em estrutura auxiliar da posi��o 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - n�o tem espa�o
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    	return POSICAO_INVALIDA;
    else{
        // testar se existe a estrutura auxiliar
        if (vetorP[posicao-1].aux == 1){
          if (vetorP[posicao-1].qtd < vetorP[posicao-1].tamanho){
              //insere
              vetorP[posicao-1].vet[vetorP[posicao-1].qtd] = valor;
              vetorP[posicao-1].qtd++;
              return SUCESSO;
          }else{
              return SEM_ESPACO;
          }
        }else{
          return SEM_ESTRUTURA_AUXILIAR;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Ap�s excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta � uma exclus�o l�gica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){

	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		return POSICAO_INVALIDA;
	if(vetorP[posicao-1].aux == 0)
		return SEM_ESTRUTURA_AUXILIAR;
	if(vetorP[posicao-1].qtd == 0)
		return ESTRUTURA_AUXILIAR_VAZIA;
	if(vetorP[posicao-1].qtd != 0)
		vetorP[posicao-1].qtd--;
		return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posi��o 'posicao'.
Caso seja excluido, os n�meros posteriores devem ser movidos para as posi��es anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta � uma exclus�o l�gica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posi��o 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    NUMERO_INEXISTENTE - N�mero n�o existe
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int i, j, aux=0;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		return POSICAO_INVALIDA;
	if(vetorP[posicao-1].aux == 0)
		return SEM_ESTRUTURA_AUXILIAR;
	if(vetorP[posicao-1].qtd == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}else {
		for(i=0; i < vetorP[posicao-1].qtd; i++){
			if(vetorP[posicao-1].vet[i] == valor){
				for(j = i; j < vetorP[posicao-1].qtd; j++){
					vetorP[posicao-1].vet[j] = vetorP[posicao-1].vet[j+1];
				}
				return SUCESSO;
			}
		}
  		vetorP[posicao-1].qtd--;
   		}
  	if(aux = NUMERO_INEXISTENTE){
  		return NUMERO_INEXISTENTE;
	}
}


/*
Objetivo: retorna os n�meros da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int i, aux, quantidade;

	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		return POSICAO_INVALIDA;

	if(vetorP[posicao-1].aux == 0)
		return SEM_ESTRUTURA_AUXILIAR;

	for(i=0; i<vetorP[posicao-1].qtd; i++)
		vetorAux[i] = vetorP[posicao-1].vet[i];
	
    return SUCESSO;
}

/*
Objetivo: retorna os n�meros ordenados da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

	int i, aux, quantidade;

	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		return POSICAO_INVALIDA;
	if(vetorP[posicao-1].aux == 0)
		return SEM_ESTRUTURA_AUXILIAR;
	for(i=0; i<vetorP[posicao-1].qtd; i++)
		vetorAux[i] = vetorP[posicao-1].vet[i];

	quantidade = vetorP[posicao-1].qtd;

	getDadosEstruturaAuxiliar(posicao, vetorAux);

	aux = VerificarVetores();
	if(aux == 0){
		return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	}
	else {
		for(i=0; i < quantidade; i++){
			vetorAux[i] = vetorP[posicao-1].vet[i];
		}
		return OrdenarVetores(posicao, vetorAux);
	}
}

/*
Objetivo: retorna os n�meros de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int i, j, aux = 0, x = 0, v;

    for(i=0; i < TAM; i++){
    	if(vetorP[i].aux == 0){
    		x++;
		}
	}
    v = VerificarVetores();
    if(v==0){
    	return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    if(x == TAM){
    	return SEM_ESTRUTURA_AUXILIAR;
	}
	} else {
		for(i=0; i < TAM; i++){
			for(j=0; i < vetorP[i].qtd; j++){
				vetorAux[aux] = vetorP[i].vet[j];
				aux++;
			}
		}
		return SUCESSO;
	}
   
}

/*
Objetivo: retorna os n�meros ordenados de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
	int v, quantidade = 0;

	v = VerificarVetores();
	getDadosDeTodasEstruturasAuxiliares(vetorAux);

	if(v == 0){
		return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	}else if(retorno == SUCESSO){
		quantidade = VerificarQuantidadeTotal();
		OrdenarTodosVetores(quantidade, vetorAux);
	}else{
		return SEM_ESTRUTURA_AUXILIAR;
	}
    
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posi��o 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho n�o pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na aloca��o do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		return POSICAO_INVALIDA;
	if(vetorP[posicao-1].aux == 0) {
		return SEM_ESTRUTURA_AUXILIAR;
	} else
		if(novoTamanho < -90){
			return NOVO_TAMANHO_INVALIDO;
		}else {
			novoTamanho = vetorP[posicao-1].tamanho + novoTamanho;
			vetorP[posicao-1].vet = (int*)realloc(vetorP[posicao-1].vet, novoTamanho *sizeof(int));
			vetorP[posicao-1].tamanho = novoTamanho;
			if(vetorP[posicao-1].qtd > novoTamanho){
				vetorP[posicao-1].qtd = novoTamanho;
			}
			return SUCESSO;
		}
		if(!vetorP[posicao-1].vet){
			return SEM_ESPACO_DE_MEMORIA;
		}

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posi��o 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posi��o inv�lida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um n�mero int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;

	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
		retorno = POSICAO_INVALIDA;

	if(vetorP[posicao-1].aux == 0)
		retorno = SEM_ESTRUTURA_AUXILIAR;

	if(vetorP[posicao-1].qtd == 0)
		retorno = ESTRUTURA_AUXILIAR_VAZIA;

    return vetorP[posicao-1].qtd;

}


/*
Objetivo: montar a lista encadeada com cabe�ote com todos os n�meros presentes em todas as estruturas.
Retorno (No*)
    NULL, caso n�o tenha nenhum n�mero nas listas
    No*, ponteiro para o in�cio da lista com cabe�ote
*/
No* montarListaEncadeadaComCabecote(){

	int total;
	int vetorAux[total];
	
	No *inicio = (No*)malloc(sizeof(No));
	inicio->prox = NULL;
			
	total = VerificarQuantidadeTotal();
	vetorAux[total];
	
	getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
	int i;
	for(i = 0; i < total; i++){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = vetorAux[i];
		novo->prox = NULL;
		inicio = novo;
	}
	if(total == 0){
		return NULL;
	}
	
    return inicio;

}

/*
Objetivo: retorna os n�meros da lista enceada com cabe�ote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
	int i=0;

	inicio = montarListaEncadeadaComCabecote();
	while(inicio != NULL){
		vetorAux[i] = inicio->conteudo;
		inicio = inicio->prox;
		i++;
	}
}

/*
Objetivo: Destruir a lista encadeada com cabe�ote a partir de in�cio.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No* inicio){
   if(inicio != NULL){
   		No *aux;
		while(inicio != NULL){
			aux = inicio;
			inicio = inicio->prox;
			free(aux);
		}
   	free(inicio);
   }
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/
void inicializar(){
	int i;

	for(i=0; i < TAM; i++){
		vetorP[i].vet = NULL;
		vetorP[i].tamanho = 0;
		vetorP[i].qtd = 0;
		vetorP[i].aux = 0;
	}
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espa�os de mem�ria das estruturas auxiliares.
*/

void finalizar(){
    int i=TAM;

    while(i > TAM){
    	free(vetorP[i].vet);
    	i--;
	}
}

// se posi��o � um valor v�lido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else 
		return SUCESSO;
}

int VerificarVetores(){
	int retorno, i, k =0;

	for(i=0; i < TAM; i++){
		if(vetorP[i].qtd > 1){
			k++;
		}
	}
	return k;
}

int VerificarQuantidadeTotal(){
	int i, quantidade = 0;

	for(i = 0; i < 10; i++){
		quantidade = quantidade + vetorP[i].qtd;
	}

}

int QtdPosicoesDaEstrutura(int posicao){
	int qtd;

	qtd = vetorP[posicao-1].qtd;

	return qtd;
}

int OrdenarVetores(int posicao, int vetorAux[]){
	int i, retorno, qtd, j, troca, menor;

	qtd = QtdPosicoesDaEstrutura(posicao);

	for(i=0; i < qtd-1; i++){
		menor = i;
		for(j=i+1; j<qtd; j++){
			if(vetorAux[j] < vetorAux[menor]){
				menor = j;
			}
		}
		if(menor != i){
			troca = vetorAux[i];
			vetorAux[i] = vetorAux[menor];
			vetorAux[menor] = troca;
		}
	}
	retorno = SUCESSO;

	return retorno;
}
void OrdenarTodosVetores(int qtdt, int vetorAux[]){
	int i, j, troca, menor;

	for(i=0; i < qtdt-1; i++){
		menor=i;
		for(j = i+1; j < qtdt; j++){
			if(vetorAux[j] < vetorAux[menor]){
				menor=j;
			}
		}
		if(menor != i){
			troca = vetorAux[i];
			vetorAux[i] = vetorAux[menor];
			vetorAux[menor] = troca;
		}
	}

}

