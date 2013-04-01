/*A frog has to cross a river. There are n rocks in the river, using which the frog can leap across the river. 
 its way across the river the frog can chose to skip a rock, but it cannot skip two consecutive rocks because that would be two far a distance
 for the frog to hop, also the from would not skip the first rock and the last rock. 
 E.g. if there are 3 rocks, 1,2,3 and 4, there could be three following routes it could take:
1,2,3,4
1,2,3,4
1,3,4
1,2,4

Write a recursive algorithm, that takes a number of rocks' and prints all the feasible paths. Ofcourse there can be other arguments too.*/
// DONE MYSELF :)))))
#include <iostream.h>
#include <conio.h>
/* with the following function I was not able to print the path from the begining
Hence I need to use a new array to store the path 
void func(int *a, int pos, int n)
{
     if(pos==n-1)
     {
      cout<<a[pos]<<"\n";
      return;
     }
     cout<<a[pos];
     if((n-pos)>2)
     func(a,pos+2,n);
     func(a,pos+1,n);
}*/
void func(int *a, int pos, int n, int *ans, int i)
{

     if(pos==n-1)
     {
      ans[i]=a[pos];
      for(int j=0;j<n;j++)
      {
              if(ans[j])
              cout<<ans[j];
      }
      cout<<"\n";
      return;
     }
     ans[i]=a[pos];
     if((n-pos)>2)
     func(a,pos+2,n,ans,i+1);
     func(a,pos+1,n,ans,i+1);
}
int main()
{
    int n,*arr;
    cout<<"Enter the number of rocks";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
    arr[i]=i+1;
    int *ans=new int[n];// this will intialize with 0 all the array elements. I dont know why. As per the net we should use the memset() for the same.
    func(arr,0,n,ans,0);
    getch();
}
