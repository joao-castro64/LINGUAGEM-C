#define new(TYPE,...) new_##TYPE(__VA_ARGS__)


typedef struct{
	
	Object head;
	Object tail;
	int size;
	
}__List;
typedef __List* List;

List new_List(){
	
	List list = malloc(sizeof(__List));
	
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void list_enqueue(List list, Object obj){
	
	if(!list->head){
		list->head = obj;
		list->tail = obj;
		return;
	}
	
	list->tail->right = obj;
	obj->left = list->tail;
	list->tail = obj;

}

void list_print(List list){
	
	Object obj = list->head;
	
	while(obj){
		switch(obj->type){
			
			case LIVRO: obj->printObjeto(obj);
				break;
				
			case PLAYER: obj->printObjeto(obj);
				break;
			
		}
		obj = obj->right;
	}
	
}

