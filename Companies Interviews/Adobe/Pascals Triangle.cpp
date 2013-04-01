#include <iostream.h>
#include<conio.h>
// Read from geeksforgeeks. The reason for the following formula is 
/*C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line - i + 1) / i
*/
void PrintPascal(int n)
{
   for (int line = 1; line <= n; line++)
  {
    int C = 1;  // used to represent C(line, i)
    for (int i = 1; i <= line; i++)  
    {
      printf("%d ", C);  // The first value in a line is always 1
      C = C * (line - i) / i;  
    }
    printf("\n");
  }
             
}

int main()
{
    int n;
    cout<<"\n Enter the level of pascals triangle:  ";
    cin>>n;
    PrintPascal(n);     
    getch();
    return 0;
}
