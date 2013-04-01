#include<iostream.h>
#include<conio.h>
void push(int a[],int element);
int pop(int a[]);
int top=-1, capacity=0;

int main()
{    
    cout<<"Enter the size of the array\n\n";
    cin>>capacity;
    char answer='y', operation;
    int a[capacity];
    while(answer=='y')
    {
                      cout<<"What would you like to do: Press 1 for push and 2 for pop\n\n";
                      cin>>operation;
                      if(operation=='1')
                      {
                                        int element;
                                        cout<<"Enter the element you want to push\n\n";
                                        cin>>element;
                                        push(a,element);
                      }
                      else if(operation=='2')
                      {
                                        int element=pop(a);
                                        cout<<"The popped element is: "<<element<<"\n\n";
                      }
                      else
                      cout<<"Wrong option selected\n\n";
                      cout<<"Press y to continue\n\n";
                      cin>>answer;
    }
    getch();
}
void push(int a[],int element)
{
     if(top!=capacity)
     {
        top++;
        a[top]=element;
     }
     else
     cout<<"stack is full\n\n";        
}

int pop(int a[])
{
     if(top!=-1)
     {                
                top--;
                return a[top+1];
     }
     else 
     cout<<" Stack is empty\n\n";
     return 0;
}
