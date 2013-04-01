#include<conio.h>
#include<stdio.h>
#include <iostream>
struct node
{
  struct node *next;
  struct node *random;
  int val;
  
};

struct node* copy_list(struct node *root)
{
    struct node *res=NULL;
     
    struct node *cur = root;
    struct node *next, *tmp;
     
    //Create the copy of every node in the list and insert 
    //it in original list between current and next node. 
    while(cur)
    {
        tmp =new(node);
        tmp->val = cur->val;
        tmp->random = NULL;
        tmp->next = cur->next;
        next = cur->next;
        cur->next = tmp;
        cur = next;        
    }
       
    //save result pointer    
    res = root->next;
     
    //Copy the arbitrary link for result
    cur = root;    
    while(cur)
    {
        cur->next->random = cur->random->next;
        cur = cur->next->next;  //move 2 nodes at a time
    }
     
    //restore the original and copy linked lists
    cur = root;    
    tmp = root->next;
    while(cur && tmp)
    {
        cur->next = cur->next->next;
        cur = cur->next;
        if (tmp->next){
            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }        
    }
     
    return res;
}
  
void printList(struct node *head)
{
     while(head!=NULL)
     {
        printf("%d -> %d",head->val,head->random);
        head=head->next;
     }
     printf("\n");
}
  struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->val = data;
    node->random=NULL;
    node->next = NULL;

    return(node);
}
int main()
{
struct node *head =newnode(1);
    head->next        = newnode(2);
    head->random   = head->next;
    head->next->next=newnode(3);
    head->next->random= newnode(4);
     head->next->next->next=head->next->random;
    head=copy_list(head);
  
    printf("Given Linked List: ");
    printList(head);
    getch();
    return 0;
}
