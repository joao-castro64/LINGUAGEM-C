#define new(TYPE,...) new_##TYPE(__VA_ARGS__)
typedef enum{
	
	LIVRO,
	PLAYER
	
}Type;

typedef struct Node{
	
	void* item;
	
	struct Node* left;
	struct Node* right;
	void (*printObjeto)();
	Type type;
	
}Node;
typedef Node* Object;

Object new_Object(Type type){
	
	Object obj = malloc(sizeof(Node));
	
	obj->item = NULL;
	obj->left = NULL;
	obj->right = NULL;
	obj->type = type;
	return obj;

}





