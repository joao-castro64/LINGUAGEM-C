typedef struct __Object{
	void* item;
	struct __Object* left;
	struct __Object* right;
}__Object;
typedef __Object* Object;

Object new_Object(){
	Object obj = malloc(sizeof(__Object));
	
	obj->item = NULL;
	obj->left = NULL;
	obj->right = NULL;
	return obj;
}





