#include <stdlib.h>
#include <iostream>


#define MAXLEN 255

typedef struct{
	char ch[MAXLEN];
	int length;
}SString;


typedef struct{
	char *ch;
	int length;
}HString;


void StrAssign(SString &T, char chars[]){
	int k = 0;
	while(chars[k] != '\0'){
		T.ch[k] = chars[k];
		T.length++;
		k++;
	}	
}


void StrSopy(SString &T, SString S){
	for(int i = 0;i < S.length; i++){
		T.ch[i] = S.ch[i];
	}
}


bool StrCompare(SString S, SString T){
	int length_s = S.length;
	int length_t = T.length;

	for(int i = 0; i < (length_s > length_t) ? length_t : length_s;i++){
		if(S.ch[i] != T.ch[i]){
			return false;
		}
	}	 	
	if(length_s == length_t){
	return true;
	}
	else{
		return false;
	}
}


int StrLength(SString S){
	return S.length;
}


void SubString(SString &sub,SString S,  int pos, int len){
	for(int i = pos;i < pos + len;i++){
		sub.ch[i] = S.ch[i];
		sub.length++;
	}
}


void concat(SString &T, SString S1, SString S2){
	int length1 = S1.length;
	int length2 = S2.length;

	for(int i = 0;i < length1;i++){
		T.ch[i] = S1.ch[i];
		T.length++;
	}	
	for(int i = 0;i<length2;i++){
		T.ch[length1 + i] = S2.ch[i];
		T.length++;
	}

}


int index(SString S, SString T){
	int i = 0, length_s = StrLength(S), length_t = StrLength(T);
	
	SString *sub = new SString;
	while(i <= length_s - length_t){
		SubString(*sub, S, i, length_t);
		if(StrCompare(*sub, T)){
			i++;
		}else{
			return i;
		}
	}
	return -1;
}



void ClearString(SString &S){
	for(int i = 0;i<S.length;i++){
		S.ch[i] = '\0';
	}
	S.length = 0;

}

void DestroyString(SString &S){
	free(S.ch);
	free(&S);
}

//------------------------------------------


void test(SString S){
	for(int i = 0; i < S.length;i++){
		printf("%c ", S.ch[i]);
	}
	printf("\n");
}



//------------------------------------------


int main(){

	char zero[7] = {'a', 'b','c','d', 'e', 'f', 'g'} ;

	SString *S = new SString;

	StrAssign(*S, zero);

	test(*S);


}



