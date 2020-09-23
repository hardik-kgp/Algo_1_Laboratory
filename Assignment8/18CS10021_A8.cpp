//Hardik Aggarwal
//18CS10021
//Machine - 16

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool isvalid(int i,int j,int n,int m)
{
	return ((i<n&&i>=0)&&(j<m&&j>=0));
}
void dfs(int i,int j,int** a,int n,int m,int **dp,int** visited)
{	
	visited[i][j]=true;
	dp[i][j]=1;
	if(isvalid(i+1,j,n,m)&&a[i+1][j]>a[i][j])
	{
		if(!visited[i+1][j])
		{
			dfs(i+1,j,a,n,m,dp,visited);
			
		}
		dp[i][j]=max(dp[i][j],dp[i+1][j]+1);
	}
	if(isvalid(i-1,j,n,m)&&a[i-1][j]>a[i][j])
	{
		if(!visited[i-1][j])
		{
			dfs(i-1,j,a,n,m,dp,visited);
			
		}
		dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
	}
	if(isvalid(i,j+1,n,m)&&a[i][j+1]>a[i][j])
	{
		if(!visited[i][j+1])
		{
			dfs(i,j+1,a,n,m,dp,visited);
			
		}
		dp[i][j]=max(dp[i][j],dp[i][j+1]+1);
	}
	if(isvalid(i,j-1,n,m)&&a[i][j-1]>a[i][j])
	{
		if(!visited[i][j-1])
		{
			dfs(i,j-1,a,n,m,dp,visited);
			
		}
		dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
	}

}
int part_1(int n,int m,int** a)
{
		int ans[n][m];
		ans[0][0]=1;
		for(int i=1;i<m;i++)
		{	
			if(ans[0][i-1]==-1)
			{
				ans[0][i]=-1;
			}
			else
			{
				if(a[0][i-1]<a[0][i])
					ans[0][i]=ans[0][i-1]+1;
				else
					ans[0][i]=-1;
			}
		}


		for(int i=1;i<n;i++)
		{	
			if(ans[i-1][0]==-1)
			{
				ans[i][0]=-1;
			}
			else
			{
				if(a[i-1][0]<a[i][0])
				
					ans[i][0]=ans[i-1][0]+1;
				
				else
					ans[0][i]=-1;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{	
				ans[i][j]=-1;
				if(a[i-1][j]<a[i][j])
					ans[i][j]=max(ans[i-1][j]+1,ans[i][j]);
				if(a[i][j-1]<a[i][j])
					ans[i][j]=max(ans[i][j-1]+1,ans[i][j]);
			}
		}
		int result=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ans[i][j]!=-1)
					result=max(result,ans[i][j]);
			}
		}
		return result;
}
int part_2(int n,int m,int** a)
{	
	int** visited;
	int** dp;
	dp=(int **)malloc(n*sizeof(int *));
	visited=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			dp[i]=(int *)malloc(m*sizeof(int));
			visited[i]=(int *)malloc(m*sizeof(int));
			for(int j=0;j<m;j++)
			{
				visited[i][j]=0;
			}
		}

	dfs(0,0,a,n,m,dp,visited);
	return dp[0][0];
}
int part_3(int n,int m,int** a)
{
	int** visited;
	int** dp;
	dp=(int **)malloc(n*sizeof(int *));
	visited=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			dp[i]=(int *)malloc(m*sizeof(int));
			visited[i]=(int *)malloc(m*sizeof(int));
			for(int j=0;j<m;j++)
			{
				visited[i][j]=0;
			}
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j])
				{
					dfs(i,j,a,n,m,dp,visited);				
				}
		}
	}
	
	int result=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			result=max(result,dp[i][j]);
		
	return result;
}
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int **a;
		a=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			a[i]=(int *)malloc(m*sizeof(int));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}

		cout<<part_1(n,m,a)<<" ";


		/***********************************************************************************************************/
		
		cout<<part_2(n,m,a)<<" ";


		/***********************************************************************************************************/
		
		cout<<part_3(n,m,a)<<endl;

	}
















}