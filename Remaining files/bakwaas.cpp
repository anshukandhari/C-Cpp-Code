#include<iostream.h>
#include<conio.h>
#include<stdio.h>
  
class Base1{
  public:
    virtual void func1(void){};
};

class Base2 {
  public:
    virtual void func2(void){};
};

class Derive: public Base1, Base2{
  public:
    virtual void func3(void){};
};

int main()
{
  Derive d;

  //Only non-static data
  cout<<"SIZE OF CLASS BASE (with Single Inheritance) = "<<sizeof(d)<<endl;
  getch();
  return (0);
}

