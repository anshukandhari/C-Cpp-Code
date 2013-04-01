/*
There are N problems numbered 1..N which you need to complete. You've arranged the problems in increasing difficulty order, and the ith problem has estimated difficulty level i. You have also assigned a rating vi to each problem. Problems with similar vi values are similar in nature. On each day, you will choose a subset of the problems and solve them. You've decided that each subsequent problem solved on the day should be tougher than the previous problem you solved on that day. Also, to not make it boring, consecutive problems you solve should differ in their vi rating by at least K. What is the least number of days in which you can solve all problems?

Input:
The first line contains the number of test cases T. T test cases follow. Each case contains an integer N and K on the first line, followed by integers v1,...,vn on the second line.

Output:
Output T lines, one for each test case, containing the minimum number of days in which all problems can be solved.

Constraints:
1 <= T <= 100
1 <= N <= 300
1 <= vi <= 1000
1 <= K <= 1000

------------------------------------------

Sample Input:
2
3 2
5 4 7
5 1
5 3 4 5 6

Sample Output:
2
1

Explanation:

For the first example, you can solve the problems with rating 5 and 7 on the first day and the problem with rating 4 on the next day. Note that the problems with rating 5 and 4 cannot be completed consecutively because the ratings should differ by at least K (which is 2). Also, the problems cannot be completed in order 5,7,4 in one day because the problems solved on a day should be in increasing difficulty level.

For the second example, all problems can be solved on the same day.
*/
#include<iostream>
#include<conio.h>
#include<assert.h>
void conquer(int *a, int s,int m, int e)
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
           a[i++]=a2[k++];
                             
           while(j==l1 && k<l2)
                a[i++]=a2[k++];
           
           while(k==l2 && j<l1)
           a[i++]=a1[j++];
     }
}
void divide(int *a, int s,int e)
{
     if(s<e)
     {
            int m=s+(e-s)/2;
            divide(a,s,m);
            divide(a,m+1,e);
            conquer(a,s,m,e);
     }
}
int NoOfDays(int *a, int n, int d)
{
    int i=0,count=0;
    divide(a,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d",a[i]);
    for(int i=0;i<n;i++)
    {
         if(a[i]==-1)
         continue;
         
         int k=i;
         for(int j=i+1;j<n;j++)
         {
                if(((a[j]-a[k])>=d || (a[j]-a[k])==0) && (a[j]!=-1))
                {
                               a[k]=-1;                               
                               k=j;
                }
         }
         a[k]=-1;
         count++;
    }
    
    return count;
}
int main()
{
    int t, *ans,n, k,*a,x=0;
    scanf("%d", &t);
    ans=new int[t];
    while(t>0 && t<=100)
    {
        scanf("%d %d", &n, &k);
        if(n>0 && n<=300)
        {
            if(k>0 && k<=1000)
            {
                a=new int[n];
                for(int i=0;i<n;i++)
                {
                    scanf("%d", &a[i]);
                    assert(a[i]<=1000 && a[i]>0);
                }
                ans[x++]=NoOfDays(a,n,k);
            }    
        }
        t--;
    }
    for(int i=0;i<x;i++)
    printf("%d\n",ans[i]);
    getch();
    return 0;
}
          
              
    
