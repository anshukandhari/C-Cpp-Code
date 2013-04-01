//Coin Change problem...DP because 1)Optimal substructure as subproblem needs to be optimal also...
// 2) Overlapping subproblem (which is basically recursion)
// C(P) = min number of coins to make change = p optimally
#include<iostream.h>
#include<conio.h>
#define min(a,b) a<b?a:b
int sqart(int n)
{
    if(n < 0)
    {
    return -1;
}
    
    if(n<2)
    return n;
    
    int x,i=1, mul=1;
    
    while(mul<=n)
    {
     i++;
     mul=i*i;
    }
    
    return i-1;
}
int CountSquaresToGetN(int n, int table[])
{
     if(n<0)
     return -1;
     
     if(table[n]!=-1)          
     return table[n];
     
     int x;
     x=sqart(n);
     int ans=-1;
    // cout<<"\n"<<x;
     
     
     for(int i=1;i<=x;i++)
     {
           if(ans==-1)
           ans=CountSquaresToGetN(n-table[i],table);
           else
           {
          // cout<<ans<<"\n";
           ans=min(ans, CountSquaresToGetN(n-table[i],table));  
           }
     }
     table[n]=ans+1;
     return ans+1;
}            
    
    

int main()
{
    int n, answer;
    cout<<"Enter the number, of which minimum number of suares reuired to get that number, you want?";
    cin>>n;
    int *table=new int[n+1];
    for(int i=0;i<=n;i++)
    table[i]=-1;
    table[0]=0;
    table[1]=1;
    answer=CountSquaresToGetN(n, table);
    cout<<"\n"<<answer;
    getch();
    return 0;
}
