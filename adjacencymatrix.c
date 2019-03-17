//representing graph using adjacency matrix
#include<stdio.h>
void main()
{
	int v, AM[10][10], a, b, sum=0;
	char V[10], ch;
	printf("How many vertices? ");
	scanf("%d", &v);
	printf("Enter the vertices: ");
	for(int i=0;i<v;i++) scanf(" %c", &V[i]);
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
	printf("\nThe given Adjacency Matrix is:\n");
	for(int i=0;i<v;i++)
		printf("\t%c", V[i]);
	printf("\n");
	for(int i=0;i<v;i++)
	{
		printf("%c\t", V[i]);
		for(int j=0;j<v;j++)
			printf("%d\t", AM[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("Degree of each vertex:\n");
	for(int i=0;i<v;i++)
	{
		sum=0;
		for(int j=0;j<v;j++) sum+=AM[i][j];
		printf("%c: %d\n", V[i], sum);
	}
	printf("\n");
}
