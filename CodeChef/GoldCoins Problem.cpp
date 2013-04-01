/* Problem: Bytelandian gold coins */
//Using a Binary Search Tree. Can be speeded up by using Red Black / AVL trees
#include<stdio.h>
#include<stdlib.h>
 
struct node {
     unsigned int key;
     unsigned int value;
     struct node* left;
     struct node* right;
};
 
void insertNode(struct node** root, struct node* newNode) {
     if(*root == NULL)
          *root = newNode;
     else if(newNode->key < (*root)->key)
          insertNode(&((*root)->left), newNode);
     else
          insertNode(&((*root)->right), newNode);
}
 
unsigned int search(struct node** root, unsigned int key) {
     if(*root == NULL)
          return -1;
     if((*root)->key == key)
          return (*root)->value;
     if((*root)->key < key)
          return search(&((*root)->right), key);
     return search(&((*root)->left), key);
}
 
unsigned int getMaxCoins(struct node** root, unsigned int number) {
     unsigned int val;
     if((val = search(root, number)) != -1)
          return val;
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->left = NULL;
     node->right = NULL;
     if(number < 12) {
          node->key = number;
          node->value = number;
          insertNode(root, node);
          return number;
     }
     val = getMaxCoins(root, number/2) + getMaxCoins(root, number/3) + getMaxCoins(root, number/4);
     node->key = number;
     node->value = val;
     insertNode(root, node);
     return val;
}
 
int main() {
     unsigned int number;
     while(scanf("%d", &number) != EOF) {
          struct node* ptr = NULL;
          printf("%u\n", getMaxCoins(&ptr, number));
     }
     return 0;
}
