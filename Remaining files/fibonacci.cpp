#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int fibo(int n)
{
     if(n==0)
     return 0;
     else if(n==1)
     return 1;
     else
     {
         return fibo(n-1)+fibo(n-2);
     }
}
int main()
{
    int i;
    char *ch=new char(4);
    ch="yes";
    while(ch=="yes")
    {
        printf("Enter the nth number index you want to know in fibonacci\n");
        scanf("%d",&i);
        int n=fibo(i);
        printf("%d",n);
        printf("\nDo you wanna continue, say yes if you want\n");
        cin>>ch;
    }
        cout<<ch;
        getch();
        return 0;
}
