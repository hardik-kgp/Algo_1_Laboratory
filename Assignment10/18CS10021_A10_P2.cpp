/*I was not able to complete the implementation of the 2nd part so here is the pseudo code for the second part.


FastGreedyHorn(phi):
1. SetvtoFalsefor each variable v in(phi)
2. Set W:=f v:v appears on the right-hand side of an empty implication g
3. While W , do:
4.Take (and delete) v from W.
5.Set v to True.
6.For each clause c where v appears on the left-handside,do:
7.Delete v from the left-hand side of c.
8.If this makes c into an empty implication,add the variable on the right-hand side of c into W(if it is not already in W).
9. Return the current truth assignment.*/


//Name -Hardik Aggarwal
//Roll no-> 18CS10021
//Machine NO-16
#include <bits/stdc++.h>
using namespace std;
const int MAX=10000;
bool evaluate_single(char s[],int val[])
{
	for(int i=0;i<strlen(s);i++)
	{	
		if(s[i]=='I')
		{
			if(val[s[i+4]-'a']==0)
				return false;
		}
		if(s[i]>='a'&&s[i]<='z')
		{
			if(val[s[i]-'a']==false)
			{
				return true;
			}
		}
	}
	return true;
}


bool evaluate(char s[][10000],int val[],int t)
{	

	for(int i=0;i<t;i++)
	{	
		
		if(s[i][0]=='I')
			{
				val[s[i][4]-'a']=1;
				continue;
			
			}
		else if(s[i][0]=='N')
		{	
			bool flag=0;
			
			for(int j=0;j<strlen(s[i]);j++)
				{
					if(s[i][j]>='a'&&s[i][j]<='z')
					{
						if(val[s[i][j]-'a']==false)
						{
							flag=1;
							break;
						}
					}
				}
				if(!flag)
					return 0;
		}
		else
		{
			if(evaluate_single(s[i],val))
			{
				continue;
			}
			else
			{
				for(int j=0;j<strlen(s[i]);j++)
				{
					if(s[i][j]=='I')
					{
						val[s[i][j+4]-'a']=true;
						break;
					}
				}
			}
		}
		

	}

	return true;
}
int main()
{
	ifstream ip ("input.txt");
	ofstream op ("output.txt");
	int t;
	ip>>t;
	ip.ignore();
	char s[t][MAX];
	int val[26];
	for(int i=0;i<26;i++)
		val[i]=-1;
	for(int i=0;i<t;i++)
	{
		
		ip.getline(s[i],500);
		//op<<s[i]<<endl;
		//op<<strlen(s[i])<<endl;
		for(int j=0;j<strlen(s[i]);j++)
		{
			if(s[i][j]>='a'&&s[i][j]<='z')
			{
				val[s[i][j]-'a']=0;
			}
		}
	}
	int found=evaluate(s,val,t);
	
	if(found)
	{
		for(int i=0;i<26;i++)
		{
			if(val[i]!=-1)
			{	
				if(val[i])
					op<<(char)(i+'a')<<"= "<<"true"<<", ";
				else
					op<<(char)(i+'a')<<"= "<<"false"<<", ";
			}
		}
		op<<endl<<"satisfiable"<<endl;
	}
	else
	{
		op<<"not satisfiabe"<<endl;
	}
	



}