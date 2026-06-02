#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum{
	ELFO,
	ANAO,
	HUMANO,
	ORC,
	HOBBIT,
	GIGANTE
}Raca;

typedef enum{
	GUERREIRO,
	MAGO,
	SACERDOTE,
	NECROMANTE,
	LADRAO
}Categoria;

typedef struct{
	char nome[100];
	int mana;
	Raca raca;
	int hp;
	Categoria tipo;
}Personagem;


int receberMana(Personagem p1){
	
	if(p1.tipo == 0)
		return 5000;
	if(p1.tipo == 1)
		return 20000;
	if(p1.tipo == 2)
		return 10000;
	if(p1.tipo == 3)
		return 15000;
	if(p1.tipo == 4)
		return 2000;
	return 0;
}

int receberHP(Personagem p1){
	
	if(p1.raca == 0)
		return 10000;
	if(p1.raca == 1)
		return 2000;
	if(p1.raca == 2)
		return 200;
	if(p1.raca == 3)
		return 1000;
	if(p1.raca == 4)
		return 700;
	if(p1.raca == 5)
		return 15000;
	return 0;

}

void raca(Personagem p1){
	if(p1.raca == 0)
		printf("ELFO");
	if(p1.raca == 1)
		printf("ANAO");
	if(p1.raca == 2)
		printf("HUMANO");
	if(p1.raca == 3)
		printf("ORC");
	if(p1.raca == 4)
		printf("HOBBIT");
	if(p1.raca == 5)
		printf("GIGANTE");
}

void tipo(Personagem p1){
	if(p1.tipo == 0)
		printf("GUERREIRO");
	if(p1.tipo == 1)
		printf("MAGO");
	if(p1.tipo == 2)
		printf("SACERDOTE");
	if(p1.tipo == 3)
		printf("NECROMANTE");
	if(p1.tipo == 4)
		printf("LADRAO");
}
	

int main(){
	
	Personagem player[5];
	srand(clock());
	for(int i = 0; i < 5; i++){
		strcpy(player[i].nome, "Link");
		player[i].raca = rand() % 6;
		player[i].tipo = rand() % 5;
	}
	printf("aqui\n");


	for(int i = 0; i < 5; i++){
		player[i].mana = receberMana(player[i]);
		player[i].hp = receberHP(player[i]);
	}
	
	for(int i = 0; i < 5; i++){
		printf("[PLAYER %d]\n", i);
		printf("Nome: %s\n",player[i].nome);
		printf("Raça: ");
		raca(player[i]);
		printf("\n");
		printf("Categoria: ");
		tipo(player[i]);
		printf("\n");
		printf("HP: %d\n", player[i].hp);
		printf("Mana: %d\n\n", player[i].mana);
	}
		
		
}
	
	
