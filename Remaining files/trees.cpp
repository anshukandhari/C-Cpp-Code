/*#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;
   
  return(node);
}
struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node 
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;  
 
    /* 2. Otherwise, recur down the tree 
    if (data <= node->data)
    {    
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }    
  
    /* return the (unchanged) node pointer 
    return node;
  }
} 
int main()
{
struct node* root = NULL, *temp, *succ, *min;
 
  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);  
  root = insert(root, 14);    
  temp = root->left->right->right;
 



getch();
return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

/* Set next of all descendents of p */
void connectRecur(struct node* p)
{
    // Base case
    static struct node *next = NULL;
    if(p)
    {
        connectRecur(p->right);
        p->next = next;
        next = p;
        connectRecur(p->left);
    }
}

void print(struct node *root)
{
      if(root)
    {
        print(root->left);   
        if(root->next)          
        printf("%d  \n", root->next->data);        
        print(root->right);
    }
    //while(root)
//    {
//        printf("%d  ", root->data);
//        root = root->next;
//    }
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
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

/* Driver program to test above functions*/
int main()
{

    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct node *root = newnode(22);
    root->left        = newnode(8);
    root->right       = newnode(22);
    root->left->left  = newnode(4);
    root->left->right  = newnode(12);
     root->left->right->left  = newnode(10);   
      root->left->right->right  = newnode(14);   
    // Populates nextRight pointer in all nodes
    connectRecur(root);
    print(root);

    getchar();
    return 0;
}
