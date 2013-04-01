#include <iostream.h> 
#include <conio.h> 
// http://stackoverflow.com/questions/1121160/how-would-you-count-the-number-of-bits-set-in-a-floating-point-number
int NumberOfSetBits(int v)
{
    int sum;
    while(v)
    {
            if(v&1)
            sum++;
            v=v>>1;
    }
    
   /*  int c;
     for(c = 0; v; c++)
    {
            v &= v - 1; // clear the least significant bit set
    }/*
   /* i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return ((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
    */
    return sum;
}
int main(void) 
{
  float f;
  cin>>f;  
  cout<< NumberOfSetBits(*(int*) &f); 
  getch();
  return 0;
}
