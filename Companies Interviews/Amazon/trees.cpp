#include<conio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;   
};
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return(node);
}
int main()
{

    /* Constructed binary tree is
              22
            /   \
          8      32
        /  \
      4     12
           /  \
          10   14 
      
      
    */      
    struct node *root = newnode(22);
    root->left        = newnode(8);
    root->right       = newnode(32);
    root->left->left  = newnode(4);
    root->left->right  = newnode(12);
     root->left->right->left  = newnode(10);   
      root->left->right->right  = newnode(14);   
}
void getPathFromRoot(struct node **arr, struct node *root, struct node*ptr, int k)
{
          
}     
void printKDistantance(struct node *root , struct node*ptr, int k)
{
     struct node *arr[k]= (struct node*)malloc(sizeof(struct node)*k);
   if( k == 0 )
   {
      printf( "%d ", ptr->data );
      return ;
   }
   else
   {
      printKDistant( ptr->left, k-1 ) ;
      printKDistant( ptr->right, k-1 ) ;
   }
}
