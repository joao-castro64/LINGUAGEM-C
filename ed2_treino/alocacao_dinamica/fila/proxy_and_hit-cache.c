#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proxy_and_hit-cache-Back.c"

int interface(){
	printf("«««««««««««««««««««««««««\n");
	printf("[1] - Buscar Arquivo\n");
	printf("[0] - Exit\n");
	printf("»»»»»»»»»»»»»»»»»»»»»»»»»\n");
	int opc;
	scanf(" %d", &opc);
	return opc;
}

void buscar(Fila fila){
		printf("Digite o nome do Arquivo a ser Buscado: \n");
		char nome[100];
		scanf(" %[^\n]s", nome);
		
		printf("Arquivo Buscado: %s\n", nome);
		
		Arquivo arq = procurarArquivo(fila, nome);
		
		if(arq == NULL){
			printf("Chache Miss!\n");
			adicionar(fila, nome);
		}
			
		if(arq != NULL){
			printf("Cache Hit!\n");
			alterarHate(arq);
		}
		
		organizar(fila);
		
		exibirArquivos(fila);
		
}

int main(){
	
	Fila fila = new_fila();
	
	while(1){
		
		switch(interface()){
			
			case 1: buscar(fila);
				break;
			
			case 2: return 0;
		}
	}
	
}
