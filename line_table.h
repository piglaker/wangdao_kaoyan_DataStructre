#include <iostream>
#include <stdlib.h>

#define Maxsize 20
#define TOP 65535

typedef struct{
	int data[Maxsize];
	int length;
}SqList;

typedef struct{
	int *data;
	int MaxSize,length;
}SeqList;

typedef struct{
	int *p[Maxsize];
	int length;
}SqPointer;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;

}

void test(int &a){
		
}

void test(SqList &L){
	for(int i = 0; i < L.length; i++){
		printf("%d\t", L.data[i]);
	}
	printf("\n");

}


bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length){
		return false;
	}

	if(L.length >= Maxsize){
		return false;
	}
	
	if(i == L.length){
		L.length++;
		L.data[i] = e;
		return true;
	}


	int tmp = 0;

	for(int j = 0; j < L.length;j++){
		if(j == i){
			tmp = L.data[j];
			L.data[j] = e;
		}
		if(j > i){
			swap(L.data[j], tmp);	
		}
	}
	L.length++;
	L.data[L.length - 1] = tmp;
	return true;
}


bool ListDelete(SqList &L, int i, int e){
	if(i < 0 || i > L.length){
		return false;
	}
	e = L.data[i];
	for(int j = i;j < L.length - 1;j++){
		L.data[j] = L.data[j + 1];
	}
	L.length--;
	return true;
}

int LocateElem(SqList &L, int e){
	for(int j = 0; j <L.length;j++){
		if(L.data[j] == e){
			return j;
		}
	}
	return -1;
}


int DeleteMin(SqList &L){
	int min = 65535;
	if(L.length < 1){
		printf("The list is empty!");
		return 1;
	}

	for(int j = 0; j < L.length;j++){
		min = (L.data[j] < min) ? L.data[j] : min;
	}
	int ans;
	ListDelete(L, LocateElem(L, min), ans);
	printf("min is %d\n", min);
	return ans;
}

void reversed(SqList &L){
	for(int j = 0;j< L.length / 2;j++){
		swap(L.data[j], L.data[L.length - 1 - j]);
	}
}

void DeleteAllX(SqList &L, int x){
	int max = L.length;
	int rubish = 0;
	for(int i = 0; i<max; i++){
		if(L.data[i] == x){
			ListDelete(L, i, rubish);
			max--;
			i--;
		}	
	}
}

void DeleteBetween(SqList &L, int a, int b){
	int border = L.length;
	int bin = 0;
	if( a >= b || L.length < 1){
		printf("Wrong parameters!");
		exit(0);
	}
	
	for(int j = 0;j < border;j++){
		if(L.data[j] > a && L.data[j] < b){
			ListDelete(L, j, bin);
			border--;
			j--;
		}
	}
}

void Set(SqList &L){
	int border = L.length;
	SqList L2;
	L2.length = 0;
	int bin;
	for(int i = 0; i < border; i++){
		if(LocateElem(L2, L.data[i]) != -1){
			ListDelete(L, i, bin);
			border--;
			i--;
		}
		else{
			L2.data[L2.length] = L.data[i];
			L2.length++;
		}
	}
}

SqList MergeList(SqList &L1, SqList &L2){
	SqList List;
	List.length = L1.length + L2.length;
	int point = 0;
	for(int i = 0; i < L1.length; i++){
		List.data[point] = L1.data[i];
		point++;
	}
	for(int j = 0; j < L2.length; j++){
		List.data[point] = L2.data[j];
		point++;
	}
	return List;
}

void reversed_in(SqList &L, int start, int end){
	for( int i = start; i < (end - start) / 2 + 1 + start; i++){
		swap(L.data[i], L.data[end - i + start ]);
	}
}

SqList sublist(SqList &L, int start ,int end){
	SqList sl;
	if(end < start){
		printf("sub lisr error! (end < start !)");
	}
	sl.length = end - start;
	for(int i = start ; i < end; i++){
		sl.data[i - start] = L.data[i];	
	} 
	return sl;
}


int BinarySearch(SqList &L, int e){
	int low = 0;
	int high = L.length - 1;
	int mid = 0;	
	while(1){
		mid = (high + low) / 2;
		if(e > L.data[high]){
			ListInsert(L, high+1, e);
			return -1;
		}
		if(e < L.data[low]){
			ListInsert(L, low, e);
			return -1;
		}
		if(e == L.data[mid]){
			if(mid + 1 < L.length){
				swap(L.data[mid], L.data[mid+1]);
			}
			return 1;
		}
		else{
			if(e > L.data[mid]){
				low = mid;
			}
			else{
				high = mid;
			}
		}
	}
}


void cycle_move(SqList &L, int p){
	reversed_in(L, 0, L.length - 1);	
	reversed_in(L, 0, p);
	reversed_in(L, p+1, L.length-1);
}

int mid_of_couple(SqList a, SqList b){
	int path = 0;	
	path = (a.length + b.length + 1) / 2;

	int p1 = 0;
	int p2 = 0;
	int flag = 0;
	for(int i = 0; i < path;i++)
	{
		if(p1 == a.length - 1)
		{
			p2++;
			flag = 1;	
		}
		else{
			if(p2 == b.length - 1){
				p1++;
				flag = 2;
			}
			else{
				if(a.data[p1] > b.data[p2])
				{
					p2++;
					flag = 1;	
				}
				else{
					p1++;
					flag = 2;
				}
			}
		}
	}
	
	if(flag == 1){
		printf("a: %d - 1" , p1);
		return a.data[p1-1];
	}
	else{
		if(flag == 2){
			printf("b:%d - 1", p2);
			return b.data[p2-1];
		}
		else{
			printf("something wrong!");
		return -1;
		}
	}
}


int find_main_Elem(SqList &L){

	int hash_map[TOP] = {-1};

	int k=0;

	int max = 0;

	int main_Elem = 0;

	for(int i = 0; i < L.length; i++){		
		if( hash_map[L.data[i]] < 0 ){
			hash_map[L.data[i]] = 1;
		}
		else{
			hash_map[L.data[i]]++;
			if(hash_map[L.data[i]] > max){
				max = hash_map[L.data[i]];
				main_Elem = L.data[i];
			}
		}
	}
	return (max > L.length / 2) ? main_Elem : -1;	
}

int find_min_lack(SqList &L){
	
	int hash_map[TOP] = {0};//c++ default value if given_elem_length < len(array) :0

	int min = TOP;

	for(int i = 0; i < L.length; i++){
		hash_map[L.data[i]] = 1;
		if(L.data[i] < min){
			min = L.data[i];
		}
	}
	
	while(1){
		min++;
		if(hash_map[min] == 0){
			return min;
		}
	}
	
}
