#include<iostream.h>
#include<conio.h>

typedef struct Tree
{
       int data;
       Tree *left;
       Tree *right;
}tree;
tree* InsertBST(tree *, int a);
void display (tree *);

int main()
{
    int arr[10];
    tree *root=NULL;
    cout<<"Enter the elements to be created: ";
    for(int i=0;i<10;i++)
    {
            cin>>arr[i];
            root=InsertBST(root, arr[i]);
    }
    display(root);
    getch();
    return 0;
}

tree* InsertBST(tree *root, int a)
{
     if(root==NULL)
     {   
      root=new tree;      
      root->data=a;
      root->left=root->right=NULL;
     }
     else 
     {
          if(a <= root->data)
          root->left=InsertBST(root->left, a);
          
          else
          root->right=InsertBST(root->right, a);
     }
     return root;
}

void display(tree *root)
{
     if(root)
     {
         display(root->left);
         cout<<root->data;
         display(root->right);
     }
}         
