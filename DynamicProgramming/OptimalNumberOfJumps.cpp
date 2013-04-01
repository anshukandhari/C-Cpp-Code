#include<iostream.h>
#include<conio.h>
#define MAX 0xFFFFFFFE;  
  
unsigned int jump(int *array, int n)  
{  
  unsigned int  
*result = new unsigned int[n];  
  int i, j;  
    
  //Boundry conditions  
  if (n==0 || array[0] == 0)  
    return MAX;  
      
  result[0] = 0;  //no need to jump at first element  
  for (i = 1; i < n; i++)  
  {  
    result[i] = MAX; //Initialization of result[i]  
    for (j = 0; j < i; j++)  
    {  
      //check if jump is possible from j to is  
      if (array[j] >= (i-j))      {  
  
        //check if better solution available  
        if ((result[j] + 1) < result[i])   
          result[i] = result[j] + 1;  //updating result[i]  
      }  
    }  
  }  
    
  //return result[n-1]  
  for(int i=0;i<n;i++)
  cout<<result[i]<<"\t";
  
  unsigned int answer = result[n-1];  
  delete[] result;  
    cout<<"\n";
  return answer;  
}  
int main()
{
    int arr[]={2,3,1,1,4};
    cout<<jump(arr,5);
    getch();
    return 0;
}
