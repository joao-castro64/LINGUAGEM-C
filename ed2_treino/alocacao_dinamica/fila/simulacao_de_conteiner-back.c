typedef struct TypeConteiner{
	int id;
	char *nome;
	int status;
	struct TypeConteiner *prox;
	struct TypeConteiner *ant;
}TypeConteiner;

typedef TypeConteiner* Conteiner;


typedef struct TypeImagem{
	int id;
	char *nome;
	Conteiner cHead;
	Conteiner cTail;
	struct TypeImagem* prox;
	struct TypeImagem* ant;
	int size;
}TypeImagem;

typedef TypeImagem* Imagem;

typedef struct TypeListaImagem{
	Imagem head;
	Imagem tail;
	int size;
}TypeListaImagem;

typedef TypeListaImagem* ListaImg; 

ListaImg iniciarListaImagem(){
	
	ListaImg lista = malloc(sizeof(TypeListaImagem));
	
	lista->head = NULL;
	lista->tail = NULL;
	lista->size = 0;
	
	return lista;
}


Imagem criarImagem(ListaImg lista, char* nome){
	
	Imagem img2 = malloc(sizeof(TypeImagem));
	
	img2->id = lista->size;
	img2->nome = malloc(sizeof(nome + 1));
	strcpy(img2->nome, nome);
	img2->cHead = NULL;
	img2->cTail = NULL;
	img2->prox = NULL;
	img2->ant = NULL;
	img2->size = 0;

	return img2;
}

void baixarImagem(ListaImg lista, char* nome){
	
	Imagem img1 = criarImagem(lista, nome);
	
	if(lista->head == NULL){
		lista->head = img1;
		lista->tail = img1;
		lista->size++;
	}else{
		lista->tail->prox = img1;
		img1->ant = lista->tail;
		lista->tail = img1;
		lista->size++;
	}
	
}

void printImagem(Imagem img){
	
	printf("Id: %d Nome: %s\n", img->id, img->nome);

}

void exibirImagens(ListaImg lista){
	
	Imagem img = lista->head;
	if(img == NULL)
		return;
	
	while(img != NULL){
		
		printImagem(img);
		img = img->prox;
		
	}
}

Conteiner criarConteiner(Imagem img, char *nome, int status){
	
	Conteiner ctn = malloc(sizeof(TypeConteiner));
	
	ctn->id = img->size;
	ctn->nome = malloc(sizeof(nome));
	strcpy(ctn->nome, nome);
	ctn->status = status;
	ctn->prox = NULL;
	ctn->ant = NULL;
	
	return ctn;
}

void makeContainer(Imagem img, char *nome, int status){
	
	Conteiner conteiner = criarConteiner(img, nome, status);
	
	if(img->cHead == NULL){
		img->cHead = conteiner;
		img->cTail = conteiner;
		img->size++;
		return;
	}
	
	img->cTail->prox = conteiner;
	conteiner->ant = img->cTail;
	img->cTail = conteiner;
	img->size++;

	
}

void printConteiner(Imagem img, Conteiner ctn){
	
	printf("IMG: %s ID: %d Nome: %s Status: ", img->nome, ctn->id, ctn->nome);
	if(ctn->status)
		printf("Em Execução\n");
	if(!ctn->status)
		printf("Interrompido\n");
}

void exibirConteiners(ListaImg lista){
	
	Imagem img = lista->head;
	Conteiner ctn = NULL;
	if(img == NULL)
		return;
	
	while(img != NULL){
		ctn = img->cHead;
		while(ctn != NULL){
			printConteiner(img, ctn);
			ctn = ctn->prox;
		}
		img = img->prox;
	}
}

void exibirConteinersInterrompidos(ListaImg lista){
	
	Imagem img = lista->head;
	Conteiner ctn = NULL;
	if(img == NULL)
		return;
	
	while(img != NULL){
		ctn = img->cHead;
		while(ctn != NULL){
			if(!ctn->status)
				printConteiner(img, ctn);
			ctn = ctn->prox;
		}
		img = img->prox;
	}
}

Imagem procurarImagem(ListaImg lista, int id){
	
	Imagem img = lista->head;
	if(img == NULL)
		return NULL;
	
	if(img->id == id)
		return img;
		
	while(img != NULL){
		if(img->id == id){
			return img;
		}
		img = img->prox;
	}
	return NULL;
}

void freeImagem(ListaImg lista, Imagem img){
	
	if(img->cHead != NULL){
		printf("Existe Container ligado a essa imagem\n");
		return;
	}
	
	if(img == NULL)
		return;
	
	if(img->prox == NULL && img->ant == NULL){
		lista->head = NULL;
		lista->tail = NULL;
		free(img);
		return;
	}
	
	if(lista->head == img){
		lista->head = img->prox;
		free(img);
		return;
	}
	
	img->ant->prox = img->prox;
	if(img->prox != NULL)
		img->prox->ant = img->ant;
	if(img->prox == NULL)
		lista->tail = img->ant;
	free(img);
	
}
		
void mostrarImagem(Imagem img){
	
	printf("IMG = ID: %d Nome: %s\n", img->id, img->nome);
	printf("CTN = ID: %d Nome: %s\n", img->cHead->id, img->cHead->nome);
	printf("CTN = ID: %d Nome: %s\n", img->cTail->id, img->cTail->nome);
	

}

void alterarStatus(ListaImg lista, int id, int md){
	
	Imagem img = lista->head;
	Conteiner ctn = NULL;
	if(img == NULL)
		return;
	
	while(img != NULL){
		ctn = img->cHead;
		while(ctn != NULL){
			if(ctn->id == id && ctn->status == md)
				ctn->status = !(ctn->status);
			ctn = ctn->prox;
		}
		img = img->prox;
	}
}



















