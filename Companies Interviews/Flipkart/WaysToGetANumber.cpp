#include<iostream.h>
#include<conio.h>
static int count;
void Change( int * amounts, int highest, int sum , int n)
{    
    if (sum == n)
	{
	    count++;
	    return;
	} 
	//
	// See if we have too much.
	//
	if (sum > n)
	{
	    return;
	}
	//
	// Loop through amounts.
	//
	for(int i=0;i<3;i++)
	{
	    // Only add higher or equal amounts.
	    //
	    if (amounts[i] >= highest)
	    {
		Change(amounts, amounts[i], sum + amounts[i], n);
	    }
	}
}
int main()
{
    int n , amounts[]= { 1, 2, 3};
	cout<<"Enter the value you want to make: ";
	cin>>n;
	Change(amounts, 0, 0, n);
	cout<<count;
    getch();
	return 1;
}
