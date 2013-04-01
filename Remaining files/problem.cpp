#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int main()
{
    char *ch=new char(5);
    ch="hii";
    cout<<ch<<"enter value";
    cin>>ch;
    cout<<ch;
    getch();
    return 0;
}
