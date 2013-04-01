#include<stdio.h>
#include<conio.h>
static int isUniqueChars(char str[]) 
{
int checker = 0;
for (int i = 0; i < str.length(); ++i) {
int val = str.charAt(i) - ‘a’;
if ((checker & (1 << val)) > 0) 
return 0;
checker |= (1 << val);
}
return 1;
}
int main()
{
    char arr[10];
    scanf("%s",&arr);
    isUniquechars(arr);
    getch();
    return 1;
}
