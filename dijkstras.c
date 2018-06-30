#include<stdio.h>
#include<stdlib.h>
int cost[5][5]={{0,0,0,0,0},{0,999,15,35,40},{0,15,999,15,20},{0,35,15,999,10},{0,40,20,10,999}};
int nvert=4, visited[5]={0};

void dijshort(int dist[5], int src)
{
	int i,u, min, count=0;
	visited[src]=1;
	dist[src]=0;
	while(count<nvert-1)
	{
		min=999;
		for(i=1;i<nvert;i++)
			if(dist[i]<min && visited[i]!=1)
			{
				min=dist[i];
				u=i;

			}
			visited[u]=1;
			count++;

			for(i=1;i<nvert;i++)
			{
				if(dist[u]+cost[u][i]<dist[i] && visited[i]!=1)
					dist[i]=dist[u]+cost[u][i];
			}
	}
}

void initdist(int dist[5], int src)
{
	int i;
	for(i=1;i<nvert;i++)
	{
		dist[i]=cost[src][i];
	}
}

void print(int dist [5], int src)
{
	int i;
	for(i=1;i<=nvert;i++)
	{
		if(i!=src)
			printf("%d -> %d = %d", src, i, dist[i]);
	}
}

main()
{
int dist[5], src=1;
initdist(dist, src);
dijshort(dist, src);
print(dist, src);


}