#include<iostream.h>
#include<conio.h>
// find the number of way on getting sum of k(input) elements =n, in an array having 1,2....n elements 
int NoOfWays=0;
void SumKN(int i, int n, int remainingElements, int a[])
{
     if((n==0 && remainingElements!=0)||(i==n && n!=0)||(n<0))
     return;
     if(n==0 && remainingElements==0)
     {
             NoOfWays++;
             return;
     }
     if(remainingElements<0)
     return;
     
     SumKN(i+1, n,remainingElements,a);// not including ith elemenr
     SumKN(i+1, n-i,remainingElements-1,a);// including ith elemenr
}
     
     
int main()
{
    int a[6];
    int k,n ;
    cout<<"Enter the value of K\n";
    cin>>k;
    cout<<"Enter the value of N\n";
    cin>>n;
    
    for(int j=0;j<n;j++)
     a[j]=j+1;
     
    SumKN(1,n,k,a);
    cout<<"Number of ways are  "<<NoOfWays;
    //getch();
    cout<<"hello wait";
    int x;
    cin>>x;
    return 0;
}
