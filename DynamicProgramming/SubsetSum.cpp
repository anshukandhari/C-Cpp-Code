#include<iostream.h>
#include<conio.h>

void  subsetSum(int *A, int n, int T);
int main()
{
    int arr[]={3,2,4,19,7,13,10,6,11};
    subsetSum(arr,9,65);
    getch();
    return 0;
}


void  subsetSum(int *A, int n, int T)
{
 int S[n+1][T+1];
 
 for(int i=0;i<=n;i++)
        for(int j=0; j<=T; j++)
        S[i][j]=0;
        
    for (int i = 0; i <= n; i ++)
        S[i][0] = 1;
        
  
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=T; j++)
        {
            if(S[i-1][j] || S[i-1][j-A[i]])
               S[i][j]=1;            
        }
    }
    cout<<S[n][T];


}
/*
void subsetSum ( int a[] , int n , int sum ){
    int *s = new int[sum+1];

    for(int i=0; i<=sum; i++) s[i]=0;
    s[0]=1;

    // assume state is s[i] where s[i] = 1 if sum 'i' can be hit otherwise 0 if it is not possible.
    // think about next state.....? 
    // base state is s[0] = 1 which is always hit which an empty subset.
    // any sum can be hit by a number a[i] if s[j-a[i]] = 1
    // so we run two for loops outer for loop to consider every number a[i]
    // and the inner for loop for checking sum.
    // therefore ... s[j] = s[j] | s[j-a[i]];
    // i.e. s[j] can be hit by a[i] only when if s[ j - a[i] ] is set. :)

    for(int i=0; i<n; i++)
        for(int j=sum; j>=a[i]; j--)
            s[j] |= s[j-a[i]];

    cout<< s[sum];
}

*/
