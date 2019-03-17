//Representing graph using Adjacency List
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int vertex;
	struct node *link;
};
struct node *AL[20];		//array of pointers to node
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
	int degree;
	for(int i=0; i<v; i++)
	{
		degree = 0;
		printf("%d", i);
		temp = AL[i];
		while(temp!=NULL)
		{
			degree++;
			printf("->%d", temp->vertex);
			temp = temp->link;
		}
		printf("\nDegree of node %d: %d\n", i, degree);
	}
}
void main()
{
	int e, s, d, v;
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
		insert(s, d);
	}
	printf("Adjacency List:\n");
	display(v);
}
