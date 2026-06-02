typedef enum{
	
	PLAYER
	
}Type;

typedef struct Node{
	
	void *item;
	Type type;
	struct Node *next;
	struct Node *prev;
	
}Node;
typedef Node* Object;

Object new_Object(void *item, Type type){
	
	Object obj = malloc(sizeof(Node));
	
	obj->item = item;
	obj->type = type;
	obj->next = NULL;
	obj->prev = NULL;
	
	return obj;
	
}
	
