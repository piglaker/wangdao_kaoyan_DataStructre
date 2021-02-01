#include <iostream>
#include <stdlib.h>
#include "linked_table.h"


int main(){
		
	int array[15] = {1,2,3,1,1,2,4};

		LinkList L;
		
		int k = 0;
		
		printf("%ld\n", sizeof(k));

		printf("%ld\n", sizeof(array));

		while(1){
			printf("%d ", array[k]);
			k++;
			if(k > sizeof(array) / sizeof(k) - 1){
				break;
				}
			}
		
		printf("\n");

		L = array2LinkList(array, sizeof(array) / sizeof(k));

		test(L);

		printf("Delete all Elem in LinkList equal to : %d\n", 1);
		
		Delete_Elem(L, 1);

		test(L);

		printf("reversed_visit\n");

		Reversed_visit(L);

		printf("reverse the LinkList\n");

		LinkList L_head = L;

		L_head = Reversed_dupli(L_head);

		test(L_head);
		
		int **point;

		point = LinkList2array(L_head);
		
		printf("%d\n", **point);

		printf("%d\n", **(point+1));	

		printf("LinkList_sort:\n");

		LinkList_sort(L_head);

		test(L_head);

		printf("Delete_Elem\n");	
		
		delete_Elem(L_head, 0 , 2);

		test(L_head);
			
		printf_addr_LinkList(L_head);

		LNode *a;

		printf("test get_LinkList:\n");

		printf("first random LinkList:\n");

		a = get_LinkList(5);

	test(a);

	printf("second random LinkListi\n");

	LNode *b;
	
	b = get_LinkList(5);
	
	test(b);

	printf("test addr walk:\n");

	printf_addr_LinkList(a);
	
	printf("test addr walk 2\n");
	
	printf_addr_LinkList(b);
	
	printf("test find_public_node\n");

	LNode *result;

	result = find_public_node(a, b);

	printf("%p\n", result);

	printf("test insert:\n");	

	LNode *son;

	son = new LNode;

	son->next = NULL;

	LNode *new_node;

	new_node = new LNode;

	new_node->next = NULL;

	new_node->data = 1;

	insert(son, new_node);

	printf("%p\n", son);

	printf("%p\n", son->next);

	test(son);
	
	printf("test LinkList\n");

	LNode *odd_ls;

	odd_ls = new LNode;

	odd_ls->next = NULL;

	test(b);

	cut_LinkList(b, odd_ls);
	
	test(b);

	test(odd_ls);
	
	printf("test LinkList2Set:\n");

	LNode *rand_LinkList;

	rand_LinkList = get_LinkList(20);

	printf("before:\n");

	test(rand_LinkList);

	printf("%p %d\n", rand_LinkList, rand_LinkList->data);

	printf("%p %d\n", rand_LinkList->next, rand_LinkList->next->data);

	LNode *killer = new LNode;

	killer = rand_LinkList->next;

	printf("%p \n", killer);

	LinkList2Set(rand_LinkList);

	printf("after:\n");

	test(rand_LinkList);

	printf("test merge_LinkList");

	LNode *L0 = get_LinkList_in(7);

	LNode *L1 = get_LinkList_in(5);
	
	test(L0);

	test(L1);

	LNode *L2 = merge_LinkList(L0, L1);

	test(L2);

	printf("test public node of :\n");

	LNode *l0 = get_LinkList_in(8);

	LNode *l1 = get_LinkList_in(10);

	test(l0);

	test(l1);

	int arr[9999] = {0};

	int length_arr = 0;

	length_arr = get_public_All_Elem(arr, l0, l1);
	
	for(int i = 0; i< length_arr;i++){
		printf("%d ", arr[i]);
		}
	
	printf("\n");

	LNode *new_common_LinkList = new LNode;

	new_common_LinkList = merge_public_LinkList(l0, l1);

	test(new_common_LinkList);

	printf("test kmp in LinkLIsti\n");

	LNode *a_linklist = get_LinkList(40);

	LNode *b_linklist = get_LinkList(2);

	test(a_linklist);

	test(b_linklist);

	bool ans = kmp_LinkList(a_linklist, b_linklist);

	if(ans){
		printf("is_sub\n");
		}
	else{
		printf("is_not_sub\n");
		}

	printf("test is_palindrome for DLinkList \n");

	int length = 8;

	DNode *D = get_DLinkList(length);

	test(D);

	bool is_palindrome = if_palindrome(D);

	if(is_palindrome){
		printf("is_palindrome\n");
	}
	else{
		printf("not palindrome\n");
	}

	printf("test merge loop LinkList\n");

	LNode *loop_single1 =  get_LinkList(length);

	LNode *loop_single2 = get_LinkList(length);

	LNode *tmp1 = loop_single1->next;

	LNode *tmp2 = loop_single2->next;

	while(tmp1->next){
		tmp1 = tmp1 -> next;
	}

	tmp1->next = loop_single1;

	while(tmp2->next){
		tmp2 = tmp2->next;
	}

	tmp2->next = loop_single2;

	merge_loop_LinkList(loop_single1, loop_single2);

	//-----------------19--------------------------

	printf("test free loop_linklist\n");

	LNode *loop_ls = get_LinkList(length);

	LNode *move = loop_ls;

	while(move->next){
		move = move->next;
	}

	move->next = loop_ls;
	
	printf("%p", loop_ls);

	test_loop_ls(loop_ls);

	free_loop_LinkList(loop_ls);

	


	return 0;
}


