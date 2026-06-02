typedef struct __Player{
	
	char nome[100];
	int hp;
	int level;
	int xp;
	
}__Player;
typedef __Player *Player;

Player new_Player(char *nome){
	
	Player p1 = malloc(sizeof(__Player));
	
	strcpy(p1->nome, nome);
	p1->hp = 200;
	p1->level = 1;
	p1->xp = 0;
	
	return p1;
}

void exibirPlayer(Player p1){
	printf("Nome: %s \nLevel: %d \nHP: %d \nXP: %d\n\n", 
		p1->nome, p1->level, p1->hp, p1->xp);
}

