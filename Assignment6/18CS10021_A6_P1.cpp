//Hardik Aggarwal 
//18CS10021


#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 10000
typedef  struct  _treenode {
char route[MAXLEN];
struct  _treenode *left;
struct  _treenode *right;
int  height;
} AVLtreenode;
//typedef  AVLtreenode *AVLtree;
ofstream op ("18CS10021_A6_output.txt");
int height(AVLtreenode *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

AVLtreenode* newAVLtreenode(char route[])  
{  
    AVLtreenode* node = new AVLtreenode(); 
    strcpy(node->route,route)  ;
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return(node);  
}  

AVLtreenode *rightRotate(AVLtreenode *y)  
{  
    AVLtreenode *x = y->left;  
    AVLtreenode *T2 = x->right;   
    x->right = y;  
    y->left = T2;  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
 
    return x;  
}   
AVLtreenode *leftRotate(AVLtreenode *x)  
{  
    AVLtreenode *y = x->right;  
    AVLtreenode *T2 = y->left;   
    y->left = x;  
    x->right = T2; 
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;   
    return y;  
}  
int getBalance(AVLtreenode *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
AVLtreenode* insert(AVLtreenode* node, char route[])  
{  

    if (node == NULL)  
        return(newAVLtreenode(route));  
  
    if (strcmp(route , node->route)<0)  
        node->left = insert(node->left, route);  
    else if (strcmp(route , node->route))  
        node->right = insert(node->right, route);  
    else  
        return node;  
 
    node->height = 1 + max(height(node->left),  
                        height(node->right));  

    int balance = getBalance(node);  
  
    if (balance > 1 && route < node->left->route)  
        return rightRotate(node);  
   
    if (balance < -1 && route > node->right->route)  
        return leftRotate(node);  
   
    if (balance > 1 && route > node->left->route)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  

    if (balance < -1 && route < node->right->route)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    return node;  
}  
void Inorder(AVLtreenode *root)  
{  
    if(root != NULL)  
    {  
          
        Inorder(root->left);
        op<<root->route<<endl;
        Inorder(root->right);  
    }  
} 

void Corrections(char s[])
{
	int j=0;
	int l=0;
  		while(j<strlen(s))
  		{
  			int k=j;
  			while(s[j]==s[k]&&k<strlen(s))
  				k++;
  			s[l++]=(s[j]);
  			j=k;
  		}
  	s[l]='\0';
  	
} 
int main()
{
	
  
  	ifstream ip ("Routes.txt");
  	int n;
  	ip>>n;
  	AVLtreenode* root=NULL;
  	char s[n+1][MAXLEN];
  	for(int i=0;i<n;i++)
  	{	
  		
  		ip>>s[i];
  		Corrections(s[i]);
  		root=insert(root,s[i]);
  	}
  	op<<root->height<<endl;
  	Inorder(root);

 	


}