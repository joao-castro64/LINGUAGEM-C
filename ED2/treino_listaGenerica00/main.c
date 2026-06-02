#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "object.h"
#include "livro.h"
#include "list.h"
#include "player.h"


int main(){
	
	List list = new(List);
	
	Object obj = new(Livro, "Estrela", "Clarice", 200);
	list_enqueue(list, obj);
	
	Object obj1 = new(Player, "Gandalf", "Magia", 200);
	list_enqueue(list, obj1);
	
	Object obj2 = new(Livro, "Subsolo", "Fiódor", 400);
	list_enqueue(list, obj2);
	
	Object obj3 = new(Player, "E. Newgate", "Gura Gura no Mi", 1000);
	list_enqueue(list, obj3);
	
	list_print(list);

}
