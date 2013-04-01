#include<iostream.h>
#include<conio.h>
int counttree( int n)
{
    if(n<=1)
    return 1;
    else
    {
        int sum=0, root, left, right;
        for(int root=1;root<=n;root++)
        {
                left= counttree(root-1);
                right=counttree(n-root);
                sum+=left*right;
        }
        return sum;
    }
}   
        
int main()
{
    int number=-1;
    while (number!=0)
    {
        
        cin>>number;
      cout<<"The number of BSTs possible are"<<counttree(number)<<"\n";
     }
      getch();
  return 0;
}   
