#include<stdio.h>
#include<conio.h>

void encrypt(char *message)
{
  char c;
  while (*message)
  {
    *message = *message ^ 31;
     message++;
  }
  
}
int main()
{
    char a[]="Anshu",
    encrypt(a);
    printf(a);
   
    getch();
    return 0;
    
}
