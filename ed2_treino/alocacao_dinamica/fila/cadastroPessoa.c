#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastroPessoa_back.c"

int interface(){
	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Excluir\n");
	printf("4 - Editar\n");
	printf("5 - Priorizar\n");
	printf("0 - Sair\n");
	int opc;
	scanf(" %d", &opc);
	return opc;
}

void cadastrar(Fila fila){
	int id = fila->size;
	printf("Digite o nome:\n");
	char nome[100];
	scanf(" %[^\n]s", nome);
	printf("Digite a idade:\n");
	int idade;
	scanf(" %d", &idade);
	cadastroFila(fila, id, nome, idade);
}

void escolher(Fila fila, char* txt){
	
	printf("Digite o id da pessoa a ser %s\n", txt);
	int id;
	scanf(" %d", &id);
	if(!strcmp(txt, "EXCLUÌDA"))
		excluirPessoa(fila, id);
	if(!strcmp(txt, "PRIORIZADA"))
		priorizarPessoa(fila, id);
	printf("Concluido!!!\n");
	
}

void editar(Fila fila){
	
	printf("Digite o id da pessoa a ser editada: \n");
	int id;
	scanf(" %d", &id);
	
	printf("Digite o novo nome: \n");
	char nome[100];
	scanf(" %[^\n]s", nome);
	
	printf("Digite a nova idade: \n");
	int idade;
	scanf(" %d", &idade);
	
	editarPessoa(fila, id, nome, idade);
	printf("Concluído!!!\n");
	setbuf(stdin, NULL);
	getchar();
}
	

int main(){
	Fila fila = new_fila();

	while(1){
		
		switch(interface()){
			
			case 1:cadastrar(fila);
				break;
			case 2:listarFila(fila);
				break;
			case 3:escolher(fila, "EXCLUÌDA");
				break;
			case 4:editar(fila);
				break;
			case 5:escolher(fila, "PRIORIZADA");
				break;
			case 0: return 0;
				break;
		}
	}
}

