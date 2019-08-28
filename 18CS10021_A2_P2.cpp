#include<bits/stdc++.h>

using namespace std;
typedef struct Stack{
		int data;
		struct Stack *next;
	}Stack;
	int size=0;
	bool isEmpty(Stack *stack)
	{
		return size==0;
	}
	int pop(Stack **stack)
	{	
		int k=(*stack)->data;
		(*stack)=(*stack)->next;
		size--;
		return k;
	}
	void push(Stack **stack,int val)
	{
		Stack* newnode=(Stack *)malloc(sizeof(Stack *));
  		newnode->data=val;
  		
    	newnode-> next=(*stack);
  		(*stack)=newnode;
  		size++;
	}
	int peek(Stack *stack)
	{

		return stack->data;
	}

bool is_operand(char s)
{
	return (s>='0')&&(s<='9');
}

bool is_operator(char s)
{
	return (s=='%'||s=='*'||s=='/'||s=='+'||s=='-'||s=='+');
}
int evaluate(int a,int b,char op)
{
	if(op=='%')
		return a%b;
	if(op=='*')
		return a*b;
	if(op=='/')
		return a/b;
	if(op=='+')
		return a+b;
	if(op=='-')
		return a-b;
}
int solve(string s)
{
	Stack *st=NULL;

	for(int i=0;i<s.size();i++)
	{	
	
		if(s[i]==' ')
			continue;
		if(is_operand(s[i]))
		{	int temp=0;
			while(is_operand(s[i]))
			{
				temp=temp*10+(s[i]-'0');
				i++;
			}
			push(&st,temp);
			
		}
		
		
		if(is_operator(s[i]))
		{	
				
			int a=pop(&st);
			int b=pop(&st);
			
			int c=evaluate(b,a,s[i]);
			push(&st,c);

		}
		
				

	}

	int ans=pop(&st);
	return ans;
}
int main()
{
	string line;
	 ofstream op ("18CS10021_A2_P2_output.txt");
  
  ifstream myfile ("18CS10021_A2_P1_output.txt");
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


  return 0;

}