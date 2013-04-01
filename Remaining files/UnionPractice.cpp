#include<iostream.h>
#include<conio.h>
#include<stdio.h>
union A
{
      int x;char y;
}a;
      
int main()
{
 
  a.y='p';
  cout<<a.y;
  a.x=0;
  cout<<a.x;
  cout<<a.y;
  getch();
  return 0;
}  
