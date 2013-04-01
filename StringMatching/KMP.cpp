#include<iostream.h>
#include<conio.h>
// KMP Algorithm ...my implementation

int x[4];
void KmpPrefix(char [],int );
int KMP(char t[], char p[], int n, int m);
int main()
{
    char p[]="Kand",t[]="Anshu Kandhari";
    int answer=KMP(t,p,14,3);  
    cout<<" Pattern found at "<<answer+1;
    getch();
    return 0;
}

int KMP(char t[], char p[], int n, int m)
{
     KmpPrefix(p,m);
     int i=0,j=0;
     while(i<n)
     {
               if(t[i]==p[j])
               {
                             if(j==m)
                             return i-j;
                             else
                             {
                                 i++;
                                 j++;
                             }
               }
               else if(j>0)
               j=x[j-1];
               else
               i++;
     }
     return -1;
}       
     
     
void KmpPrefix(char p[],int m)
{
    int k=0;
    x[k]=0;
    for(int i=1;i<m;i++)
    {
            if(p[i]==p[k])
            {
                   x[i]=++k;
            }
            else
            {
                x[i]=0;             
                k=0;
            }
    }
     for(int i=0;i<m;i++)
    cout<<x[i]<<" ";
}
                            
                  
                           
