//18CS10021
//Hardik Aggarwal
//Machine 16
#include<bits/stdc++.h>
using namespace std;
typedef struct cell{
	int data;
	int rank;
	struct cell *parent;
}cell;

cell *makeset(int data)
{	
	cell *newset=new cell;
	newset->data=data;
	newset->parent=(newset);
	newset->rank=0;
	return newset;
}
cell *findset(cell *c)
{
	if((c->parent)==(c))
		return (c->parent);
	else
		//cout<<((*(c.parent).data));
		return (c->parent=findset(c->parent));
}
void unite1(cell *x,cell *y)
{
	cell *root1=(findset(x));
	cell *root2=(findset(y));
	if(root1==root2)
		return ;
	if(root1->rank<root2->rank)
	{
		root1->parent=root2;
	}
	else if(root1->rank>root2->rank)
	{
		root2->parent=root1;
	}
	else
	{
		root1->parent = (root2);
		(root2->rank)+=1;
	}

}
int main()
{
	ifstream ip ("input.txt");
	int n;
	ip>>n;
	cell *cells[n][n];
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ip>>a[i][j];
			
		}

	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cells[i][j]=makeset(a[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=n-1)
			{
				if(a[i][j]==1&&a[i][j+1]==1)
				{
					unite1(cells[i][j],cells[i][j+1]);
				}
				
			}
			if(i!=0)
			{
				if(a[i][j]==1&&a[i-1][j]==1)
					unite1(cells[i][j],cells[i-1][j]);
			}
		}
	}
	bool check=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[0][i]==1&&a[n-1][j]==1&&(findset(cells[0][i])==findset(cells[n-1][j])))
				{
					check=1;
					break;
				}
			}
	}
	if(check==1)
	{
		cout<<"Path_found\n";
	}
	else
		cout<<"Path not found\n";

}