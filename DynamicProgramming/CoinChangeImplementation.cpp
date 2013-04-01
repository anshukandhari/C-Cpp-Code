#include<iostream.h>
#include<conio.h>
#define min(a,b) a<b?a:b

int denomination[]={1,5,10,20,25,50};
int table[256];
int MakingChange(int n)
{
    int ans=-1,x=0;
    if(n<0)
    return -1;
    if(n==0)
    return 0;
    
    if(table[n]!=-1)
    return table[n];
    
    for(int i=0; i<6 && denomination[i]<=n;i++)
    {
           if(ans==-1)
           ans=MakingChange(n-denomination[i]);
           else
           ans=min(ans, MakingChange(n-denomination[i]));
           
    }
    table[n]=ans+1;
    return ans+1;
} 
    
    
    
int main()
{
    int n, answer;
    cout<<"Enter the number, of which, change you want?";
    cin>>n;
    for(int i=0;i<256;i++)
    table[i]=-1;
    answer=MakingChange(n);
    cout<<"\n"<<answer;
    getch();
    return 0;
}
