//definindo uma interface padrão para funções construtoras
#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __List{
	Object head;
	Object tail;
	int size;
}__List;
typedef __List* List;

List new(List){
	
	List list = malloc(sizeof(__List));
	
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void list_enqueue(List list, Object obj){
		
		if(list->head == NUL){
			list->head = obj;
			list->tail = obj;
			return;
		}
		
		list->tail->prox = obj;
		list->tail = obj;	
}
