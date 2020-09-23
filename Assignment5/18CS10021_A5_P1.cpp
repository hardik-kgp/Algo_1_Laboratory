#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	string symbol;
	int  frequency;
	struct Node *next;
	struct Node *left;
	struct Node *right;
}Node;

bool comp(Node* a,Node* b)
{
	if(a->frequency<b->frequency)
		return 1;

	else if(a->frequency==b->frequency)
	{	
			if(a->symbol[0]=='N')
		{
			if(b->symbol[0]=='N')
				return a->symbol<b->symbol;
			else
				return 1;
		}
		else if(b->symbol[0]=='N')
			return 0;
		if(a->symbol[0]>='0'&&a->symbol[0]<='9')
		{
			if(b->symbol[0]>='0'&&b->symbol[0]<='9')
			{
				return a->symbol<b->symbol;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if(b->symbol[0]>='a'&&b->symbol[0]<='z')
			{
				return a->symbol<b->symbol;
			}
			else
			{
				return 1;
			}
		}
		return 1;
		/*if(a->symbol[0]>='0'&&a->symbol[0]<='9')
		{
			a->symbol[0]+=(100);
		}
		if(b->symbol[0]>='0'&&b->symbol[0]<='9')
		{
			b->symbol[0]+=(100);
		}
		return a->symbol<b->symbol;
*/
	}
	return 0;
}
void sortedInsert(Node** head_ref, Node* new_node)  
{  
    Node* current;  
    
    if (*head_ref == NULL || !comp(*head_ref,new_node))  
    {  
        new_node->next = *head_ref;  
        *head_ref = new_node;  
    }  
    else
    {  
       
        current = *head_ref;  
        while (current->next!=NULL &&  
            comp(current->next,new_node))  
        {  
            current = current->next;  
        }  
        new_node->next = current->next;  
        current->next = new_node;  
    }  
}  

  

Node *newNode(char key,int val)  
{  
    
    Node* new_node =new Node(); 
  	
    new_node->symbol = key;
    new_node->frequency = val;  
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;  
  
    return new_node;  
}  

Node *newNode1(string key,int val,Node* a,Node* b)  
{  
    
    Node* new_node =new Node(); 
  	
    new_node->symbol = key;
    new_node->frequency = val;  
    new_node->next = NULL;
    new_node->left = a;
    new_node->right = b;  
  
    return new_node;  
}  
/*void new_node(string key,int val,Node **head)
{	
	if(*head==NULL)
	{
		(*head) -> symbol = key;
		(*head)->frequency=val;
		(*head)->next=NULL;
		(*head)->left=NULL;
		(*head)->right=NULL;
	}
	else
	{	
		Node* newnode=(Node *)malloc(sizeof(Node *));
		newnode->symbol=key;

		newnode-> frequency=val;
		newnode->next=(*head);

		newnode->left=NULL;
		newnode->right=NULL;
		(*head)=newnode;	
	} 
} */
string tostring(int x)
{
	string s;
	while(x)
	{
		s+=('0'+x%10);
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
string s2="";
void TreeTraverse(Node* T,string H[],string C)
{	
	s2+=(T->symbol);
	s2+=(" ");
	if((T->symbol[0]>='a'&&T->symbol[0]<='z')||(T->symbol[0]>='0'&&T->symbol[0]<='9'))
	{
		if(T->symbol[0]>='a'&&T->symbol[0]<='z')
		{
			H[T->symbol[0]-'a']=C;
		}
		else
		{
			H[T->symbol[0]-'0'+26]=C;	
		}
	}
	else
	{	
		if(T->left!=NULL)
		TreeTraverse(T->left, H,C+'0');
		
		if(T->right!=NULL)
		TreeTraverse(T->right, H,C+'1');
	}
}
int main()
{
	ofstream op ("18CS10021_A5_P1_output.txt");
  
  	ifstream ip ("log-2.txt");

  	int n;
	ip>>n;

	
	int fre[36]={0};

	for(int i=0;i<n;i++)
	{	string s;
		ip>>s;
		
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>='a'&&s[j]<='z')
			{
				fre[s[j]-'a']++;
			}
			else
			{
				fre[26+s[j]-'0']++;
			}
		}
	}
	Node *head=NULL;

	for(int i=0;i<36;i++)
	{
		if(i<26)
		{
			sortedInsert(&head,newNode('a'+i,fre[i]));
		}
		else
		{
			sortedInsert(&head,newNode('0'+i-26,fre[i]));
		}
	}
	Node *temp=head;
	int size=0;
	while(temp!=NULL)
	{
		op<<temp->symbol<<"="<<temp->frequency<<",";
		temp=temp->next;
		size++;
	}
	int var1=1;
	while(size>1)
	{
		Node *temp=head;
		string x="N";
		x+=(tostring(var1));
		Node* nn=newNode1(x,temp->frequency+temp->next->frequency,temp,temp->next);
		head=head->next;
		head=head->next;
		sortedInsert(&head,nn);		
		var1++;
		size--;
	}
	op<<endl;
	temp=head;
	string H[36];
	string C="";
	TreeTraverse(temp,H,C);
	op<<s2<<endl;

	for(int i=0;i<36;i++)
	{	
		
		if(i<26)
		{	char c='a'+i;
			op<<c<<" "<<H[i]<<endl;
		}
		else
		{	char c='0'+i-26;
			op<<c<<" "<<H[i]<<endl;
		}
	}
	ifstream ip1("encode.txt");
	ip1>>n;
	for (int i = 0; i < n; ++i)
	{
		string s,ans="";
		ip1>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>='0'&&s[j]<='9')
			{
				ans+=H[s[j]-'0'+26];
			}
			else
			{
				ans+=H[s[j]-'a'];	
			}
		}
		op<<ans<<endl;
	}
	ifstream ip2("decode.txt");
	ip2>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		ip2>>s;
		string ans="";
		for(int j=0;j<s.size();j++)
		{
			for(int k=0;k<36;k++)
			{
				if(s.substr(j,H[k].size())==H[k])
				{
					j=j+H[k].size()-2;
					if(k<26)
					{
						ans+=('a'+k);
					}
					else
					{
						ans+=('0'+i-26);
					}
					break;
				}
			}
		}
		op<<ans<<endl;
	}









}