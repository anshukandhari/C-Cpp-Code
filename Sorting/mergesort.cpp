#include<iostream.h>
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
int main()
{
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    assert(n>0);
    int *a=new int[n];
    cout<<"Enter the elements in the array: \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    divide(a,0,n-1);
    cout<<"\ Sorted  array\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
    getch();
    return 0;
}
