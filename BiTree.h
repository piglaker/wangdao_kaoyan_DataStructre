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
	int tag = 0;
}SqQueue_bt;

SqQueue_bt Q;


void InitQueue_bt(SqQueue_bt &Q){
	Q.front = 0;
	Q.rear = 0;
}


bool QueueEmpty_bt(SqQueue_bt &Q){
	if(Q.front == Q.rear){
		return true;
		}
	else{
		return false;
		}
}


bool EnQueue_bt(SqQueue_bt &Q, BiTree x){
	if(Q.rear == MaxSize){
		Q.data[Q.rear] = x;
		Q.rear++;
		return true;
		}	
	return false;
}


bool DeQueue_bt(SqQueue_bt &Q, BiTree &x){
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
	InitQueue_bt(Q);
	BiTree p;
	EnQueue_bt(Q, T);
	while(!QueueEmpty_bt(Q)){
		DeQueue_bt(Q, p);	
		visit(p);
		if(p->lchild != NULL){
			EnQueue_bt(Q, p->lchild);
		}
		if(p->rchild != NULL){
			EnQueue_bt(Q, p->rchild);
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