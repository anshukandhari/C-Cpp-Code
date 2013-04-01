#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> values;
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
   

    return(node);
}
void printNodeAtDistance(node *root, int distance) 
{
    if (root == NULL) 
    return;
    
    if (distance == 0)
     {
          values.push_back(root->data);
     } 
    else
    {
        printNodeAtDistance(root->left, distance-1);
        printNodeAtDistance(root->right, distance-1);
    }
}

int getLen(node *move, node *desired, int k)
{
 if (move == NULL) 
 return -10;
 if (move->data == desired->data) 
 {
  printNodeAtDistance(move, k);
  return k-1;
 }
 int p = getLen(move->left, desired, k);
 if (p == -10)
  {
   p = getLen(move->right, desired, k);
     if (p == 0)
     {
      values.push_back(move->data);
      return -10;                  
      }
      if (p == -10) 
      return -10;
      printNodeAtDistance(move->left, p-1);
      }
     else if (p >= 0) 
     {
      if (p == 0)
      {
       values.push_back(move->data);
       return -10;
      }
      printNodeAtDistance(move->right, p-1);
  }
 return p-1;
}


void printValues()
 {
  sort(values.begin(), values.end());
  for(int j = 0; j < values.size(); j++)
  {
  cout << values[j] << endl;
  }
}

void printKDistanceNodes(node *root, node *start, int K)
{
    getLen(root, start, K);
    printValues();
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
    struct node *root = newnode(50);
    root->left        = newnode(25);
    root->right       = newnode(55);
    root->left->left  = newnode(20);
    root->left->right  = newnode(30);
    root->left->left->right= newnode(23);
    root->left->left->left= newnode(10);
    root->left->left->right->right  = newnode(24);   
    root->left->left->left->right  = newnode(12);   
    root->left->left->left->left  = newnode(5); 
    printKDistanceNodes(root, root->left->left, 2);
    getch();
    return 0;
}
