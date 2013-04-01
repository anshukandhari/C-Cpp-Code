#include<iostream.h>
#include<conio.h>
#include<stdio.h>
// read from http://vijayinterviewquestions.blogspot.in/2007/07/what-little-endian-and-big-endian-how.html 
// also http://www.geeksforgeeks.org/archives/801
void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2p", start[i]);
    printf("\n");
}
 
/*Main function to call above function for 0x01234567*/
int main()
{
   int i = 0x01234567;
   show_mem_rep((char *)&i, sizeof(i));
   getchar();
   return 0;
}

/*void display ( int **q, int row, int col )
{
 int i, j ;
 for ( i = 0 ; i < row ; i++ )
 {
  for ( j = 0 ; j < col ; j++ )
  printf ( "%d ",q[i][j]);// *(* q + i * col + j )) ;
  printf ( "\n" ) ;
  }
 printf ("\n" ) ;
}
int main()
{
 int **a = new int*[400];
for( int i = 0 ; i < 3 ; i++ )
  for ( int j = 0 ; j < 4 ; j++ ) 
  {
      a[i][j]=(i+1)*j;
  } 

display ( a, 3, 4) ;
*/
    
 /*printf("\n %d %d %d", ptr-p, *ptr-a, **ptr);
 *ptr++;
 printf("\n %d %d %d", ptr-p, *ptr-a, **ptr);
*++ptr;
printf("\n %d %d %d", ptr-p, *ptr-a, **ptr);
++*ptr;
printf("\n %d %d %d", ptr-p, *ptr-a, **ptr);


  /* 100;
   200;
   cout<<"hello"; 
    getch();
    return 0;
}
*/
