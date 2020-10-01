#include <iostream>
#include <stdlib.h>

#define MaxSize 50

typedef struct{
    char data[MaxSize];
    int top;
}SqStack;




void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Push(SqStack &S, char x){
    if(S.top + 1 == MaxSize ){
        return false;
    }
    else{
        S.top++;
        S.data[S.top] = x;
        return true;
    }
}


bool Pop(SqStack &S, char &x){
    if(S.top == -1){
        return false;
    }
    else{    
    x = S.data[S.top];
    S.top--;
    return true;
    }
}

bool GetTop(SqStack S, char &x){
    if(S.top == -1){
        return false;
    }
    else{
        x = S.data[S.top];
        return true;
    }
}

void DestroyStack(SqStack &S){
    free(S.data);
    free(&S);
}

typedef struct Linknode{
    int data;
    struct Linknode *next;
}*LiStack;

//---------------------

char *get_data(){
    char* str = new char[MaxSize];
    std::cin.get(str, 30).get();
    return str;
}   


void test_str(char str[]){
	int k = 0;
	while( str[k] != '\0'){
		printf("%c ", str[k]);
		k++;
	}
	printf("\n");
}


typedef struct LNode{
	char data;
	struct LNode *next;
}LNode, *LinkList;


LNode *char2LinkList(char s[]){
	LNode *head = new LNode;
	
	head->next = NULL;

	int k = 0;
	
	LNode *p = head;

	while(s[k] != '\0'){
		LNode *new_node = new LNode;
		new_node->data = s[k];
		new_node->next = NULL;
		p->next = new_node;
		p = new_node;
		k++;
		}
	return head;
}



//--------------------

bool if_legal(char str[]){
	int k = 0;
	int count = 0;
	while( str[k] != '\0'){
		printf("%c\n", str[k]);
		if( str[k] =='I'){
			count++;	
			}
		else{
			count--;
			}
		k++;
		if(count < 0){
			return false;
			}
		}
    return true;
}


bool if_centralsymmetry(LinkList head){
	SqStack *S = new SqStack;
	
	InitStack(*S);

	LNode *p = head->next;

	int length = 0;

	while(p){
		length++;
		p = p->next;
	}	

	p = head->next;

	for(int i = 0;i < length / 2;i++){
		Push(*S, p->data);
		p = p->next;
	}


	if(length % 2 != 0){
		p = p->next;
	}
	
	while(S->top != -1){
		if(S->data[S->top] == p->data){
			char x;
			Pop(*S,x);
			p = p->next;
		}
		else{
			return false;
		}
	}
	
	return true;
}


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

}



