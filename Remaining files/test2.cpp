#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class x{      
          public:
          int a;
          x()
          {
               a=10;
          }
          void show()
          {      
                
             cout<<"in base a is   "<<a;
          }   
      };
class y: public x
{
      public:
      int b;
      y()
      {
          b=20;
      }
      void show()
      {
           cout<<"in derived a and b are   "<<a<<"\t"<<b;
      }  
}  ;
int main()
{
    x X, *xptr;
    y Y, *yptr;
    yptr=&X;
    yptr->show();
    getch();
    return 0;
}
//try this 
/*char *ch=new char(5);
    ch="hii";
    cout<<"enter value";
    cin>>ch;
    ch[4]="\0";
    cout<<ch;*/
    
