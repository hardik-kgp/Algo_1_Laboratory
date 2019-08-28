#include<bits/stdc++.h>

using namespace std;
typedef struct Stack{
		char data;
		struct Stack *next;
	}Stack;
	int size=0;
	bool isEmpty(Stack *stack)
	{
		return (size==0);
	}
	char pop(Stack **stack)
	{	
		char k=(*stack)->data;
		(*stack)=(*stack)->next;
		size--;
		return k;
	}
	void push(Stack **stack,char val)
	{
		Stack* newnode=(Stack *)malloc(sizeof(Stack *));
  		newnode->data=val;
  		
    	newnode-> next=(*stack);
  		*stack=newnode;
  		size++;
	}
	char peek(Stack *stack)
	{
		return stack->data;
	}

bool is_operand(char s)
{
	return (s>='0')&&(s<='9');
}
int precedence(char s)
{
	if(s=='('||s==')')
		return 3;
	else if(s=='*'||s=='%'||s=='/')
		return 2;
	else 
		return 1;
}
bool is_operator(char s)
{
	return (s=='%'||s=='*'||s=='/'||s=='+'||s=='-'||s=='+');
}
string solve(string s)
{
	Stack *st=NULL;
	
	string ans;
	ans.resize(100000);
	int m=0;
	for(int i=0;i<s.size();i++)
	{
		if(is_operand(s[i]))
		{	
			if(m!=0)
				if(is_operand(ans[m-1]))
				ans[m++]=' ';
			while(is_operand(s[i]))
			{
				ans[m++]=s[i];
				i++;
			}
			
			i--;
		}
		else if(is_operator(s[i]))
		{	
			
			while((!isEmpty(st))&&precedence(peek(st))>=precedence(s[i])&&(peek(st)!='('))
			{
				ans[m++]=pop(&st);;
				
			}

			push(&st,s[i]);

		}
		else if(s[i]=='(')
		{
			push(&st,s[i]);
		}
		else 
		{
			while(peek(st)!='(')
			{
				ans[m++]=peek(st);
		
				pop(&st);
			}
			pop(&st);
			
		}
				

	}

	while(!isEmpty(st))
	{
		ans[m++]=peek(st);
		pop(&st);
	}
	ans.resize(m);
	return ans;
}
int main()
{
	string line;
	 ofstream op ("18CS10021_A2_P1_output.txt");
  
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      op<<solve(line);
      op<<'\n';
    }
    myfile.close();
  }

  op.close();
	/*string s;
	cin>>s;
	cout<<solve(s)<<endl;*/


  return 0;

}