//Hardik Aggarwal
//18CS10021
//Machine No-16

#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
int calc_hash(int x,int table_size)
{
	int sum=0;
	int y=x;
	while(y)
	{
		sum+=(y%10);
		y/=10;
	}
	return sum%table_size;

}
int search_(int x,int h,int table_size,int a[])
{
	int hash_val=calc_hash(x,table_size);
	for(int i=hash_val;i<hash_val+h;i++)
	{
		if(a[i%table_size]==x)
		{
			return i%table_size;
		}
	}
	return -1;
}
int insert_(int x,int h,int table_size,int a[],char** bitmaps)
{
	if(search_(x,h,table_size,a)!=-1)
		return 1;
	int hash_val=calc_hash(x,table_size);
	int j=-1;
	for(int i=hash_val;i<hash_val+table_size;i++)
	{
		if(a[i%table_size]==-1)
		{
			j=i%table_size;
			break;
		}
	}
	if(j==-1)
	{	
		return 2;
	}
	if((j-hash_val+table_size)%table_size<h)
	{
		a[j]=x;
		bitmaps[hash_val][(j-hash_val+table_size)%table_size]='1';
		return 1;
	}
	while((j-hash_val+table_size)%table_size>=h)
	{	
		int check=0;
		for(int i=j-h+1;i<j;i++)
		{
			if(calc_hash(a[(i+table_size)%table_size],table_size)>(j-h+table_size)%table_size)
			{	
				int temp=calc_hash(a[(i+table_size)%table_size],table_size);
				bitmaps[temp][(i-temp+2*table_size)%table_size]='0';
				bitmaps[temp][(j-temp+2*table_size)%table_size]='1';
				swap(a[j],a[(i+table_size)%table_size]);
				j=(i+table_size)%table_size;
				check=1;
				break;
			}
		}
		if(check==0)
		{
			return 3;
		}
	}
	bitmaps[hash_val][(j-hash_val+2*table_size)%table_size]='1';
	a[j]=x;
	return 1;


}
void delete_(int x,int h,int table_size,int a[],char** bitmaps)
{
	int hash_val=calc_hash(x,table_size);
	for(int i=hash_val;i<hash_val+h;i++)
	{
		if(a[i%table_size]==x)
		{
			a[i%table_size]=-1;
			bitmaps[hash_val][i-hash_val]='0';
			return ;
		}
	}
}

int main()
{	
	ifstream ip ("input.txt");
	ofstream op ("output.txt");
	int table_size;
	ip>>table_size;
	int h;
	ip>>h;
	int a[table_size];
	char s[MAX_SIZE];
	char** bitmaps;

		bitmaps=(char **)malloc(table_size*sizeof(char *));
		for(int i=0;i<table_size;i++)
		{
			bitmaps[i]=(char *)malloc(h*sizeof(char));
			for(int j=0;j<h;j++)
			{
				bitmaps[i][j]='0';
			}
		}	
		for(int i=0;i<table_size;i++)
		a[i]=-1;
	while(ip>>s)
	{	
		if(s=="\n")
			break;
		int n;
		ip>>n;
		if(strcmp(s,"in")==0)
		{
			for(int i=0;i<n;i++)
			{
				int x;
				ip>>x;
				int res=insert_(x,h,table_size,a,bitmaps);
				if(res==2)
				{
					op<<"NO SPACE AVAILABLE\n";
				}
				else if(res==3)
				{
					op<<"EXCEPTION FOUND\n";
				}
			}
			for(int i=0;i<table_size;i++)
			{
				if(a[i]!=-1)
				{
					op<<a[i]<<" ";
				}
			}
			op<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				int x;
				ip>>x;
				delete_(x,h,table_size,a,bitmaps);
			}
			for(int i=0;i<table_size;i++)
			{
				if(a[i]!=-1)
				{
					op<<a[i]<<" ";
				}
			}
			op<<endl;
		}
	}
	
	for(int i=0;i<table_size;i++)
	{
		op<<bitmaps[i]<<endl;
	}
}



