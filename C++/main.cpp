#include <stdio.h>
#include <malloc.h>
#define INF 32767				
#define	MAXV 100				
typedef char InfoType;
int visited[MAXV];

typedef struct
{	int no;						
	InfoType info;				
} VertexType;					
typedef struct
{	int edges[MAXV][MAXV];		
	int n,e;					
	VertexType vexs[MAXV];		
} MatGraph;						

//以下定义邻接表类型
typedef struct ANode
{	int adjvex;					
	struct ANode *nextarc;		
	int weight;					
} ArcNode;						
typedef struct Vnode
{	InfoType info;				
	int count;					
	ArcNode *firstarc;			
} VNode;						
typedef struct 
{	VNode adjlist[MAXV];		
	int n,e;					
} AdjGraph;						

void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e) 
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MatGraph g)	
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","∞");
		printf("\n");
	}
}

void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) 
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)						
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)						
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)	
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	
{
	ArcNode *p;
	for (int i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]→",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("∧\n");
	}
}
void DestroyAdj(AdjGraph *&G)	
{
	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)		
	{	pre=G->adjlist[i].firstarc;	
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						
}

void dfs(AdjGraph *G,int v){
	ArcNode *p;
	printf("%3d",v);visited[v]=1;
	p=G->adjlist[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex]==0) {
			dfs(G,p->adjvex);
		}
		p=p->nextarc;
	}
}

void bfs(AdjGraph *G,int v){
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;
	int visited[MAXV];
	int w,i;
	for(i=0;i<G->n;i++){
		visited[i]=0;
	}
	printf("%3d",v);
	visited[v]=1;
	rear=(rear+1)%MAXV;
	queue[rear]=v;
	while(front!=rear){
		front=(front+1)%MAXV;
		w=queue[front];
		p=G->adjlist[w].firstarc;
		while(p!=NULL){
			if(visited[p->adjvex]==0){
				printf("%3d",p->adjvex);
				visited[p->adjvex]=1;
				rear=(rear+1)%MAXV;
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;
		}
	}
	printf("\n");
}

int main()
{
	MatGraph g;
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	int n=6,e=10;			
	CreateMat(g,A,n,e);
	printf("(1)图G的邻接矩阵:\n");	DispMat(g);
	CreateAdj(G,A,n,e);
	printf("(2)图G的邻接表:\n"); DispAdj(G);
	printf("dfs\n");
	dfs(G,0);
	printf("\n");
	printf("bfs\n");
	bfs(G,4);
}