typedef struct TypeArquivo{
	
	char *nome;
	int hate;
	struct TypeArquivo* prox;
	struct TypeArquivo* ant;
	
}TypeArquivo;

typedef TypeArquivo* Arquivo;

typedef struct TypeFila{
	
	Arquivo head;
	Arquivo tail;
	
}TypeFila;

typedef TypeFila *Fila;

Fila new_fila(){
	
	Fila fila = malloc(sizeof(TypeFila));
	
	fila->head = NULL;
	fila->tail = NULL; 
	
	return fila;
}

Arquivo criarArquivo(Fila fila, char* nome){
	
	Arquivo arq2 = malloc(sizeof(TypeArquivo));
	
	arq2->nome = malloc(sizeof(nome));
	strcpy(arq2->nome, nome);
	arq2->hate = 0;
	
	return arq2;
}

void adicionar(Fila fila, char *nome){
	
	Arquivo arq = criarArquivo(fila, nome);
	
	if(fila->head == NULL){
		fila->head = arq;
		fila->tail = arq;
		return;
	}
	
	fila->tail->prox = arq;
	arq->ant = fila->tail;
	fila->tail = arq;
	
}

void print(Arquivo arq2){
	
	printf("%s(%d) -> ", arq2->nome, arq2->hate);
	
}

void exibirArquivos(Fila fila){
	
	printf("-> ");
	if(fila->head == NULL){
		printf("/\n");
		return;
	}
	
	Arquivo arq = fila->head;
	
	while(arq != NULL){
		
		print(arq);
		arq = arq->prox;
	}
	printf("/\n");
}

Arquivo procurarArquivo(Fila fila, char* nome){
	
	if(fila->head == NULL) return NULL;
	
	Arquivo arq = fila->head;
	
	if(!strcmp(arq->nome, nome))
		return arq;
	
	while(arq != NULL){
		if(!strcmp(arq->nome, nome))
			return arq;
		arq = arq->prox;
	}
	return NULL;
}

void alterarHate(Arquivo arq){
	
	arq->hate++;
	
}

void organizar(Fila fila){
	
	Arquivo arq = fila->tail;
	
	if(fila->head == NULL || fila->head->prox == NULL)
		return;
	
	if(arq->hate >= 1){
		if(arq->hate >= arq->ant->hate){
			Arquivo arq2 = arq->ant;
			
			arq2->prox = arq->prox;
			arq->prox = arq2;
			arq->ant = arq2->ant;
			fila->tail = arq2;
			if(arq2 == fila->head)
				fila->head = arq;
			return;
			
		}
	}
}


	
