#include <iosrtream>
#include <stdlib.h>




typedef struct BiTNode{
	int data;
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


void PostOrder(BiTree Tˇ){
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


void LevelOrder(BiTree T){
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	while(!IsEmpty(Q)){
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
		if(pre != NULL && pre->child == NULL){
			pre->rchild = p;
			pre-rtag = 1;
		}
		pre->p;
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






