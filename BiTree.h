#include "SqStack.h"


typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void visit(BiTree T){
	printf("%d\n", T->data);
}


void PreOrder(BiTree T){
	if(T!= NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}


void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}


void PostOrder(BiTree T){
	if(T!= NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


void PreOrder_SE(BiTree T){
	//
}

void InOrder_SE(BiTree T){
	//
}


void PostOrder_SE(BiTree T){
	//
}



typedef struct{
	BiTree data[MaxSize];
	int front, rear;
	int tag;
}SqQueue_bt;

SqQueue_bt Q;

typedef struct{
    BiTree data[MaxSize];
    int top;
}SqStack_bt;



void InitStack(SqStack_bt &S){
    S.top = -1;
}

bool StackEmpty(SqStack_bt S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Push(SqStack_bt &S, BiTree x){
    if(S.top + 1 == MaxSize ){
        return false;
    }
    else{
        S.top++;
        S.data[S.top] = x;
        return true;
    }
}


bool Pop(SqStack_bt &S, BiTree &x){
    if(S.top == -1){
        return false;
    }
    else{    
    x = S.data[S.top];
    S.top--;
    return true;
    }
}


bool GetTop(SqStack_bt S, BiTree &x){
    if(S.top == -1){
        return false;
    }
    else{
        x = S.data[S.top];
        return true;
    }
}


void DestroyStack(SqStack_bt &S){
    free(S.data);
    free(&S);
}


void InitQueue(SqQueue_bt &Q){
	Q.front = 0;
	Q.rear = 0;
}


bool QueueEmpty(SqQueue_bt &Q){
	if(Q.front == Q.rear){
		return true;
		}
	else{
		return false;
		}
}


bool EnQueue(SqQueue_bt &Q, BiTree x){
	if(Q.rear == MaxSize){
		Q.data[Q.rear] = x;
		Q.rear++;
		return true;
		}	
	return false;
}


bool DeQueue(SqQueue_bt &Q, BiTree &x){
	if(Q.front >= 0){
		x = Q.data[Q.front];
		Q.front++;
		return true;
		}
	else{
		return false;
		}
}


void LevelOrder(BiTree T){
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	while(!QueueEmpty(Q)){
		DeQueue(Q, p);	
		visit(p);
		if(p->lchild != NULL){
			EnQueue(Q, p->lchild);
		}
		if(p->rchild != NULL){
			EnQueue(Q, p->rchild);
		}
	}	
}


typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;


void InThread(ThreadTree &p, ThreadTree &pre){
	if(p != NULL){
		InThread(p->lchild, pre);
		if( p->lchild == NULL){
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL && pre->rchild == NULL){
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}


void CreateThread(ThreadTree T){
	ThreadTree pre = NULL;
	if(T!=NULL){
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

SqStack_bt S;

void PostOrder_no(BiTree T){
	InitStack(S);
	BiTree p = T;
	BiTree r = NULL;
	while( p || StackEmpty(S)){
		if(p){
			Push(S, p);
			p = p->lchild;
		}
		else{
			GetTop(S, p);
			if(p->rchild && p->rchild != r){
				p = p->rchild;
				Push(S, p);
				p = p->lchild;
			}
			else{
				Pop(S, p);
				visit(p);
				r = p;
				p = NULL;
			}
		}
	}
}


void InvertLevel(BiTree bt){
	SqStack_bt s; SqQueue_bt Q;
	BiTree p;
	if(bt != NULL){
		InitStack(S);
		InitQueue(Q);
		EnQueue(Q, bt);
		while(QueueEmpty(Q) != false){
			DeQueue(Q, p);
			Push(s, p);
			if(p->lchild){
				EnQueue(Q, p->lchild);
			}
			if(p->rchild){
				EnQueue(Q, p->rchild);
			}
		}
	
		while (StackEmpty(s) != false){
			Pop(s, p);
			visit(p);
		}
	}
}


int Btdepth(BiTree T){
	if(!T){
		return 0;
	}

	int front = -1, rear = -1;

	int last = 0, level = 0;

	BiTree Q[MaxSize];

	BiTree p;

	Q[++rear] = T;

	while(front < rear){
		p = Q[++front];
		if(p->lchild){
			Q[++rear] = p->lchild;
		}
		if(p->rchild){
			Q[++rear] = p->rchild;
		}
		if(front == last){
			level++;
			last = rear;
		}
	}
	return level;
}


int Btdepth2(BiTree T){
	if(T == NULL){
		return 0;
	}
	int ldep = Btdepth2(T->lchild);

	int rdep = Btdepth2(T->rchild);

	return (ldep > rdep) ? (ldep + 1) : (rdep + 1);
}

int num_of_nodes = 8;

BiTree get_node(int val){
	BiTNode *node = (BiTNode *)malloc(sizeof(BiTNode));
	node->data = val;
	return node;
}


BiTree build_BT_from_Pre_In(int pre[], int in[], int pre_0, int pre_end, int in_0, int in_end){
	pre_0 = 0;
	in_0 = 0;
	pre_end = num_of_nodes;
	in_end = num_of_nodes;	

	BiTNode *root = get_node(pre[pre_0]);

	int i;

	for(i = in_0;i != pre[pre_0];i++);

	int llen = i - in_0;

	int rlen = in_end - i;

	if(llen != 0)
		root->lchild = build_BT_from_Pre_In(pre, in, pre_0+1, pre_0 + llen, in_0, in_0 + llen - 1);
	else
		root->lchild = NULL;
	
	if(rlen != 0)
		root->rchild = build_BT_from_Pre_In(pre, in, pre_end - rlen + 1, pre_end, in_end - rlen + 1, in_end);
	else
		root->rchild = NULL;

	return root;	
}


bool is_complete_BT(BiTree T){
	InitQueue(Q);

	if(!T)
		return 1;
	
	EnQueue(Q, T);

	BiTree p;

	while(!QueueEmpty(Q)){
		DeQueue(Q, p);
		if(p){
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else{
			while(!QueueEmpty(Q)){
				DeQueue(Q, p);
				if(p){
					return false;
				}
			}
		}

	}

	return true;
}



int count_full_node(BiTree T){
	InitQueue(Q);
	BiTree p;

	EnQueue(Q, T);

	int count = 0;

	while(!QueueEmpty(Q)){
		DeQueue(Q, p);
		if(p){
			if(p->lchild && p->lchild){
				count++;
			}
		}
		if(p->lchild){
			EnQueue(Q,p->lchild);
		}
		if(p->rchild){
			EnQueue(Q, p->rchild);
		}
	}
	return count;
}


void swap(BiTree &T){
	BiTree tmp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = tmp;
}


void Mirror(BiTree &T){
	Mirror(T->lchild);
	Mirror(T->rchild);
	swap(T);
}


void PreOrder_k(BiTree T, int k){
	while(T!=NULL){
		if(k==0){
			visit(T);
		}
		PreOrder_k(T->lchild, k-1);
		PreOrder_k(T->rchild, k-1);
	}
}

SqQueue_bt to_free;



void free_x_in_tree(BiTree T, char x){
	InitQueue(to_free);

	InitQueue(Q);

	BiTree p;

	EnQueue(Q, T);

	while(!QueueEmpty(Q)){
		DeQueue(Q, p);
		if(p->data == x){
			EnQueue(to_free, p);
		}
		if(p->lchild){
			EnQueue(Q, p->lchild);
		}
		if(p->rchild){
			EnQueue(Q, p->rchild);
		}
	}

	while(!QueueEmpty(to_free)){
		DeQueue(Q, p);
		if(p->lchild){
			EnQueue(to_free, p->lchild);
		}
		if(p->rchild){
			EnQueue(to_free, p->rchild);
		}
		free(p);
	}
}


typedef struct{
	BiTree t;
	int tag;
}stack;

stack s[20];

int top;

void visit_father_x(BiTree T, char x){
	top = 0 ;
	
	while(T != NULL || top >0){
		while(T != NULL && T->data != x){
			s[++top].t = T;
			s[top].tag = 0;
			T = T->lchild;
		}
		if(T->data == x){
			printf("get it !");
			for(int i = 0; i <= top;i++){
				printf("%d", s[i].t->data);
				exit(1);
			}
		}
		while(top != 0 && s[top].tag == 1){
			top--;
		}
		if(top != 0){
			s[top].tag = 1;
			T = s[top].t->rchild;
		}
	}
}



SqQueue_bt Qu;


void free_SqQueue(SqQueue_bt &Q){
	BiTree p;
	while(!QueueEmpty(Q)){
		DeQueue(Q, p);
	}
}


void SqQueue_DeepCopy(SqQueue_bt &Q0, SqQueue_bt &Q1){
	BiTree tmp_copy;
	while(!QueueEmpty(Q)){
		DeQueue(Q0, tmp_copy);
		EnQueue(Q1, tmp_copy);
	}
}


int BTWidth(BiTree b){

	int count = 0;

	int max = 0;

	BiTree p;
	
	InitQueue(Qu);
	
	EnQueue(Qu, b);

	SqQueue_bt next_Queue;

	InitQueue(next_Queue);

	while(!QueueEmpty(Qu)){
		DeQueue(Qu, p);
		
		count++;
		
		if(p){
			if(p->lchild){
				EnQueue(next_Queue, p->lchild);
			}
			if(p->rchild){
				EnQueue(next_Queue, p->rchild);
			}
		}
		else{
			if(count > max){
				max = count;
				count = 0;
			}
			SqQueue_DeepCopy(next_Queue, Qu);
		}
	}
	return max;
}




void pre2post_fullBT(int pre[], int l1, int h1, int post[], int l2, int h2){
	int half;
	if(h1 >= h2){
		post[h2] = pre[l1];
		pre2post_fullBT(pre, l1+1, h1/2, post, l2, h2/2);
		pre2post_fullBT(pre, h2/2, h2, post, h2/2, h2);
	}
}


typedef struct LinkedNode_bt{
	BiTree data;
	struct LinkedNode_bt *next;
}LinkedNode_bt, *LinkList_bt;

SqQueue_bt Q16;

LinkList_bt BiTree2LinkList(BiTree T){
	
	LinkList_bt head = new LinkedNode_bt;

	LinkList_bt p = head;

	InitQueue(Q16);

	EnQueue(Q16, T);

	BiTree tmp_node;

	while(!QueueEmpty(Q16)){
		
		DeQueue(Q16, tmp_node);

		LinkList_bt new_node = new LinkedNode_bt;

		new_node->data = tmp_node;

		p->next = new_node;

		p = new_node;

		if(tmp_node){
			if(tmp_node->lchild){
				EnQueue(Q16, tmp_node->lchild);
			}
			if(tmp_node->rchild){
				EnQueue(Q16, tmp_node->rchild);
			}
		}
	}

	return head;
}


bool if_similar(BiTree A, BiTree B){

	if( ((A) ? 1:0) ^ ((B) ? 1:0)){
		return false;
	}

	bool lf = ((A->lchild) ? 1:0 )^ ((B->lchild) ? 1:0);
	
	bool rf = ((A->rchild) ? 1:0) ^ ((B->rchild) ? 1:0);

	if(!lf && !rf){
		return if_similar(A->lchild, B->lchild) && if_similar(A->rchild, B->rchild);
	}
	else{
		return false;
	}
}


//18:pass

typedef struct weighted_BiTNode{
	int weight;
	struct weighted_BiTNode *lchild, *rchild;
}weighted_BiTNode, *weighted_BiTree;

int depth = 0;

int get_WPL(weighted_BiTree root){
	if(!root){
		return 0;
	}
	int k = root->weight;
	depth++;
	return k + get_WPL(root->lchild) * depth + get_WPL(root->rchild) * depth;
}


void BtreeToExp(BiTree root, int deep){
	if(root==NULL)return;
	else if(root->lchild == NULL && root ->rchild == NULL)
		printf("%c", root->data);
	else{
		if(deep>1)printf("(");
		BtreeToExp(root->lchild, deep+1);
		printf("%c", root->data);
		BtreeToExp(root->lchild, deep + 1);
		if(deep > 1)printf(")");
	}
}


void BtreeToE(BiTree root){
	BtreeToExp(root, 1);
}

typedef struct{
	int data;
	int parent;
}PTNode;


typedef struct{
	PTNode nodes[MaxSize];
	int n;
}PTree;


typedef struct{
	int data;
	struct CSNode *firstchild, *nextsibing;
}CSNode, *CSTree;

#define size 100;

int UFSets[MaxSize];

void Initial(int S[]){
	for(int i = 0;i<size;i++){
		S[i] = -1;
	}
}

int Find(int S[], int x){
	while(S[x] > 0){
		x = S[x];
	}
	return x;
}

void Union(int S[], int Root1, int Root2){
	S[Root2] = Root1;
}








