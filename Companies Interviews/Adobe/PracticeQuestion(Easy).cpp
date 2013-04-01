#include<iostream.h>
#include<conio.h>
/*
class x
{
      public:
      int a;
};
class y
{
      public:
      int b;
      x *p,*q;
};
int main()
{
    y o;
    (o.p)->a=4;
    getch();
    return 0;
}*/
/*class x
{
      public:
      struct a{
      int n,b;
      }p;
      //a arr[5];
      x(){}
};

      
int main()
{
    cout<<sizeof(x);
    x o;
    cout<<"struct"<<sizeof(o.p);
    getch();
    return 0;
}
  */
  class x
{
      public:
      //int a;
      class y
      {
      public:
      int b;
      }y1;
};

int main()
{
    x o;
    cout<<sizeof(x);
    cout<<sizeof(o.y1);
    getch();
    return 0;
}    
