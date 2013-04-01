#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
   struct node
   {
       int data;
       struct node *link;
   };

  void insert(struct node *p, int n)
  {
      struct node *temp;
      if(p==NULL)
      {
          p=(struct node *)malloc(sizeof(struct node));

         if(p==NULL) 
         {
             printf("Error\n");
              getch();
         }
         p-> data = n;
         p-> link = NULL;
      } 
      else 
      {
         temp = p;
         while (temp-> link != NULL)
            temp = temp-> link;
            temp-> link = (struct node *)malloc(sizeof(struct node));
            if(temp -> link == NULL)
            {
               printf("Error\n");
               getch();
            }
            temp = temp-> link;
            temp-> data = n;
            temp-> link = NULL;
      }
         
   }
   
   void printlist ( struct node *p )
   {
      struct node *temp;
      temp = p;
      printf("The data values in the list are\n");
      if(p!= NULL)
      {
            do
            {
                printf("%d\t",temp->data);
                temp=temp->link;
            } while (temp!= NULL);
      }
      else
         printf("The list is empty\n");
   }

   int main()
   {
      struct node start;
      start.data=0;
      start.link=NULL;

     insert ( &start, 1 );
     insert ( &start, 2);
     insert ( &start, 3 );
     insert ( &start, 4 );                          

      printf("The created list is\n");
      printlist ( &start );
      getch();
      return 0;
   }
