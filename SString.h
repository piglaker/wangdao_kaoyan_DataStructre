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
	/*
	assgin chars to T
	*/
	int k = 0;
	while(chars[k] != '\0'){
		T.ch[k] = chars[k];
		T.length++;
		k++;
	}	
}


void StrSopy(SString &T, SString S){
	/*
	copy from S to T;
	not test yet ...
	*/

	for(int i = 0;i < S.length; i++){
		T.ch[i] = S.ch[i];
	}
}


bool StrCompare(SString S, SString T){
	/*
	
	*/
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
	/*
		assign the S[pos] - [len -1] to sub
		equal to python "sub = S[pos:len]"
	*/
	for(int i = pos;i < pos + len;i++){
		sub.ch[i] = S.ch[i];
		sub.length++;
	}
}


void concat(SString &T, SString S1, SString S2){
	/*
	T = S1 + S2  
	not test yet ...
	*/
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
	/*
	whereis T in S
	*/
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


void get_next(int next[], char array[], int length){
	/*
	
	i:point to the next-update val in next[]

	next : next = {{ak} | k <- [0-n] }
			[-1] [0] [0 1 2 3] [1] [1 2 3 4 5]
					
					{ -1 , next[next[next]]	 = 1;
		next[i+1] = { next[i] + 1, array[i] = array[j] , j = next[i] + 1;
					{ 0 , others
	*/
	int i = 0 , j = -1;
	
	for(int i = 0;i < length; i++){
		next[i] = -1;
	}
	
	while(i < length){
		if(j == -1 || array[i] == array[j]){
				i++;
				j++;
				next[i] = j;
		}
		else{
			j = next[j];
		}
	}

}

bool kmp(SString S, SString T, int next[]){
	int i = 0, j = -1;

	while(i != S.length && j != T.length){
		if(j == -1 || S.ch[i] == T.ch[j]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}

	if(j == T.length){
		return true;
	}
	else{
		return false;
	}
}



//------------------------------------------


void test(SString S){
	for(int i = 0; i < S.length;i++){
		printf("%c ", S.ch[i]);
	}
	printf("\n");
}



//------------------------------------------







