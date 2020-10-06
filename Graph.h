#include <iostream>
#include <stdlib.h>

#define MaxVertexNum 100


typedef int EdgeType;

typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum];
    int vexnum, arcnum;
}MGraph;


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






