/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<conio.h>
#include<assert.h>
using namespace std;

int CalculateStringReduction(int *a,int l)
{
    
        if((a[0]==0 && a[1]==0)||(a[0]==0 && a[2]==0)||(a[2]==0 && a[1]==0))
            return l;
        else if((a[0]%2==0 && a[1]%2==0 && a[2]%2==0)||(a[0]%2==1 && a[1]%2==1 && a[2]%2==1))
            return 2;
        else
            return 1;
    
}
int main()
{
    int t;
    scanf("%d", &t);
    assert(t>0 && t<=100);
    int *ans=new int[t],x=0;
    while(t>0)
    {
        int a[3]={0,},j=0,l;
        char s[100];
        cin>>s;
        while(s[j++]);
        l=--j;
        
        j--;
        while(j>=0 && (s[j]-'a')<=3 && (s[j]-'a')>=0)
          {

                   a[s[j]-'a']+=1;
                   j--;
          }
        for(int i=0;i<3;i++)
        cout<<a[i]<<"\n";
        ans[x++]=CalculateStringReduction(a,l);
        t--;
     }
    for(int i=0;i<x;i++)
        cout<<ans[i]<<"\n";
    getch();         
   return 0;   
}
