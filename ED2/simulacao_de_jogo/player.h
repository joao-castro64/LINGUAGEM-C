typedef enum{
	ELFO,
	HUMANO,
	ORC,
	ANAO,
	HOBBIT
}Raca;

typedef struct __Player{
	char nome[100];
	int hp;
	Raca raca;
	int mana;
}__Player;
typedef __Player* Player;

Object new_Player(char* nome, int hp){
	Object obj = new(__Object);
	Player n = malloc(sizeof(__Player));
	obj->item = n;
	strcpy(n->nome,nome);
	n->hp = hp;
	return obj;
}

void print_player(List lst){
	
	Player p1 = lst->head;
	
	if(!p1) return;
	
	while(p1){
		print(p1);
		p1 = p1->prox;
	}
	
}

