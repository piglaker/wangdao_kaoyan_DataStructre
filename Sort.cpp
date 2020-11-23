#include "Sort.h"




int main(){
    int a[5] = {1,5,4,3,2};

    test(a, 5);

    InsertSort(a, 5);

	printf("InsertSort:\n");

    test(a, 5);

    int a2[7] = {1,2,4,6,8,3,5};

    test(a2, 7);

	printf("InsertSort_bs\n");

    InsertSort_bs(a2,7);

    test(a2, 7);

    int a3[7] = {1,2,4,6,8,3,5};

    test(a3, 7);

    BubbleSort(a3,7);

	printf("BubbleSort\n");

    test(a3, 7);

	int a4[7] = {3,4,5,6,7,1,2};

	test(a4, 7);

	heap_sort(a4, 7);

	printf("heap_sort\n");

	test(a4, 7);

	int a5[8] = {1,5,4,5,8,1,4,4};

	test(a5, 8);

	printf("MergeSort\n");

	MergeSort(a5, 0, 7);

	test(a5, 8);

	int a6[8] = {4,6,8,4,78,3,31,7};
	
	test(a6, 8);

	printf("quicksort:\n");

	quicksort(a6, 0, 7);

	test(a6, 8);

	int a7[8] = {4,67,71,4,1,5,6,9};

	test(a7, 8);

	printf("heap_sort:\n");	

	heap_sort(a7, 8);

	test(a7, 8);


    return 0;

}




