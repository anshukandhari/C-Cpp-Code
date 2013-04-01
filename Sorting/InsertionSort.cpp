#include<iostream.h>
#include<conio.h>
int main()
{
    int i,j,k,a[5]={5,3,8,9,2};
    for(j=0;j<4;j++)
    for(i=j+1;i<5;i++)
    if(a[i]<a[j])
    {
                 int temp=a[i];
                 for(k=i;k>j;k--)
                 a[k]=a[k-1];
                 a[k]=temp;
    
    }
    for(i=0;i<5;i++)
    cout<<a[i]<<"\n";
    getch();
    return 0;    
}
