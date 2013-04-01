#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class base
{
       int a;
       public: 
       base(int x)
       {
             a=x;
       }
       void print()
       {
            cout<<a;
       }
};
class derive: public base
{
       
       public: 
       int b;
       derive(int x, int y): base(x)// see the way of calling the base class constructor, its necessary also.
       {
             b=y;
       }
       void print()
       {
            base::print();// Use the scope resolution to call the base class function from derive class 
            cout<<b;
       }
};
int main()
{
   int i = 1;
   derive d(i,i+2);// I forgot that we can pass the constructor argument in this way also.
   cout<<d.b;
   d.print();
   getchar();
   return 0;
}
