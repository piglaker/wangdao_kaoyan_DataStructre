#include <iostream>
#include <cstdlib>

#define Maxsize 99

typedef struct SqList{
	int data[Maxsize];
	int length;

}SqList;



typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L){
	LNode *s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}	
	return L;
}

LinkList List_TailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return 	L;
}

LNode *GetElem(LinkList L, int i){
	int j = 1;
	LNode *p = L->next;
	if(i==0){
		return L;
	}
	if(i < 1){
		return NULL;
	}
	
	while(p  && j < i){
		p = p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p && p->data != e ){
		p = p->next;
	}
	return p;
}

typedef struct DNode{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

//-------------------------
// my utils

void test(int array[], int length){
	for(int i = 0;i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}


LNode *array2LinkList(int array[], int length){
	LNode *head, *now;
	head = (LNode *)malloc(sizeof(LNode));
	head->data = array[0];
	int i = 1;
	now = head;
	printf("in array2LinkList : %d \n", length);
	while(i < length){
		LNode *tmp;
		tmp = (LNode *)malloc(sizeof(LNode));
		tmp->data = array[i];
		now->next = tmp;
		now = tmp;
		i++;
		}
	LNode *L_head;
	L_head = (LNode *)malloc(sizeof(LNode));
	L_head->data = -1;
	L_head->next = head;
	return L_head;
	}

int **LinkList2array(LinkList L){

	int length = 0;
	
	LNode *p = L->next;
 	
	int *array = new int[100];

	int **package = new int*[2];

	int k = 0;

	while(p->next){
		array[k] = p->next->data;
		p = p->next;
		k++;
	}

	int *length_pointer = &k;

	package[0] = array;

	package[1] = length_pointer;

	return package;
}


int LinkList2array_SE(int array[], LinkList L){
	LNode *p = L->next;
	
	int k = 0;

	while(p){
		array[k] = p->data;
		p = p->next;
		k++;
		}

	return k;
}

LNode *get_LinkList(int length){
		
	LNode *head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	LNode *p = head;
	LNode *new_node;
	for(int i = 0 ; i < length; i++){
		new_node = new LNode;
		new_node->data = rand() %11;
		printf("%d ", new_node->data);
		new_node->next = p->next;
		p->next = new_node;
		p = new_node;
		}
	
	return head;
	}


DNode *get_DLinkList(int length){
	
	DNode *head = (DNode *)malloc(sizeof(DNode));
	head->next = NULL;
	DNode *p = head;
	DNode *new_node;

	for(int i = 0 ;i < length; i++){
		new_node = new DNode;
		new_node->data = rand()%11;
		printf("%d \n", new_node->data);
		new_node->next = p->next;
		new_node->prior = p;
		p->next = new_node;
		p = new_node;
	}
	return head;

	}


LNode *get_LinkList_in(int length){

	LNode *head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	LNode *p = head;
	LNode *new_node;
	for(int i = 0 ; i < length; i++){
		new_node = new LNode;
		new_node->data = i+1;
		new_node->next = p->next;
		p->next = new_node;
		p = new_node;
		}
	LNode *tmp = head;	
	p->next = NULL;
	return head;
	}



void test(LinkList L){
	LNode *p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
		}
	printf("\n");
}

void test(DLinkList D){
	DNode *d = D->next;
	while(d){
		printf("%d ", d->data);
		d = d->next;
	}
	printf("\n");
}


int get_length_LinkList(LinkList L){
	LNode *p = L;
	int length = 0;
	while(p->next){
		p = p->next;
		length++;
		}
	return length;

	}

void printf_addr_LinkList(LinkList L){
	LNode *p = L->next;
	while(p){
		printf("%p\n", p);
		p = p->next;
		}


	}


int find(SqList array, int e){
	for(int i = 0;i < array.length;i++){
		if(e == array.data[i]){
			return i;
			}

		}
	return -1;
	}


void insert(LinkList &L, LinkList &n){
	LNode *p = L;
		
	while(p->next){
		p = p->next;
		}
	p->next = n;
	n->next = NULL;
	printf("-----------%p\n", p);
	printf("-----%p\n", L->next);
}



//-------------------------------------------
//--------------------------------------------

void Delete_Elem(LinkList &L, int e){
	LNode *p = L;

	if(p->data == e){
		if(p->next){
			printf("try to change v of head here\n");
			L = p->next;
			Delete_Elem(L, e);
		}
		else{
			L = NULL;
			}
		}

	else{
	if(p->next){
		if(p->next->data == e){
			if(p->next->next){
				p->next = p->next->next;
				Delete_Elem(p->next, e);
			}	
			else{
				p->next = NULL;
				}
			}
		else{
			Delete_Elem(p->next, e);
			}

		}
	}
}


void Reversed_visit(LinkList L){
	int a[9999] = {0};
	
	LNode *p = L;
	
	int k =0;

	a[k] = p->data;
	
	while(p->next){
		p = p->next;
		k++;
		a[k] = p->data;
	}
	
	for(int j = k ; j >= 0 ; j--){
		printf("%d " , a[j]);
	}
	printf("\n");
}

LinkList Reversed_dupli(LinkList L){	
	LNode *p, *tmp;
	p = L->next;
	L->next = NULL;
	while(p != NULL){
		tmp = p->next;
		p->next = L->next;
		L->next = p;
		p = tmp;
		}
	return L;
}



void LinkList_sort(LinkList &L){
	
	LNode *p=L->next, *pre;
	
	LNode *r = p->next;

	p->next = NULL;

	p = r;

	while(p != NULL){
		pre = L;
		r = p->next;
		while(pre->next != NULL && pre->next->data < p->data){
			pre = pre->next;
			}
		p->next = pre->next;
		pre->next = p;
		p = r;
		}
}


void delete_Elem(LinkList &L, int a, int b){
	LNode *p = L->next;
	LNode *pre = L;
	
	while(p){
		
		if(p->data >= a && p->data <= b){
			if(p->next){
				pre->next = p->next;
				p = p->next;
				}
			else{
				pre->next = NULL;
				}
			}
		else{
			pre = p;
			p = p->next;
			}
		}
}



LNode *find_public_node(LinkList a, LinkList b){
	
	LNode *pa = a->next;

	while(pa){
		
		LNode *pb = b->next;
		while(pb){
			if(pb == pa){
				return pb;
				}
			else{
				pb = pb->next;
				}
			}
		pa = pa->next;
		}
	return NULL;
}


void printf_de_LinkList(LinkList L){
	//sort the LinkList for high to low, then output node by node;
}


void cut_LinkList(LinkList &L, LinkList &son){
	
		printf("start cut\n");

		LNode *p = L->next;
				
		LNode *pre = L;

		int k = 0;

		LNode *s = new LNode;

		while(p){
			printf("%d ", k);
			if(k % 2 == 0){
				pre = p;
				p = p->next;
				
				}
			else{
				s = p->next;	
				pre->next = p->next;
				insert(son, p);
				p = s;
				}
			k++;
			}
		printf("finish cut \n");
	}


int hash(int a){
	int prime = 209621;
	int bias = 138617;
	return a * bias % prime;
	}


void LinkList2Set(LinkList &L){
	
	int hash_map[299999] = {0};

	LNode *p = L->next;
	
	LNode *pre = L;
	
	while(p){
		printf("%d ", p->data);
		int key = hash(p->data); 
 		printf("%d", key);

		if(hash_map[key] == 0){
			hash_map[key] = 1;
			pre = p;
			p = p->next;
			printf(" new\n");
			
			}
		else{
			pre->next = p->next;	
			p = p->next;
			printf(" delete\n");
			
			}
		}
}



LNode *merge_LinkList(LinkList &a, LinkList &b){
	LNode *pa = a->next;
	LNode *pb = b->next;

	LNode *head = new LNode;

	head->next = NULL;

	LNode *tail = head->next;

	LNode *tmp = new LNode;

	while( pa || pb){
		
		if(pa && pb){
			
			if(pa->data > pb->data){
				head->next = pb;
				tmp = pb->next;
				pb->next = tail;
				tail = pb;
				pb = tmp;
				}
			else{
				head->next = pa;
				tmp = pa->next;
				pa->next = tail;
				tail = pa;
				pa = tmp;
				}
		}else{
			if( pa == NULL && pb){
				head->next = pb;
				tmp = pb->next;
				pb->next = tail;
				tail = pb;
				pb = tmp;
				}
			else{
				if( pa && pb == NULL){
					head->next = pa;
					tmp = pa->next;
					pa->next = tail;
					tail = pa;
					pa = tmp;
					}

				}
			}
		}
	return head;
}


int get_public_All_Elem(int array[], LinkList a, LinkList b){
	LNode *pa = a->next;
	LNode *pb = b->next;
	int k =0;
	while(pa){
		pb = b->next;
		while(pb){
			if(pb->data == pa->data){
				array[k] = pa->data;
				k++;
				break;
				}
			else{
				pb = pb->next;
				}
			}
		pa = pa->next;
		}
	return k;
}


LNode *merge_public_LinkList(LinkList a, LinkList b){
	
	LNode *pa = a->next;
	
	LNode *pb = b->next;
	
	LNode *head = new LNode;
	
	LNode *pre = head;

	int arr[9999] = {0};

	int length = get_public_All_Elem(arr, a , b);

	for(int i = 0;i<length; i++){
		LNode *new_node = new LNode;
		pre->next = new_node;
		new_node->data = arr[i];
		new_node->next = NULL;
		pre = new_node;
		}
	return head;
}

//------------------------
// kmp utils for array

void get_next_SE(int next[], int array[], int length){
	for(int i = 0;i<length;i++){
		next[i] = -1;
		}
	int j = -1;
	int i = 0;
	
	while( i < length ){
		if( j == -1 || array[i] == array[j]){
			i++;
			j++;
			next[i] = j;
			}
		else{
			j = next[j];
			}
		}
}


bool kmp_array(int s[], int length_s, int sub[], int length_sub, int next[]){
	int i = -1;
	int j = -1;
	
	while(j != length_sub && i < length_s){

		if(j == -1 || s[i] == sub[j]){
			i++;
			j++;
		}
		else{
			j = next[j];
			}
		}
	
	if(j == length_sub){
		return true;
		}
	else{
		return false;
		}
}

//-----------------------

bool kmp_LinkList(LinkList a, LinkList b){
	
	int a_array[9999] = {0};

	int b_array[9999] = {0};

	int a_length = LinkList2array_SE(a_array, a);

	int b_length = LinkList2array_SE(b_array, b);

	int *next = new int[9999];

	get_next_SE(next, b_array, b_length);

	for(int i = 0 ;i < b_length;i++){
		printf("%d ", next[i]);
		}
	printf("\n");


	bool ans = kmp_array(a_array, a_length, b_array, b_length, next);

	return ans;
}


bool if_palindrome(DLinkList D){
	DNode *d = D->next;

	//get length and DLinkLsit2array

	int length = 0;

	int array[9999] = {0};

	while(d){
		array[length] = d->data;
		d = d->next;
		length++;
	}

	test(array, length);

	//reverse the array then judge array if palindrome

	int array_T[9999] = {0};

	for(int i = length - 1;i >= 0;i--){
		array_T[length - 1 - i] = array[i]; 
	}

	test(array_T, length);

	for(int i = 0;i < length;i++){
		if(array[i] != array_T[i]){
			return false;
		}

	}

	return true;

}

void merge_loop_LinkList(LinkList &L1, LinkList &L2){
	LNode *head1 = L1;
	LNode *head2 = L2;
	LNode *tail1 = L1 -> next;
	LNode *tail2 = L2 ->next;

	while(tail1->next != L1){
		tail1 = tail1->next;
	}
	
	while(tail2->next != L2){
		tail2 = tail2->next;
	}

	tail1->next = head2;

	tail2->next = head1;
}


void test_loop_ls(LinkList L){
	printf("test loop_LinkList:\n");
	LNode *p = L->next;
	while(p != L){
		printf("------%d %p %p %p-------\n", p->data,  L, p, p->next);
		p = p->next;
	}	
}



void free_loop_LinkList(LinkList &L){
	
	LNode *p = L->next;
	
	int k = 10;

	printf("start :%p %p\n", L, p);

	while(p != L && p && k > 0){

		//test_loop_ls(L);

		k--;

		int min = 9999;

		while(p != L){
			if(p->data < min ){
				min = p->data;
			}
			p = p->next;
		}

		p = L->next;

		LNode *pre = L;

		while(p != L){
			if(p->data == min){
				pre->next = p->next;
				printf("%d\n", p->data);
				free(p);
				break;
			}
			else{
			pre = p;
			p = p->next;
			}
		}
		p = L->next;
		//test_loop_ls(L);
	}
	free(L);
}