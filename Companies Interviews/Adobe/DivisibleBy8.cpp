#include<iostream.h>
#include<conio.h>
// First read from http://www.careercup.com/question?id=13718748
int main()
{
    int n,*a,sum=0,i=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    a=new int[n];
    for(int j=0;j<n;j++)
    cin>>a[j];
    while (n--)
    {
    sum += a[i++] & 0x7;
    }
    sum & 0x07;
    if (sum & 0x07)
    cout<<"\n not";    // not divisible by 8
    else
    cout<<"\n it is";
    // divisible by 8.
    
    getch();
    return 0;
}
