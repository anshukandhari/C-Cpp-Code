#include <stdlib.h> /* atoi() */
#include <stdio.h>  /* (f)printf */
#include <assert.h>
#include<iostream.h> /* assert() */
#include <conio.h>
// write your own add function after studying digital...just use the formula.
// then see how all the other operations are dependent on add.
int add(int x, int y) 
{
    int static carry = 0;
    int result = 0;
    int i;
// because S= x^y^z and C=xy+xz+yz in n bit adder
// also we can do this using half adder. See http://www.geeksforgeeks.org/archives/18324
    for(i = 0; i < 32; ++i) 
    {
        int a = (x >> i) & 1;
        int b = (y >> i) & 1;
        result |= ((a ^ b) ^ carry) << i;
        carry = (a & b) | (b & carry) | (carry & a);
    }

    return result;
}

int negate(int x) 
{
    return add(~x, 1);
}

int subtract(int x, int y) {
    return add(x, negate(y));
}

int is_even(int n) {
    return !(n & 1);
}

int divide_by_two(int n) {
    return n >> 1;
}

int multiply_by_two(int n) {
    return n << 1;
}
int multiply(int a, int b) 

{
   int result=0;
   while(b != 0)               // Iterate the loop till b==0
   {
      if (b&01)                // Bitwise &  of the value of b with 01
        {
          result=add(result, a);     // Add a to result if b is odd .
        }
      a<<=1;                   // Left shifting the value contained in 'a' by 1 
                               // multiplies a by 2 for each loop
      b>>=1;                   // Right shifting the value contained in 'b' by 1.
   } 
   return result;
}

/*int multiply(int x, int y) 

{
    int result = 0;

    if(x < 0 && y < 0) {
        return multiply(negate(x), negate(y));
    }

    if(x >= 0 && y < 0) {
        return multiply(y, x);
    }

    while(y > 0) {
        if(is_even(y)) {
            x = multiply_by_two(x);
            y = divide_by_two(y);
        } else {
            result = add(result, x);
            y = add(y, -1);
        }
    }

    return result;
}
*/
int main(int argc, char **argv) 
{
    /*int from = 1, to = 100;
    int i, j;

    for(i = from; i <= to; ++i) {
        assert(0 - i == negate(i));
        assert(((i % 2) == 0) == is_even(i));
        assert(i * 2 == multiply_by_two(i));
        if(is_even(i)) {
            assert(i / 2 == divide_by_two(i));
        }
    }

    for(i = from; i <= to; ++i) {
        for(j = from; j <= to; ++j) {
            assert(i + j == add(i, j));
            assert(i - j == subtract(i, j));
            assert(i * j == multiply(i, j));
        }
    }*/
    int i, j;
    cout<<"Enter the numbers";
    cin>>i;
    cin>>j;
    cout<<multiply(i, j);
    getch();

    return 0;
}
/*Multiply two integers without using multiplication, division and bitwise operators, and no loops
int multiply(int x, int y)
{
   // 0  multiplied with anything gives 0 
   if(y == 0)
     return 0;
 
   // Add x one by one 
   if(y > 0 )
     return (x + multiply(x, y-1));
  
  //the case where y is negative 
   if(y < 0 )
     return -multiply(x, -y);
}*/
