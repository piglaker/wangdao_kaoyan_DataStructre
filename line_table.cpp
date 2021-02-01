#include<iostream>
#include "line_table.h"


int main(){
	SqList L;
	L.length = 10;
	for(int i = 0;i < L.length; i++){
		L.data[i] = i;
	}
	test(L);
	int target = 1;
	int e = 5;
	
	bool p = ListInsert(L, target, e);
	printf("%d\n", p);
	test(L);

	int target2 = 3;

	int e2 = 0;

	bool d = ListDelete(L, target2, e2);

	printf("index :%d, value:%d \n", target2, e2);

	test(L);

	int index = LocateElem(L, 1);

	printf("DeleteMin\n");

	DeleteMin(L);

	test(L);

	printf("reversed:\n");	
	
	reversed(L);

	test(L);

	printf("Delete All 1\n");

	DeleteAllX(L, 1);

	test(L);

	printf("Delete all number between 4-7\n");

	DeleteBetween(L, 4,7);

	test(L);
	
	printf("Set of L");

	Set(L);

	test(L);

	printf("Merge List\n");

	SqList tmp;
	tmp.length = 3;
	for(int i = 0;i < tmp.length; i++){
		tmp.data[i] = i;
	}
	
	SqList new_list;

	new_list = MergeList(L, tmp);

	test(new_list);
	
	printf("Reverse_in :\n");
	
	SqList L3;
	L3.length = 0;
	for(int i = 0;i < 10;i++){
		L3.data[i] = i;
		L3.length ++;
	}

	test(L3);

	reversed_in(L3, 0, L3.length-1);

	test(L3);

	reversed_in(L3, 0, 5);

	test(L3);

	reversed_in(L3, 6, L3.length-1);

	test(L3);
	
	printf("Lets go BinarySearch!\n");
	
	SqList L4;
	
	L4.length = 10;

	for(int i = 0;i < L4.length;i++){
		L4.data[i] = i;
	}

	test(L4);
	
	int res = BinarySearch(L4, 5);
	
	printf("%d\n", res);

	test(L4);

	int res2 = BinarySearch(L4, 10);

	printf("%d\n", res2);

	test(L4);
	
	printf("cycle move...\n");

	cycle_move(L4, 4);

	test(L4);

	SqList L5;

	L5.length = 5;

	for(int i = 0;i < L5.length;i++){
		L5.data[i] = 10 + i;
	}

	SqList L6;

	L6.length = 8;

	for(int i = 0;i < L6.length;i++){
		L6.data[i] = i;
	}

	int mid_number = 0;

	printf("get mid_number\n");

	test(L6);

	test(L5);

	mid_number = mid_of_couple(L6, L5);

	printf("%d\n", mid_number);

	printf("Find the main element of SqList\n");

	for(int i = 0; i < 5;i++){
		L6.data[i] = 1;
	}

	test(L6);

	int ans = find_main_Elem(L6);

	printf("%d\n", ans);

	printf("find min lack element\n");
	
	test(L6);
	
	int min_lack_of_SqList = find_min_lack(L6);

	printf("%d\n", min_lack_of_SqList);

	return 0;
}



