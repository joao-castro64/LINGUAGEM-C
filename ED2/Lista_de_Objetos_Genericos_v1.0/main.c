#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "object.h"
#include "list.h"
#include "player.h"


int main(){
	
	List list = new(List);

	Player p1 = new(Player, "Moravec");
	Player p2 = new(Player, "Obelisco");
	
	Object obj1 = new(Object, p1, PLAYER);
	Object obj2 = new(Object, p2, PLAYER);
	
	list_enqueue_fila(list, obj1);
	list_enqueue_fila(list, obj2);
	
	foreach(list, exibirPlayer, PLAYER);
	
	printf("----------------------------------\n");
	printf("Primeiro da fila\n\n");
	
	Object obj = list_pop(list);
	
	exibirPlayer(obj->item);
	
	printf("-----------------------------------\n");
	printf("Criando um player e adicionando ao topo da lista: \n\n");
	
	Player p3 = new(Player, "Law");
	Object obj3 = new(Object, p3, PLAYER);
	list_push(list, obj3);
	foreach(list, exibirPlayer, PLAYER);
	
	printf("-----------------------------------\n");
	printf("verificando se a lista foi excluida\n\n");
	list_all_clear(list);
	foreach(list, exibirPlayer, PLAYER);
	
	printf("-----------------------------------\n");
	printf("-----------------------------------\n");
	printf("Recriando Lista\n\n");
	p1 = new(Player, "Bilbo");
	p2 = new(Player, "Gandalf");
	p3 = new(Player, "Thorin");
	
	obj1 = new(Object, p1, PLAYER);
	obj2 = new(Object, p2, PLAYER);
	obj3 = new(Object, p3, PLAYER);
	
	list_enqueue_fila(list, obj1);
	list_enqueue_fila(list, obj2);
	list_enqueue_fila(list, obj3);

	foreach(list, exibirPlayer, PLAYER);
	
	printf("-----------------------------------\n");
	printf("verificando se todos os player foram excluidos\n\n");
	list_clear(list, PLAYER);
	foreach(list, exibirPlayer, PLAYER);

}
