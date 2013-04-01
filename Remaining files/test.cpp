#include<stdio.h>
#include<conio.h>
#define max(a, b) ((a) > (b)?(a):(b))
//int max, min;
int main()
{
        
       char *s="Hello World";
        char s1[20], s2[20];
        int len = sscanf(s,"%s",s1);
        printf("%s : %d", s1, len);
        getch();         
        return 0;
}

