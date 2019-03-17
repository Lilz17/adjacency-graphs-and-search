//implementing DFS on a graph represented by Adjacency Matrix
#include<stdio.h>
#include<stdlib.h>
int AM[10][10], V[10], visited[10], root, v;
void getAM()
{
    int a, b, sum=0;
	char ch;
	printf("How many vertices? ");
	scanf("%d", &v);
	printf("Enter the vertices: ");
	for(int i=0;i<v;i++) scanf("%d", &V[i]);
    root = V[0];
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			AM[i][j]=0;
	do
	{
		printf("Enter the edges in the form (a, b): ");
		scanf("%d %d", &a, &b);
		if(AM[a][b]==0)
		{
			AM[a][b]=1;
			AM[b][a]=1;
		}
		printf("Continue? y/n : ");
		scanf(" %c", &ch);
	}while(ch=='y');
	printf("\nThe given Adjacency Matrix is:\nX");
	for(int i=0;i<v;i++)
		printf("\t%d", V[i]);
	printf("\n");
	for(int i=0;i<v;i++)
	{
		printf("%d\t", V[i]);
		for(int j=0;j<v;j++)
			printf("%d\t", AM[i][j]);
		printf("\n");
	}
	printf("\n");
}
void DFS(int r)
{
    int j;
    visited[r]=1;
    printf("%d\t", r);
    for(j=0;j<v;j++)
    {
        if(AM[r][j]==1&&visited[j]==0)
            DFS(j);
    }
}
void main()
{
    printf("Input the adjacency matrix:\n");
    getAM();
    printf("Implementing Depth First Search:\nStarting from root vertex as %d\n", root);
    for(int i=0; i<v; i++) visited[i]=0;
    DFS(root);
}
