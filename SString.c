#include <stdlib.h>
#include <iostream>
#include "SString.h"


int main(){

	char zero[13] = {'a', 'a', 'b', 'a', 'a', 'b', 'a', 'a', 'b', 'a', 'a', 'c', '\0'} ;

	char p[7] = {'a', 'a', 'b', 'a', 'a', 'c', '\0'};

	SString *S = new SString;

	SString *T = new SString;

	StrAssign(*S, zero);

	StrAssign(*T, p);
	
	test(*S);

	test(*T);
		
	int *next = new int[6];

	get_next(next, p, 6);

	for(int i = 0 ;i < 6;i++){
		printf("%d ", next[i]);
	}
	
	printf("\n");

	bool is_match = kmp(*S, *T, next);

	if(is_match){
		printf("is_match\n");
	}
	else{
		printf("not_mtach\n");
	}

}



