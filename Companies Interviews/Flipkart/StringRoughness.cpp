#include<iostream.h>
#include<conio.h>
/*
roughness=max frequecy(c1)- minfrequency(c2)
We have to calculate min possible roughness after n deletion operation. 
Algorithm (My own):
1. Store the frequency of each character. Also store the value of number of different character.    
2. if the number of deletions allowed > current roughness            
then delete the character with highest frequency and calcucate c1, c2 again
*/
int minindex, maxindex,ssi=-1;// ssi is the index of the second smallest frequency element
int FindMax(int *a)
{
    int x=0;
    for(int i=0;i<256;i++)
    if(a[i]>x)
    {
     x=a[i];
     maxindex=i;
    }
    return x;
}
int FindMin(int *a)
{
    int x=10000;
    for(int i=0;i<256;i++)
    if(a[i]<x && a[i]!=0)
    {
              ssi=minindex;
              x=a[i];
              minindex=i;
    }
    return x;
}

int main()
{
    char s[1000];
    int a[256],n, c1, c2, r, count=0;// n is number of deletions that can be done; c1, c2 is the max, min frequency value respectively. 
    cin>>s;
    cin>>n;
    for(int i=0;i<256;i++)
    a[i]=0;

    for(int i=0;s[i]!=NULL;i++)
    {
            if(a[s[i]]==0)
            count++;// count will keep the track of number of different character in the string at any time
            a[s[i]]+=1;
    }
    
    c1=FindMax(a);
    c2=FindMin(a);
    r=c1-c2;
    while(n>0 && c1>0 && c2>0)
    {
        if(n<r && count>2 && ((c1-a[ssi])<=(r-n)) && (c2<=n))
        {
         n-=c2;
         a[minindex]=0;
         c1=FindMax(a);
         c2=FindMin(a); 
        }
        else 
        {
            a[maxindex]-=1;
            c1=FindMax(a);
            c2=FindMin(a); 
            n--;
        }
    }
        
               
     cout<<"\n"<<c1;
     cout<<"\n"<<c2;   
     cout<<"\n"<<c1-c2;                             
     getch();
}

/*int main()
{
    char s[1000];
    int a[256],n, c1, c2, r;
    cin>>s;
    cin>>n;
    for(int i=0;i<256;i++)
    a[i]=0;
    for(int i=0;s[i]!=NULL;i++)
    a[s[i]]+=1;
    c1=FindMax(a);
    c2=FindMin(a);
    
    while(n>0)
        {
              if(c2>n)
                {
                      c2-=n;
                      break;
                }
                else
                {
                    n-=c2;
                    a[minindex]=0;
                    c2=FindMin(a);
                }
        }
     cout<<c1-c2;                             
     getch();
}
*/
