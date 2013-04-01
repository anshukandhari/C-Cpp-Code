/*
Code from http://anandtechblog.blogspot.in/2010/06/how-to-create-circular-doubly-linked.html
void BSTtoCDbl(List *root,List **head,List** last)
{
    // if root is null return
   // this is the terminating condition for recursion
    if(root == NULL)
        return;
   // parse left subtree.
   BSTtoCDbl(root->left,head,last);
   // Reach the root node include it in doubly linked list. 
   if(*last == NULL)
  {
      // if it is left most node
     // adding node for the first time in doubly linked list
     // head and last are memory pointers of doubly linked list
     // Now they both are pointing to the same root node.
      *head = root;
      *last = *head; 
  }
  else
  {
     //adding the root node to tail of doubly linked list.
     // Update the last pointer of doubly linked list
     // current last pointer is now pointing to the newly added node
     // since it is doubly linked list newly added node is pointing to current last pointer
    // Update the last pointer to newly added root node.
     (*last)->right = root;
     root->left = *last;
    *last = root;
  }
   // Traverse the right subtree. 
   BSTtoCDbl(root->right,head,last);
}*/

#include<iostream.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef struct Lnode
{
        int data;
         struct Lnode *prev;
         struct Lnode *next;
}lnode;

node* newnode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode ->data = data;
    newnode ->left = NULL;
    newnode ->right = NULL;

    return(newnode);
}

node *a,*b;
lnode *tail;
void Join(int x, int y)
{
     lnode *A=new lnode;
     lnode *B=new lnode;
     A->data=x;
     B->data=y;
     A->next=B;
     B->prev=A;
     tail=B;
}

void WraperForJoin(node * temp)
{
     if(a == NULL)  
     a=temp;
     else if(b == NULL)
         {
          b=temp;
          Join(a->data, b->data);
          a=b;
          b=NULL;         
         }
     
}
void print(lnode* end)
{
     int i=5;
     while(i>0)
     {
               cout<<end->data;
               end=end->prev;
               i--;
     }
}
void BST2DLL(node *root)
{
     while(root!=NULL)
     {
            BST2DLL(root->left);
            WraperForJoin(root);
            BST2DLL(root->right);
     }
     print(tail);
}      
int main()
{

    /* Constructed binary tree is
              8
            /   \
          4      20
        /  \    /  \
      3    5   13   27
                 /
                 25
                 */
    a=NULL;
    b=NULL;             
    node *root = newnode(8);
    root->left        = newnode(4);
    root->right       = newnode(20);
    root->left->left  = newnode(3);
    root->left->right  = newnode(5);
    root->right->right = newnode(27);
    root->right->right->left  = newnode(25);   
    root->right->left  = newnode(13);   
    // Populates nextRight pointer in all nodes
    BST2DLL(root);
    
    getch();
    return 0;
}
