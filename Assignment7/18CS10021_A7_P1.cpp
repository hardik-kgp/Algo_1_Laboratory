//18CS10021
//Hardik Aggarwal
//Machine No:16

#include<fstream>
#include<stdio.h>

using namespace std;



//This function returns the minimum number of trials for k avilable capsules and n available beakers

int func(int k,int n)
{	

	/*Base Cases : 
	When k==1 we have only one capsule so we should check for all the available beakers so number of trials are n 

	when n is 0 so we donot have any beaker so number of trials is 0*/
	if(k==1)
	{
		return n;
	}
	else if(n==0)
		return 0;
	
	/*Now we have the the recursion. Suppose we have to check between n given beakers with k available capsules 
	So we can take the first capsule and put it in any of the possible n places say i th beaker  .
	Now we have two possible cases :
	1st :It dissolves in the ith beaker.Now we have k-1 capsules and number of possible beakers are i-1
	2nd : It does not dissolve in the ith beaker .Now we have to find from remaining n-i beakers with k available capsules.

	Now since our answer could be any of the two above cases so we take the maximum of the two cases IN THE WORST CASE +1 (the current trial).
	Our final answer would be the minimum across alll the possible places since we can select any of these.
		int ans=n+1;
		for(int i=1;i<=n;i++)
		{
			int res=1+max(func(k-1,i-1),func(k,n-i));
			ans=min(res,ans);
		}
*/

	else
	{	
		int ans=n+1;
		for(int i=1;i<=n;i++)
		{
			int res=1+max(func(k-1,i-1),func(k,n-i));
			ans=min(res,ans);
		}
		return ans;
	}
	
}

int main()
{
	ifstream ip("input.txt");
	ofstream op("output.txt");
	int t;
	ip>>t;
	while(t--)
	{	int k,n;
		ip>>k>>n;
		int ans=func(k,n); //Using Recursion
		op<<k<<" "<<n<<" "<<ans<<endl;
	}
}