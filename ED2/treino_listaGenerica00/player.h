typedef struct{
	
	char *nome;
	char *poder;
	int hp;
	
}__Player;
typedef __Player * Player;

void printPlayer(Object obj){
	
	Player p1 = obj->item;
	
	printf("««PLAYER»»\n");
	printf("Nome: %s \nPoder: %s \nHP: %d\n\n", p1->nome, p1->poder, p1->hp);
	
}

Object new_Player(char* nome, char* poder, int hp){
	
	Object obj = new(Object, PLAYER);
	Player p1 = malloc(sizeof(__Player));
	
	p1->nome = malloc(strlen(nome) + 1);
	p1->poder = malloc(strlen(poder) + 1);
	strcpy(p1->nome, nome);
	strcpy(p1->poder, poder);
	p1->hp = hp;
	
	obj->item = p1;
	obj->printObjeto = printPlayer;
	return obj;
	
}
