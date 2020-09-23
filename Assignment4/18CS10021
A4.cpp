#include<bits/stdc++.h>
using namespace std ;


typedef struct node{
	int vertex;
	struct node* next;
} node;


typedef struct Graph{
	int numvertices;
	struct node** adjlists;
}Graph;

typedef struct Edge{
	int to,from,weight;
}Edge;

void merge(Edge e[],int l,int r)
{
	Edge b[r-l+5],c[r-l+5];
	int mid=(l+r)/2;

	for(int i=l;i<=mid;i++)
	{
		b[i-l]=e[i];
	}
	for(int i=mid+1;i<=r;i++)
		c[i-mid-1]=e[i];

	int i=0,j=0,k=l,n1=mid-l+1,n2=r-mid;

	while(i<n1&&j<n2)
	{
		if(b[i].from==c[j].from)
		{	
			if(b[i].weight==c[j].weight)
			{
				if(b[i].to<c[j].to)
					e[k++]=b[i++];
				else
					e[k++]=c[j++];
			}
			else if(b[i].weight<c[j].weight)
			{
				e[k++]=b[i++];
			}
			else 
				e[k++]=c[j++];
		}
		else if(b[i].from<c[j].from)
			e[k++]=b[i++];
		else
			e[k++]=c[j++];

	}


	while(i<n1)
		e[k++]=b[i++];
	while(j<n2)
		e[k++]=c[j++];
}
void mergesort(Edge e[],int l,int r)
{	
	if(l>=r)
		return ;

	int mid=(l+r)/2;
	Edge b[mid+2],c[mid+2];
	mergesort(e,l,mid);
	mergesort(e,mid+1,r);
	merge(e,l,r);

}

void solve()
{	

	int num;
	int inp[100000],it=0;
	 ofstream op ("18CS10021_A4_output.txt");
  
  ifstream myfile ("input.txt");
  


	int n,m;
	it=0;
	myfile>>n>>m;
	Graph g;
	g.numvertices=n;
	node *a[n+1];
	g.adjlists=a;
	int u[m+1]={0},v[m+1]={0},in[n+1]={0};

	for(int i=1;i<=n;i++)
		g.adjlists[i]=NULL;
	for(int i=0;i<m;i++)
	{
		myfile>>u[i]>>v[i];
		node *newn =(node *)malloc(sizeof(node *));
		newn->vertex=v[i];
		newn->next=g.adjlists[u[i]];
		g.adjlists[u[i]]=newn;
	}
	int x=1;
	Edge e[m+5];
	for(int i=1;i<=n;i++)
	{
		while(g.adjlists[i]!=NULL)
		{	
			e[x].from=i;
			e[x].to=g.adjlists[i]->vertex;
			in[e[x].to]++;
			x++;
			g.adjlists[i]=g.adjlists[i]->next;
		}
	}

	
	for(int i=1;i<=m;i++)
	{
		e[i].weight=in[e[i].to]+in[e[i].from];
	}


	mergesort(e,1,m);

	for(int i=1;i<=m;i++)
		op<<e[i].from<<" "<<e[i].weight<<" "<<e[i].to<<'\n';
	op.close();
	myfile.close();


}





int main()
{
	solve();
}