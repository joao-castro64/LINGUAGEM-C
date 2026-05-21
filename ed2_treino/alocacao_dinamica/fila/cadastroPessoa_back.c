
typedef struct TypePessoa{
	int id;
	char nome[100];
	int idade;
	struct TypePessoa* next;
	struct TypePessoa* ant;
}TypePessoa; 

typedef TypePessoa* Pessoa;

typedef struct TypeFila{
	Pessoa head;
	Pessoa tail;
	int size;
}TypeFila;

typedef TypeFila* Fila;

Fila new_fila(){
	
	Fila fila = malloc(sizeof(TypeFila));
	
	fila->head = NULL;
	fila->tail = NULL;
	fila->size = 0;
	
	return fila;
}

Pessoa cadastroPessoa(int id, char* nome, int idade){
	
	Pessoa p2 = malloc(sizeof(TypePessoa));
	
	p2->id = id;
	strcpy(p2->nome, nome);
	p2->idade = idade;
	p2->next = NULL;
	p2->ant = NULL;

	return p2;
}

void cadastroFila(Fila fila, int id, char* nome, int idade){
	
	Pessoa p1 = cadastroPessoa(id, nome, idade);
	
	if(fila->head == NULL){
		fila->head = p1;
		fila->tail = p1;
		fila->size++;
		return;
	}

	fila->tail->next = p1;
	p1->ant = fila->tail;
	fila->tail = p1;
	fila->size++;
}

void printCadastro(Pessoa p2){
	printf("ID: %d Nome: %s Idade: %d\n\n", p2->id, p2->nome, p2->idade);
}

void listarFila(Fila fila){
	
	Pessoa p1 = fila->head;
	if(p1 == NULL) return;
	
	while(p1 != NULL){
		printCadastro(p1);
		p1 = p1->next;
	}
	printf("ID-FILA : [%d]\n", fila->head->id);

}

void excluirPessoa(Fila fila,int id){
	if(fila->head == NULL)
		return;
	Pessoa p1 = fila->head;
	
	/*if(p1->next == NULL){
		free(fila);
		fila->size--;
		return;
	}*/
	
	if(p1->id == id){
		if(p1->next != NULL){
			p1->next->ant = NULL;
			fila->head = p1->next;
		}
		if(p1->next == NULL){
			fila->tail = NULL;
			fila->head = NULL;
		}
		free(p1);
		fila->size--;
		return;
	}
	
	while(p1->next != NULL){
	
		if(p1->next->id == id){
			Pessoa p2 = p1->next;
			p1->next = p2->next;
			if(p2 != fila->tail)
				p2->next->ant = p1;
			if(p2 == fila->tail){
				fila->tail = p2->ant;
			}
			free(p2);
			fila->size--;
			return;
		}
		p1 = p1->next;
	}
}
	
void editarPessoa(Fila fila, int id, char* nome, int idade){
	
	if(fila->head == NULL) return;
	
	Pessoa p1 = fila->head;
	if(p1->id == id){
		strcpy(p1->nome, nome);
		p1->idade = idade;
	}
	
	while(p1){
		
		if(p1->next->id == id){
			Pessoa p2 = p1->next;
			strcpy(p2->nome, nome);
			p2->idade = idade;
			return;
		}
		p1 = p1->next;
	}
			
}
	

void priorizarPessoa(Fila fila, int id){
	
	Pessoa p1 = fila->head;
	if(p1 == NULL || p1->id == id)
		return;
	
	int cont = 0;
	while(p1->next != NULL){
		if(p1->next->id == id){
			Pessoa p2 = p1->next;
			p1->next = p2->next;
			if(p2->next != NULL)
				p2->next->ant = p1;
			p2->next = fila->head;
			if(fila->tail == p2)
				fila->tail = p1;
			p2->ant = NULL;
			fila->head = p2;
			return;
		}
		p1 = p1->next;
		cont++;
	}
	printf("NÃO ENCONTRADO!!\n");
			
}
	
		
		
// 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
		
		
		
		









