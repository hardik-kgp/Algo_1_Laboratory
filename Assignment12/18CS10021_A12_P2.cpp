//18CS10021
//Hardik Aggarwal
//Machine No-16

#include<bits/stdc++.h>
using namespace std;
typedef struct job{
	int jobid;
	int bursttime;
	int arrivaltime;
	int priority;
	int startime;
	int endtime;
	int cputime;
} job;
bool comp(job a,job b)
{
	if(a.bursttime==b.bursttime)
	{
		return (a.jobid<b.jobid);
	}
	return (a.bursttime<b.bursttime);
}

void heapify(int xx,int i,job **h,int size[])
{
	int smallest=i;	
	int l=(2*i);
	int r=2*i+1;
	if(l<size[xx]&&comp(h[xx][smallest],h[xx][l])==0)
	{
		smallest=l;
	}
	if(r<size[xx]&&comp(h[xx][smallest],h[xx][r])==0)
	{
		smallest=r;
	}
	if(smallest!=i)
	{	
		swap(h[xx][i],h[xx][smallest]);
		heapify(xx,smallest,h,size);
	}
}
job getmin(int xx,job **h,int size[])
{
	return h[xx][1];
}
job extract_min(int xx,job **h,int size[])
{
	job root=h[xx][1];
	swap(h[xx][size[xx]],h[xx][1]);
	size[xx]--;
	heapify(xx,1,h,size);
	return root;
}
void insert(int xx,job jj,job **h,int size[])
{	
	size[xx]++;
	int i = size[xx];
	h[xx][i]=jj;
	int parent=i/2;
	while(parent!=0&&comp(h[xx][i],h[xx][parent]))
	{
		swap(h[xx][i],h[xx][parent]);
		i=i/2;
		parent=i/2;
	}
}
void check_for_ageing(int xx,int t,job **h,int size[],int now_job)
{
	for(int i=1;i<=size[xx];i++)
	{	
		
		if(t-h[xx][i].cputime>=20&&h[xx][i].jobid!=now_job)
		{	
			//cout<<h[xx][i].jobid<<" "<<h[xx][i].cputime<<" "<<t<<" "<<xx<<" \n";	
			h[xx][i].priority--;
			//cout<<"removed "<<h[xx][i].jobid<<endl;
			insert(h[xx][i].priority,h[xx][i],h,size);
			swap(h[xx][i],h[xx][size[xx]]);
			heapify(xx,i,h,size);
			i=0;
			size[xx]--;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	job **h;
	h=(job **)malloc(6*sizeof(job *));
		for(int i=0;i<6;i++)
		{
			h[i]=(job *)malloc((n+1)*sizeof(job));
		}	
	int size[6]={0};
	job ji[n+2];
	for(int i=1;i<=n;i++)
	{
		cin>>ji[i].jobid>>ji[i].arrivaltime>>ji[i].bursttime>>ji[i].priority;
		ji[i].startime=-1;
	}
	int curr=1;
	int now_job=-1;
	for(int t=0;;t++)
	{	
		if(t!=0&&t%20==0)
		{
			for(int j=2;j<=5;j++)
			{
				check_for_ageing(j,t,h,size,now_job);
			}	
		}
		if(now_job!=-1&&ji[now_job].bursttime==0)
		{	

			ji[now_job].endtime=t;
			now_job=-1;
		}
		while(curr<=n&&ji[curr].arrivaltime==t)
		{	
			ji[curr].cputime=t;
			insert(ji[curr].priority,ji[curr],h,size);
			
			curr++;
		}
		if(now_job==-1)
		{	
			int xx=1;
			while(xx<6&&size[xx]==0)
			{
				xx++;
			}
			//cout<<xx<<endl;
			if(xx!=6)
			{
				job job_found=extract_min(xx,h,size);
				//cout<<"jobid "<<job_found.jobid<<"time "<<t<<" "<<endl;
				now_job=job_found.jobid;
				if(ji[now_job].startime==-1)
					ji[now_job].startime=t;
				ji[now_job].cputime=t;
			}
		}
		else
		{
			int xx=1;
			while(xx<=ji[now_job].priority&&size[xx]==0)
			{
				xx++;
			}
			if(xx<=ji[now_job].priority)
			{	
				ji[now_job].cputime=t;
				insert(ji[now_job].priority,ji[now_job],h,size);
				job job_found=extract_min(xx,h,size);
				
				now_job=job_found.jobid;
				if(ji[now_job].startime==-1)
					ji[now_job].startime=t;
				ji[now_job].cputime=t;
			}
		}
		if(now_job!=-1)
		{	
			ji[now_job].bursttime--;
		}
		if(curr==n+1&&now_job==-1)
		{
			break;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<ji[i].startime<<" "<<ji[i].endtime<<endl;
	}
}
