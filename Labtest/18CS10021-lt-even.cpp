//Hardik Aggarwal
//18CS10021
//Machine No: 16
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
/*
	I am using the efficient Way:
	I am using Dynamic programming solution.
*/



/******************************************************************************************************/
/*
	So here goes my dynamic programming approach for the problem
	Firstly I made a dp table of size n*K 
	now dp[i][j] stores the the maximum possible profit using atmost k moves in the range a[i...n] and necessarily including the ith element;

	So our final answer is maximum of 0,and all dp[i][k] as i varies from 1 to n;
	now if we necessarily include the ith elemnt I have the choice to choose any r between between i+1 to n
	So we will iterate our r pointer keeping l fixed as I and try to make a transaction {l,r} .
	Now we can do atmost k-1 transactions and are allowed to do it n range r+1 to n;
	so we will add the opimal answer of dp[r+1][k-1] to our current dp state .

	So our recurrance relation goes as follows:
	dp[i][k]=maximum of(dp[i][k],-a[i]+a[r]+dp[r+1][k-1]) as r varies from i+1 to n (for r!=n)

	dp[i][k]=maximum of(dp[i][k],-a[i]+a[r]+0) (for r=n)

	Also to avoid necessarily including kth move I am taking maximum with dp[i][k-1] as well.

	Time comlexity:
	my k varies from 1 to K
	the innerloops run atmost n*n times

	Hence the time complexity : O(n*n*k);

*/
int main()
{
	ofstream op ("18CS10021-lt-output.txt");
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int K;
	cin>>K;
	int dp[n+1][K+1];
	/*Initialising the dp table */
	for(int i=0;i<=n;i++)
	{
		for(int k=0;k<=K;k++)
		{
			dp[i][k]=0;
		}
		
	}
	/*Calculating the value of dp table */
	for(int k=1;k<=K;k++)//varying the k 
	{
		for(int i=1;i<=n;i++)//moving the left pointer
		{
			for(int r=i+1;r<=n;r++)//moving the right pointer
				{	
					if(r!=n)
						dp[i][k]=max(dp[i][k],-a[i]+a[r]+dp[r+1][k-1]);//recurrace relation
					else
						dp[i][k]=max(dp[i][k],-a[i]+a[r]);
				}
			dp[i][k]=max(dp[i][k],dp[i][k-1]);
		}
	}
	int ans=0;
	//Calculating the final answer by taking maximum across all the left pointers.
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[i][K],ans);
	}
	
	op<<ans<<endl;
}