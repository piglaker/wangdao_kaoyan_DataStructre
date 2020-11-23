#include <iostream>
#include <stdlib.h>


void test(int array[], int length){
    for(int i = 0;i < length;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


typedef struct{
	int *elem;
	int length;
}SSTable;


typedef struct{
	int *elem;
	int length;
}SqList;


int Search_Seq(SSTable s, int x){
	for(int i = 0; i < s.length;i++){
		if(s.elem[i] == x){
			return i;	
		}
	}
	return -1;
}


int Binart_Search(SqList L, int x){
	int low = 0, high = L.length -1,mid;
	while(low <= high){
		mid = (low + high) / 2 ;
		if(L.elem[mid] == x){	
			return mid;
		}
		else{
			if(L.elem[mid] > x){
				low = mid + 1;
			}
			else{
				high = mid -1 ;
			}
		}
	}
	return -1;
}



void InsertSort(int array[], int length){
    int i, j, tmp;
    for(i = 1;i < length;i++){
        if(array[i] < array[i-1]){
            for(j = i -1;array[j] > array[j+1] && j >= 0 ;j--){
                tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
    }
}


void InsertSort_bs(int array[], int length){
    int i, tmp;
    
    for(i = 1;i < length;i++){
        if(array[i] < array[i-1]){
            int low = 0;
            int high = i - 1;        
            int mid;
            while(low <= high){
                mid = (low + high) / 2;
                if(array[mid] > array[i]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            tmp = array[i];
            for(int j = i-1;j>=high;j--){
                array[j+1] = array[j];
            }
            array[high+1] = tmp;
        }
    }
}


void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(int array[], int length){
    for(int i = 0;i < length-1;i++){
        for(int j = 0;j < length - i;j++){
            if(array[j] < array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

int Partition(int array[], int low, int high){
    int pivot = array[low];
    while(low < high){
        while(low < high && array[high] >= pivot){
            --high;
        }
        array[low] = array[high];
        while(low < high && array[low] <= pivot){
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
	return low;

}

void QuickSort(int array[], int low, int high){
    if(low < high){
        int pivot = Partition(array, low, high);
        QuickSort(array, low, pivot);
        QuickSort(array, pivot+1, high);
    }
}

int min(int array[], int start, int n){
	int min_ = 65535;
	int index = start;
	for(int i = start;i < n;i++){
		if(array[i] < min_){
			min_ = array[i];
			index = i;
		}
	}
	return index;
}


void Select_Sort(int array[], int n){
	int index = 0;
	for(int i = 0;i < n;i++){
		index = min(array, i, n);
		if(index != i){
			swap(array[index], array[i]);
		}
	}
}


int a[1000];
int b[1000];


void Merge(int array[], int start0, int end0, int start1, int end1){
	int length_a = 0;
	int length_b = 0;
	for(int i = start0;i <= end0;i++){
		a[i - start0] = array[i];
		length_a++;
	}	
	for(int j = start1; j <= end1; j++){
		b[j - start1] = array[j];
		length_b++;
	}
	int k = start0;

	int i = 0, j = 0;

	while(k <= end1 && (i < length_a || j < length_b)){
		if(length_a == i){
			array[k++] = b[j++];
			continue;
		} 
		if(length_b == j){
			array[k++] = a[i++];
			continue;
		}
		if(a[i] < b[j]){
			array[k++] = a[i++];
		}
		else{
			array[k++] = b[j++];
		}
	}
}


void MergeSort(int array[], int low ,int high){
	if(low < high){
		int mid = (high + low) / 2;
		MergeSort(array, low, mid);
		MergeSort(array, mid+1, high);
		Merge(array, low, mid, mid+1,  high);
	}
	
}


void update(int array[], int length, int target){
	
	int left = target * 2 + 1;
	int right = target * 2 + 2;
	int mx = target;
	
	int tmp = array[target];
	
	if(left < length && array[target] < array[left]){
		mx = left;
		tmp = array[left];
	}
	
	if(right < length && tmp < array[right]){
		mx = right;
	}

	if(mx != target){
		swap(array[mx], array[target]);
		update(array, length, mx);	
	}
}

int helper[1000];

void heap_sort(int array[], int length){
	for(int i = length / 2;i >= 0; i--){
		update(array, length, i);
	}

	int count = length -1;
	int i = 0;

	while(count >= 0){
		helper[i++] = array[0];
		swap(array[count--], array[0]);
		update(array, count+1, 0);
	}
}


int lower[1000];
int bigger[1000];


int part(int array[], int low, int high){
	int flag = array[low];
	
	int i = 0, j = 0;

	for(int p = low+1;p <= high; p++){
		if(array[p] > flag){
			bigger[j++] = array[p];
		}
		else{
			lower[i++] = array[p];
		}
	}	

	int tmp = low;

	for(;tmp < low + i;tmp++){
		array[tmp] = lower[tmp - low];
	}

	array[tmp] = flag;

	for(int l = 0;l < j;l++){
		array[tmp+1+l] = bigger[l];
	}
	
	return tmp;
}

void quicksort(int array[] ,int low, int high){
	int mid = part(array, low, high);
	if(low < mid-1){
		quicksort(array, low, mid-1);
	}
	if(mid+1 < high){
		quicksort(array, mid+1, high);
	}
}



