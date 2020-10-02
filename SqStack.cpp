#include <iostream>
#include <stdlib.h>
#include "SString.h"
#include "line_table.h"
#include "linked_table.h"
#include "SqStack.h"
#include "SString.h"


#define MaxSize 50


int main(){

    char *str;

    str = get_data();

    test_str(str);    

	bool is_legal = if_legal(str);
	
	if(is_legal){
		printf("is_legal\n");
		}
	else{
		printf("is_not_legal\n");
		}

	LinkList head = char2LinkList(str);

	LNode *p = head->next;

	while(p){
		printf("%c ", p->data);
		p = p->next;
		}

	printf("\n");

	bool is_centralsymmetry = if_centralsymmetry(head);

	if(is_centralsymmetry){
		printf("is_centralsymmetry\n");
	}
	else{
		printf("is_not_centraksymmetry\n");
	}

	printf("test SqQueue");


	

}



