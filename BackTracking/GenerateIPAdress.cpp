#include <stdio.h>
#include<conio.h>
 
void generateIPUtil( char* str, char* output, int depth, int countDot, int val )
{
        if( !*str )
        {
                output[depth] = '\0';
                if( countDot == 3 && output[depth-1] != '.' )
                        printf( "solution is :%s\t\t", output );
        }
        else
        {
                output[depth] = *str;
               // printf( "%s\n", output);
                val = val * 10 + *str - '0';
                if( val <= 255 )
                {
                if( countDot < 3)// Now there are two cases, either I will put the dot now or I wont
                {
                        output[depth + 1] = '.';
                         
                        generateIPUtil( str+1, output, depth+2, countDot+1, 0 );// case 1: I will put the dot now.
                }
                generateIPUtil( str+1, output, depth+1, countDot, val );// case 2: I will not put the dot now.
                }
        }
}
 
void generateIP( char* str )
{
        char output[30];
 
        generateIPUtil( str, output, 0, 0, 0 );
}
 
int main()
{
        char str[] = "12525511135";
 
        generateIP( str );
        getch();
        return 0;
}
