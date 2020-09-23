//18CS10021
//Hardik Aggarwal
//Machine 16
#include<bits/stdc++.h>
using namespace std;
typedef struct coordinate{
	int x,y;
}coordinate;
typedef struct cell{
	int data;
	int rank;
	struct cell *parent;
	coordinate point;
}cell;

cell *makeset(int data,int x,int y)
{	
	cell *newset=new cell;
	(newset->point).x=x;
	(newset->point).y=y;
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
		return (findset(c->parent));
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
void print_path(cell *temp)
{
	if((temp->parent)==temp)
	{
		cout<<((temp->point).x)<<" "<<((temp->point).y)<<endl;
		return ;
	}
	print_path(temp->parent);
	cout<<((temp->point).x)<<" "<<((temp->point).y)<<endl;
		return ;
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
			cells[i][j]=makeset(a[i][j],i,j);
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
	int col1=0,col2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[0][i]==1&&a[n-1][j]==1&&(findset(cells[0][i])==findset(cells[n-1][j])))
				{
					check=1;
					col1=i;
					col2=j;
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

	if(check==1)
	{	
		int i=n-1,j=col2;
		cout<<"The path is"<<endl;
		cell *temp=cells[i][j];
		print_path(temp);

	}

	
}