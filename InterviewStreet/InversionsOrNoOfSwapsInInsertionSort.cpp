/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream.h>
#include<conio.h>
// took so much time coz of bad merge algo. Now I corrected it. It solved 7 cases out of 10 @interviewstreet. 
//Also refer http://www.geeksforgeeks.org/archives/3968
void conquer(int *a,int s,int m, int e,long long &count)
{
     int l1=m-s+1,l2=e-m,*a1,*a2;
     a1=new int[l1];
     a2=new int[l2];
     for(int i=0;i<l1;i++)
     a1[i]=a[s+i];
     for(int i=0;i<l2;i++)
     a2[i]=a[m+i+1];
     
     
     
     int j=0,k=0;
     for(int i=s;i<=e;)
     {
               
           if(a1[j]<=a2[k])
           a[i++]=a1[j++];
             
           else
           {
            a[i++]=a2[k++];
            count+=l1-j;
           }                 
           while(j==l1 && k<l2)
           {
                   a[i++]=a2[k++];
                    count+=l1-j;
           }
           
           while(k==l2 && j<l1)
           a[i++]=a1[j++];
             
     }
    
}
void divide(int *a,int s,int e, long long &count)
{
     if(s<e)
     {
            int m=s+(e-s)/2;
            divide(a,s,m,count);
            divide(a,m+1,e,count);
            conquer(a,s,m,e,count);
            
     }
}
int main()
{
    int t,x=0;
    scanf("%d", &t);
    long long *ans=new long long[t];
    while(t!=0 && t>0 && t<6)
        {
            int n;
            long long count=0;
            scanf("%d", &n);
            if(n>0 && n<=100000)
            {
                int *a=new int[n];
                for(int i=0;i<n;i++)
                   scanf("%d", &a[i]);
                   divide(a,0,n-1,count);
                /*for(int j=0;j<n-1;j++)
                for(int i=j+1;i<n;i++)
                if(a[i]<a[j])
                {
                             int temp=a[i],k;
                             for(k=i;k>j;k--)
                             {
                                 count++;
                                 a[k]=a[k-1];
                             }
                             a[k]=temp;
                
                }*/
            }
            t--;
            ans[x++]=count;
        }
        for (int i=0;i<x;i++)
        printf("%d\n", ans[i]);
        
   getch();  
   return 0;   
}
