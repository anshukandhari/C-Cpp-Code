#include<iostream.h>
#include<conio.h>
int n=5;
// I dont know how to pass 2 d array as a function parameter
void JPEG(int a[][5])
{
     int down=1, i=0, j=1;
     cout<<a[0][0];
     while(!((i==n-1) && (j==n-1)))
     {
          cout<<a[i][j];
          if(down==1)
          {
                while(j!=0)// these conditions should be changed after half of the array is processed. eg. in 4x4 matrix it will give error after it reaches 8 because of the next while condition.
                {
                           i++;
                           j--;
                           cout<<a[i][j];
                }
                down =0;          
          }
          else
          {
                while(i!=0)
                {
                           j++;
                           i--;
                           cout<<a[i][j];
                }
                down =1;          
          }
          if(i==0 || i==n-1)
          j++;
          else 
          i++;
     }
     cout<<a[n-1][n-1];
}
int main()
{
    int i,j,count=1;
    cout<< "Enter the number \n";
    cin>> n;
    int a[5][5];
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    a[i][j]=count++;
    
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cout<<a[i][j]<<"\t";
    
    JPEG(a);
    
    getch();
    return 0;
}
    
