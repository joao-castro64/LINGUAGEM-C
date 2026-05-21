#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "CRUD_simples_com_fila_duplamente_encadeada-back.c" 


int interface(){
	printf("«««««««««««««««««««««««««««««««««\n");
	printf("[1] - Cadastrar\n");
	printf("[2] - Listar\n");
	printf("[3] - Modificar\n");
	printf("[4] - Deletar\n");
	printf("[0] - Sair\n");
	printf("»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»\n");
	
	int opc;
	scanf(" %d", &opc);
	return opc;
}

void cadastrar(Lista lista){
	
	printf("Digite o nome do Produto\n");
	char nome[100];
	scanf(" %[^\n]s", nome);
	printf("Digite o preço do produto\n");
	float preco;
	scanf(" %f", &preco);
	cadastrarProduto(lista, nome, preco);
	printf("Concluido!!\n");
}

void deletar(Lista lista){
	
	printf("Digite o id do produto a ser deletado:\n");
	int id;
	scanf(" %d", &id);
	
	freeProduto(lista, id);
	printf("Produto Deletado!!\n");
}

int main(){
	
	Lista lista = new_lista();
	
	while(1){
		
		switch(interface()){
			
			case 1: cadastrar(lista);
				break;
	
			case 2: listarProduto(lista);
				break;
	
			case 3:
				break;
	
			case 4: deletar(lista);
				break;
	
			case 0: return 0;
				break;
		}
	}
	
}
