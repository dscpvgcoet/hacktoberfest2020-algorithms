#include<stdio.h>
#include<math.h>
#define MAX 10
#define INF 999
int adjmat[MAX][MAX],path[MAX],n;
struct Bmat
{
	int B[MAX][MAX];
	int cost;
};
void printmat(int mat[MAX][MAX]);
int searchmin(int i,int j,int flag,int mat[MAX][MAX]);
int perred(int row[10], int col[10],int mat[MAX][MAX],int flag);
int checkred(int mat[MAX][MAX]);
int checknode(int p,int v);
int makemat(int src[MAX][MAX],int dest[MAX][MAX],int nv,int v);
struct Bmat interm(int v,int snm[MAX][MAX],int cr);
int tsp();
void main()
{
	int i,j,k;
	printf("enter the no of nodes in graph\n");
	scanf("%d",&n);
	printf("enter the Cost matrix enter 999 if no edge is present\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adjmat[i][j]);
		}
	}
	tsp();
}
void printmat(int mat[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int searchmin(int i,int j,int flag,int mat[MAX][MAX])
{
	int x,y,z,min;
	if(flag==1)
	{
		min=mat[j][0];
		for(x=0;x<i;x++)
		{
			if(min>mat[j][x])
			min=mat[j][x];
		}
		return min;
	}
	else
	{
		min=mat[0][j];
		for(x=0;x<i;x++)
		{
			if(min>mat[x][j])
			min=mat[x][j];
		}
		return min;
	}
}
int perred(int row[10], int col[10],int mat[MAX][MAX],int flag)
{
	int i,j,k,redrow[10],redcol[10],sum=0;
	for(i=0;i<n;i++)
	{
		redrow[i]=0;
		redcol[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(row[i]!=0&&flag==1)
		{
			redrow[i]=searchmin(n,i,flag,mat);
			for(j=0;j<n;j++)
			{
				if(mat[i][j]!=999)
				mat[i][j]=mat[i][j]-redrow[i];
			}
			if(redrow[i]!=999)
			sum=sum+redrow[i];
		}	
		if(col[i]!=0&&flag==0)
		{
			redcol[i]=searchmin(n,i,flag,mat);
			for(j=0;j<n;j++)
			{
				if(mat[j][i]!=999)
				mat[j][i]=mat[j][i]-redcol[i];
			}
			if(redcol[i]!=999)
			sum=sum+redcol[i];
		}
		
	}
	return sum;
}
int checkred(int mat[MAX][MAX])
{
	int i,j,row[10],col[10],sum=0,k;
	for(i=0;i<n;i++)
	{
		row[i]=-1;
		col[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==0)	
			{
				row[i]=0;
			}
		}
	}
	k=1;
	for(i=0;i<n;i++)
	{
		if(row[i]!=0)
		{
			sum=perred(row,col,mat,k);
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==0)	
			{
				col[j]=0;
			}
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(col[i]!=0)
		{
			sum+=perred(row,col,mat,k);
			break;
		}
	}
	printf("\nreduced matrix is:\n");
	printmat(mat);
	return sum;
}
int checknode(int p,int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(p==path[i])
		return 0;
	}
	return 1;
}
int makemat(int src[MAX][MAX],int dest[MAX][MAX],int nv,int v)
{
	int i,j,k=0;
	for(i=0;i<n;i++)
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			dest[i][j]=src[i][j];
		}
	}
	while(k<v)
	{
		i=path[k];
		for(j=0;j<n;j++)
		{
			dest[i][j]=999;
			if(path[k+1]!=-1)
			dest[j][path[k+1]]=999;
			dest[j][nv]=999;
			dest[i][0]=999;
			dest[nv][0]=999;
		}
		k++;
	}
}
struct Bmat interm(int v,int snm[MAX][MAX],int cr)
{
	int i,j=0,min,k,cost[MAX][2],r,c;
	struct Bmat inm[MAX];
	int nv[MAX];
	for(i=0;i<n;i++)
	{
		if(checknode(i,v))
		{
			nv[j]=i;
			j++;
		}
	}
	for(i=0;i<n-v;i++)
	{
		r=0;
		if(v==1)
		makemat(adjmat,inm[nv[i]].B,nv[i],v);
		else
		makemat(snm,inm[nv[i]].B,nv[i],v);
		r=checkred(inm[nv[i]].B);
		cost[i][0]=cr + adjmat[path[v-1]][nv[i]]+r; 
		cost[i][1]=nv[i];
	}
	min=cost[0][0];
	k=cost[0][1];
	for(i=1;i<n-v;i++)
	{
		if(min>cost[i][0])
		{
			min=cost[i][0];
			
			k=cost[i][1];
		}
	}
	for(i=0;i<n-v;i++)
	{
		printf("cost %d node %d\t",cost[i][0],cost[i][1]);
	}
	for(i=0;i<n-v;i++)
	{
		if(min==cost[i][0])
		c=cost[i][1];
	}
	printf("\nthe min among node is %d and cost is %d",c,min);
	printf("\nso we expand node %d:\n",c);
	printf("\n");
	inm[k].cost=min;
	path[v]=k;
	return inm[k];
}
int tsp()
{
	int i,cr;
	struct Bmat snm;
	cr=checkred(adjmat);
	printf("Initial cost is :%d\n",cr);
	path[0]=0;
	for(i=1;i<n;i++)
	{
		path[i]=-1;
	}
	for(i=1;i<n;i++)
	{
		snm=interm(i,snm.B,cr);
		cr=snm.cost;
	}
	path[n]=0;
	for(i=0;i<=n;i++)
	printf("%d->",path[i]); 
	printf("\n");
}
/*
OUTPUT:
enter the no of nodes in graph
4
enter the Cost matrix enter 999 if no edge is present
999 10 5 4
10 999 2 3
5 2 999 1
4 3 1 999

reduced matrix is:
999	5	1	0	
5	999	0	1	
1	0	999	0	
0	1	0	999	

Initial cost is :12

reduced matrix is:
999	999	999	999	
999	999	0	1	
1	999	999	0	
0	999	0	999	


reduced matrix is:
999	999	999	999	
4	999	999	0	
999	0	999	0	
0	1	999	999	


reduced matrix is:
999	999	999	999	
4	999	0	999	
0	0	999	999	
999	1	0	999	

cost 17 node 1	cost 14 node 2	cost 13 node 3	
the min among node is 3 and cost is 13
so we expand node 3:


reduced matrix is:
999	999	999	999	
999	999	0	999	
0	999	999	999	
999	999	999	999	


reduced matrix is:
999	999	999	999	
0	999	999	999	
999	0	999	999	
999	999	999	999	

cost 14 node 1	cost 17 node 2	
the min among node is 1 and cost is 14
so we expand node 1:


reduced matrix is:
999	999	999	999	
999	999	999	999	
999	999	999	999	
999	999	999	999	

cost 14 node 2	
the min among node is 2 and cost is 14
so we expand node 2:

0->3->1->2->0->
*/
