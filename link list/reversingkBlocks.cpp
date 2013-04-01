#include<iostream.h>
#include<conio.h>


typedef struct list
{
       int data;
       list* next;
}node;

void reverseN(node* node, int a);

void print( node* root)
{
     while(root)
     {
        cout<<root->data<<"  ";
        root=root->next;
     }
     cout<<"\n";
}      

int main()
{
  node *head;
  head=new(node);
  head->data=1;
  struct list *root=head;
  for(int i=2;i<11;i++)
  {
          node *temp=new(node);
          head->next=temp;
          temp->data=i;
          head=temp;            
  }
  print(root);
  reverseN(root,2); 
  print(root);
  getch();
  return 0;
}

struct list* GetNthNode(int n, struct list* head)  
{  
   if(!head)  
       return head;  
  
   node *Nth;  
   int i;  
    
   //Notice the loop body (empty)  
   for (i=0, Nth=head; Nth && (i < n);Nth=Nth->next,i++);  
  
   if(i==n && Nth!=NULL)  
       return Nth;  
   return head->next;  
}  
  
int isNnodes(struct list* head, int n)  
{  
   int i=0;  
    
   //Notice the loop body (empty)  
   for (i=0 ; head && (i <n);i++,head=head->next);     
   if(i == n)  
       return 1;  
       
   return 0;  
}  
  
void reverseN(struct list** list1, int n)  
{  
   if (n==0 || n==1)  
       return;  
    
   struct list *cur, *tmp, *next;  
   int i;  
   cur = *list1;  
  
   if(!isNnodes(*list1,n))  
       return;  
  
   *list1 = GetNthNode(n-1,*list1);  
  
   while(cur && isNnodes(cur, n))  
   {  
       //take care on below step  
       tmp = GetNthNode(n, GetNthNode(n-1, cur));  
       i=0;  
  
       while(i<n)
       {
            next=cur->next;  
           cur->next=tmp;  
           tmp = cur;  
           cur = next;  
           i++;  
       }  
   }  
}  
