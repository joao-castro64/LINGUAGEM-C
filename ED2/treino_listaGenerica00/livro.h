typedef struct{
	
	char *titulo;
	char* autor;
	int pag;

}__Livro;
typedef __Livro* Livro;

void print_Livro(Object obj){
	
	Livro livro = obj->item;
	
	printf("««LIVRO»»\n");
	printf("Titulo: %s \nAutor: %s \nQtd. Paginas: %d\n\n", 
		livro->titulo, livro->autor, livro->pag);
}

Object new_Livro(char* titulo, char* autor, int pag){
	
	Object obj = new(Object, LIVRO);
	Livro livro = malloc(sizeof(__Livro));
	
	livro->titulo = malloc(strlen(titulo) + 1 );
	livro->autor = malloc(strlen(autor) + 1 );
	
	strcpy(livro->titulo, titulo);
	strcpy(livro->autor, autor);
	
	livro->pag = pag;
	
	obj->item = livro;
	obj->printObjeto = print_Livro;

	return obj;
}

