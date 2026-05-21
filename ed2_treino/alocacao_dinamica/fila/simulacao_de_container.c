#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "simulacao_de_conteiner-back.c"


int interface(){
	printf("\n««««««««««««««««««MENU»»»»»»»»»»»»»»»»»\n\n");		
	printf("1 - Baixar Imagem\n");		
	printf("2 - Excluir Imagem\n");		
	printf("3 - Criar Conteiner\n");		
	printf("4 - Interromper Container\n");		
	printf("5 - Iniciar Container\n");		
	printf("6 - Excluir Container\n");		
	printf("7 - Listar Todas as imagens\n");		
	printf("8 - Listar Todos os Containers e status\n");		
	printf("0 - Encerrar\n");	
	printf("«««««««««««««««««««««»»»»»»»»»»»»»»»»»»\n\n");	
	
	int opc;
	scanf(" %d", &opc);
	
	return opc;		
}

void imagem(ListaImg lista){
	
	printf("De um nome a sua imagem:\n");
	char nome[100];
	scanf(" %[^\n]s", nome);
	baixarImagem(lista, nome);
}

void container(ListaImg listaImg){
	
	printf("Qual o ID da sua imagem: \n");
	int id;
	scanf(" %d", &id);
	Imagem img = procurarImagem(listaImg, id);
	if(img == NULL)
		return;	
	printf("De um nome ao seu Container: \n");
	char nome[100];
	scanf(" %[^\n]s", nome);
	printf("Qual o estatus do container: [1] - em_execução [0] - interrompido\n");
	int status;
	scanf(" %d", &status);
	
	makeContainer(img, nome, status);
}

void excluirImagem(ListaImg lista){
		printf("Digite o ID da imagem que Deseja Excluir:\n");
		int id;
		scanf(" %d", &id);
		
		Imagem img = procurarImagem(lista, id);
		if(img == NULL)
			return;
		
		freeImagem(lista, img);
}

void interromperContainer(ListaImg lista){
	
	printf("Digite o id do container a ser interrompido: \n");
	int id;
	scanf(" %d", &id);
	
	alterarStatus(lista, id, 1);
}

void executarContainer(ListaImg lista){
	
	printf("Digite o id do container a ser executado: \n");
	int id;
	scanf(" %d", &id);
	
	alterarStatus(lista, id, 0);
}

int main(){
	
	ListaImg listaImg = iniciarListaImagem();
	
	while(1){
		
		switch(interface()){
			
			case 1: imagem(listaImg);
				break;
				
			case 2: excluirImagem(listaImg);
				break;
				
			case 3: container(listaImg);
				break;
				
			case 4: interromperContainer(listaImg);
				break;
				
			case 5: executarContainer(listaImg);
				break;
				
			case 7: exibirImagens(listaImg);
				break;
				
			case 8: exibirConteiners(listaImg);
				break;
				
			case 88: exibirConteinersInterrompidos(listaImg);
				break;
				
			case 99: mostrarImagem(listaImg->head);
				break;
		}
	}
				



}

