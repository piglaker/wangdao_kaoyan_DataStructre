#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define MaxVertexNum 100
#define TOP 2147483647
#define MaxSize 100

typedef char VertexType;
typedef int EdgeType;

typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph, Graph;


typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;


bool Adjacent(MGraph G, int x,int y){
    /*

    */
    return true;
}


int Neighbors(MGraph G, int x){
    return 0;    
}

void InsertVertex(MGraph G,int x){

}


void DeleteVertex(MGraph G, int x){

}

int M = 6;

int N = 6;

void Convert(ALGraph &G, int arcs[M][N]){

}

int FisrtNeighbor(Graph G, int u){

    return 0;
}

int NextNeighbor(Graph G, int u, int w){
    return 0;
}


//---------------------------------------
typedef struct{
	int data[MaxSize];
	int front, rear;
	int tag;
}SqQueue;

bool EnQueue(SqQueue &Q, int x){
	if(Q.rear == MaxSize){
		Q.data[Q.rear] = x;
		Q.rear++;
		return true;
		}	
	return false;
}

bool DeQueue(SqQueue &Q, int &x){
	if(Q.front >= 0){
		x = Q.data[Q.front];
		Q.front++;
		return true;
		}
	else{
		return false;
		}
}

void InitQueue(SqQueue &Q){
	Q.front = 0;
	Q.rear = 0;
}

bool QueueEmpty(SqQueue &Q){
	if(Q.front == Q.rear){
		return true;
		}
	else{
		return false;
		}
}

SqQueue Q;

//-----------------------------------------

bool visited[MaxVertexNum];

void BFSSerch(Graph G){

}

void visit(int v){

}


int FisrtNeighbor(ALGraph G, int u){
    return 0;
}

int NextNeighbor(ALGraph G, int u, int w){

    return 0;
}


/*
//fake code ~

void BFS(Graph G, int v){
    visit(v);
    visited(v) = true;
    while(!QueueEmpty(G)){
        DeQueue(Q, v);
        for(int w = FisrtNeighbor(G, v);w > 0; w = NextNeighbor(G,v)){
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}
*/

int d[MaxVertexNum];

void BFS_MIN_Distance(Graph G, int u){
    for(int i = 0;i < G.vexnum;i++){
        d[i] = TOP;
    }
    InitQueue(Q);
    visited[u] = true; d[u] = 0;
    while(!QueueEmpty(Q)){
        DeQueue(Q, u);
        for(int w = FisrtNeighbor(G, u); w >= 0;w = NextNeighbor(G, u, w)){
            if(!visited[w]){
                visited[w] = true;
                d[w] = d[u] + 1;
                EnQueue(Q, w);
            }
        }
    }
}

void DFS(Graph G, int v){
    //visit(v);
    visited[v] = true;

    for(int w = FisrtNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}

void DFSTraverse(Graph G){
    for(int v = 0;  v < G.vexnum; v++){
        visited[v] = TOP;
    }
    for(int v = 0;v < G.vexnum; v++){
        if(!visited[v])DFS(G, v);
    }
}




bool isTree(Graph G){
    /*
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false;
    }
    int Vnum = 0, Enum = 0;

    DFS(G, 0, Vnum, Enum);

    if(Vnum == G.vexnum && Enum == V.num - 1){
        return true;
    }
    else{
        return false;
    }
    */
    return false;
}


void BFS(Graph& G, int v, int &Vnum, int &Enum, int visited[]){
    /*
    visited[v] = true;Vnum++;
    int w = FisrtNeighbor(G, v);
    while(w != 1){
        Enum++;
        if(!visited[w]){
            DFS(G, w, Vnum, Enum, visited);
        }
        w = NextNeighbor(G, v, w);
    }
    */
}


typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Push(SqStack &S, int x){
    if(S.top + 1 == MaxSize ){
        return false;
    }
    else{
        S.top++;
        S.data[S.top] = x;
        return true;
    }
}

bool Pop(SqStack &S, int &x){
    if(S.top == -1){
        return false;
    }
    else{    
    x = S.data[S.top];
    S.top--;
    return true;
    }
}

bool GetTop(SqStack S, int &x){
    if(S.top == -1){
        return false;
    }
    else{
        x = S.data[S.top];
        return true;
    }
}

void DestroyStack(SqStack &S){
    free(S.data);
    free(&S);
}

SqStack S;

void DFS_Non_RC(ALGraph &G, int v){
    int w;
    int k;
    InitStack(S);
    for(int i = 0;i < G.vexnum; i++){
        visited[i] = false;
    }

    Push(S, v);visited[v] = true;

    while(StackEmpty(S)){
        Pop(S, k);
        visit(k);
        for(int w = FisrtNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
            if(!visited[w]){
                Push(S, w);
                visited[w] = true;
            }
        }
    }
}


bool Exist_Path_DFS(ALGraph G, int i, int j){
    int p;
    if(i == j){
        return true;
    }
    else{
        visited[i] = true;
        for(p = FisrtNeighbor(G, i);p >= 0;p = NextNeighbor(G, i, p)){
            if(!visited[p] && Exist_Path_DFS(G, p, j)){
                return true;
            }

        }

    }
    return false;
}


/*
NEW WORLD!
*/

vector <int> g[MaxSize];

int n = 10;

vector < vector <int> > m(n, vector<int>(n, 0));

void FindPath(vector <int> g, int visited[], int target){
    
    
}



