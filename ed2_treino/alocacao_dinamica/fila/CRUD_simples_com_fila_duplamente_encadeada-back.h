typedef struct TypeProduto{
	
	int id;
	char* nome;
	float preco;
	struct TypeProduto* prox;
	struct TypeProduto* ant;
	
}TypeProduto;

typedef TypeProduto* Produto;

typedef struct TypeLista{
	
	Produto head;
	Produto tail;
	int size;
	
}TypeLista;

typedef TypeLista* Lista;


Lista new_lista(){
	
	Lista lista = malloc(sizeof(TypeLista));
	
	lista->head = NULL;
	lista->tail = NULL;
	lista->size = 0;
	
	return lista;
}

Produto integrar(Lista lista, char* nome, float preco){
	
	Produto p2 = malloc(sizeof(TypeProduto));
	
	p2->nome = malloc(sizeof(nome));
	strcpy(p2->nome, nome);
	p2->preco = preco;
	p2->id = lista->size;
	p2->prox = NULL;
	p2->ant = NULL;
	
	return p2;
	
}

void cadastrarProduto(Lista lista, char* nome, float preco){
	
	Produto p1 = integrar(lista, nome, preco);
	
	if(lista->head == NULL){
		lista->head = p1;
		lista->tail = p1;
		lista->size++;
		return;
	}
	
	lista->tail->prox = p1;
	p1->ant = lista->tail;
	lista->tail = p1;
	lista->size++;
	
}

void print(Produto p2){
	printf("ID %d Nome: %s Preço: %.2f\n", p2->id, p2->nome, p2->preco);
}

void listarProduto(Lista lista){
	
	Produto p1 = lista->head;
	if(lista->head == NULL){
		printf("Sem produtos aqui^^\n");
		return;
	}
	
	while(p1 != NULL){
		print(p1);
		p1 = p1->prox;
	}
}

void freeProduto(Lista lista, int id){
	
	Produto p1 = lista->head;
	
	if(lista->head == NULL)
		return;
		
	if(p1->ant == NULL && p1->prox == NULL){
		lista->head = NULL;
		lista->tail = NULL;
		free(p1);
		return;
	}
	
	if(p1->id == id){
		lista->head = p1->prox;
		free(p1);
		return;
	}
	
	while(p1 != NULL){
		if(p1->id == id){
			p1->ant->prox = p1->prox;
			if(p1->prox != NULL)
				p1->prox->ant = p1->ant;
			if(p1->prox == NULL)
				lista->tail = p1->ant;
			free(p1);
			return;
		}
		p1 = p1->prox;
	}
	
}









	
