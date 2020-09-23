#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
#define INT_MIN -2147483647 - 1 // the minimum value  of integer type 
int suffix(int a[],int l,int r) //calculates the maximum sum suffix in an array
{	
	int sum=0;
	int maxi=INT_MIN;
	for(int i=r;i>=l;i--)
	{	
		sum+=a[i];
		maxi=max(maxi,sum);
	}
	return maxi;
}
int prefix(int a[],int l,int r)   //calculates the maximum sum prefix in the array
{	
	int sum=0;
	int maxi=INT_MIN;
	for(int i=l;i<=r;i++)
	{	
		sum+=a[i];
		maxi=max(maxi,sum);
	}
	return maxi;
}
int  Max_Cross_Seg (int a[],int l,int r) // calls prefix and suffix functions to calculate the maximum crossing subsegment
{
	return  suffix(a,l,(l+r)/2)+prefix(a,(l+r)/2+1,r);
}
int  Max_Seg (int a[],int l,int r)  // calculates the maximum subsegment sum in the array in range l to r
{	
	if(l>r)
	{
		return INT_MIN; 
	}
	if(r-l<=1)
	{
		if(r==l)
		{
			return a[l];
		}
		else
		{
			return max(a[l],max(a[r],a[l]+a[r]));
		}
	}

	int lefthalf= Max_Seg (a,l,(l+r)/2);
	int righthalf= Max_Seg (a,(l+r)/2+1,r);
	int cross_seg_max = Max_Cross_Seg (a,l,r); //
	int maxi=max(lefthalf,max(righthalf,cross_seg_max));
	return maxi;

}


int main()
{	
	int num;
	int a[100000],i;
	 ofstream op ("18CS10021_A3_P1_output.txt");
  
  ifstream myfile ("input.txt");
  if (myfile.is_open())// reading the input from the text file here a[0] denotes the  size of array 
  {	
    while ( myfile>>num )
    {
      a[i++]=num;
    }
    myfile.close();
  }

  op<<Max_Seg (a,1,a[0]);
  op.close();
/*	int n;
	cin>>n;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];

	}
	
	int maxsum= Max_Seg (a,1,n);
	cout<<maxsum<<endl;*/
}
