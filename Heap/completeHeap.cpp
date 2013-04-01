#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void exchange(int *a,int *b) 
{
     *a^=*b;
     *b^=*a;
     *a^=*b;
}
void print(int a[],int n)
{
     for(int j=0;j<n;j++)
             cout<<a[j]<<"\t";
            cout<<"\n";
}  
void makeheap(int a[],int i,int n)
{
    int left_child=2*i+1, right_child= 2*i+2, largest=i;
    if(left_child<n && a[left_child]>a[i])    
                    largest=left_child;
    
     if(right_child<n && a[right_child]>a[i])  
        {
              if(largest==left_child && a[left_child]>a[right_child])
                       largest=left_child;
              else     
                      largest=right_child;
        }
     if(largest!=i)
     {
      exchange(&a[i], &a[largest]);
      makeheap(a, largest, n);
     }
}
void buildheap(int a[], int n)
{
     for(int i=n/2;i>=0;i--)
     makeheap(a,i,n);
}                    

void heapsort(int a[], int n)
{
    buildheap(a,n);
    print(a,n);
    for(int i=n-1;i>=2;i--)
    {
          exchange(&a[i], &a[0]);   
          makeheap(a,0,--n);
    }
}
int main()
{
    int arr[]={5,3,17,10,84,19,6,22,9},n=9;
    heapsort(arr,n);
    print(arr,n);    
    getch();
    return 0;
}
