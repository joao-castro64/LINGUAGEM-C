#define new(TYPE,...) new_##TYPE(__VA_ARGS__)
//list_pop // retorna o primeiro da lista;
typedef struct{
	
	Object head;
	Object tail;
	Object topo2;
	int size;
	
}__List;
typedef __List *List;

List new_List(){
	
	List list = malloc(sizeof(__List));
	
	list->head = NULL;
	list->tail = NULL;
	list->topo2 = NULL;
	list->size = 0;
	
	return list;
}

void list_enqueue_fila(List list, Object obj){
	
	if(list->head == NULL){
		list->head = obj;
		list->tail = obj;
		list->topo2 = obj;
		list->size++;
		return;
	}
	
	obj->prev = list->tail;
	list->tail->next = obj;
	list->tail = obj;
	list->size++;
}

void foreach(List list, void f(), Type type){
	
	Object obj = list->head;
	if(obj == NULL) return;
	
	while(obj != NULL){
		if(obj->type == type)
			f(obj->item);
		obj = obj->next;
	}
}

Object list_pop(List list){
	
	Object obj = list->head;
	return obj;
	
}

void list_push(List list, Object obj){
		
	list->head->prev = obj;
	obj->next = list->head;
	list->head = obj;

}

void list_all_clear(List list){
	
	Object obj = list->head;
	
	for(int i = 0; i <= list->size; i++){
		
		list->head = list->head->next;
		free(obj);
		obj = list->head;
	}
	list->head = NULL;
	list->tail = NULL;
}

void list_clear(List list, Type type){
	
	if(list->head == NULL) return;
	
	Object obj = list->head;
	if(obj->type == type){
		list->head = obj->next;
		free(obj);
	}
		
	
	while(obj != NULL){
		if(obj->type == type){
			obj->prev->next = obj->next;
			if(obj->next != NULL)
				obj->next->prev = obj->prev;
			if(obj->prev == NULL)
				list->head = obj->next;
			if(obj->next == NULL)
				list->tail = obj->prev;
			free(obj);
		}
		obj = obj->next;
	}
	
}
	
