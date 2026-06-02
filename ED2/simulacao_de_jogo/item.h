typedef struct{
	char nome[100];
	int power;
}__Item;
typedef __Item* Item;

Object new_Item(char* nome, int power){
	Object obj = malloc(sizeof(__Object));
	Item n = malloc(sizeof(__Item));
	obj->item = n;
	strcpy(n->nome,nome);
	n->power = power;
	return obj;
}

