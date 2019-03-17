//to implement DFS on a graph represented by an Adjacency List
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int vertex;
	struct node *link;
};
struct node *AL[20];
int root = -1, visited[20], v;
void insert(int a, int b)
{
	struct node* sn = malloc(sizeof(struct node));
	struct node* dn = malloc(sizeof(struct node));
	sn->vertex = b; dn->vertex = a;
	if(AL[a]==NULL)
	{
		AL[a] = sn;
		sn->link = NULL;
	}
	else
	{
		sn->link = AL[a];
		AL[a] = sn;
	}
	if(AL[b]==NULL)
	{
		AL[b] = dn;
		dn->link = NULL;
	}
	else
	{
		dn->link = AL[b];
		AL[b] = dn;
	}
}
void display(int v)
{
	struct node *temp;
	for(int i=0; i<v; i++)
	{
		printf("%d", i);
		temp = AL[i];
		while(temp!=NULL)
		{
			printf("->%d", temp->vertex);
			temp = temp->link;
		}
		printf("\n");
	}
}
void getAL()
{
    int e, s, d;
	printf("Enter the number of edges: ");
	scanf("%d", &e);
	printf("Enter the number of vertices: ");
	scanf("%d", &v);
	for(int i=0;i<v;i++)
		AL[i] = NULL;
	for(int i=0;i<e;i++)
	{
		printf("Enter source and destination vertices (s, d): ");
		scanf("%d %d", &s, &d);
        if(root==-1) root = s;
		insert(s, d);
	}
	printf("Adjacency List:\n");
	display(v);
}
void DFS(int r)
{
    struct node *w;
    visited[r]=1;
    printf("%d\t", r);
    w = AL[r];
    while(w!=NULL)
    {
        if(visited[w->vertex]==0)
            DFS(w->vertex);
        w = w->link;
    }
}
void main()
{
    printf("Input the Adjacency List:\n");
    getAL();
    for(int i=0; i<v; i++) visited[i]=0;
    printf("Implementing Depth First Search on the given Adjacency List:\n");
    printf("Starting from root node as %d\n", root);
    DFS(root);
}
