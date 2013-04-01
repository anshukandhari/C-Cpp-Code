#include<iostream.h>
#include<conio.h>
#include<math.h>
// From http://www.geeksforgeeks.org/archives/16703
/* Took the hint that if number is of the form 2^b -1 e.g., 1,3,7,15.. etc, the number of set bits is b * 2^(b-1). 
so I went till the max power of 2 which is <= the given number. Then I added 1 to get the number of ones in 2^b, which is always =1. Now I called the function again 
for the differece of the calculated answer and the expected answer. But in this difference a 1 is increased for each number */
int FindTotalSetBits(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    else
    {
            
        int b=floor(log2(n));
        int maxValue=pow(2,b);
        return b*pow(2,b-1)+1+(n-maxValue)+ FindTotalSetBits(n-maxValue);
    }
}
        
    
int main()
{
    int n;
    cout<<"Enter the number";
    cin>>n;
    cout<<FindTotalSetBits(n);
    getch();
    return 0;
}
