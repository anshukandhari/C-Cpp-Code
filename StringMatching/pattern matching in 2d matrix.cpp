#include<iostream.h>
#include<conio.h>
// here I also learned how to pass 2-d array as function arguments......before reading this try on your own.
// Logic: go to each element in matrix. Check whether we need to find this or not. If yes, then reduce the count of that element in shouldfind array. Check the overall count.
// if it is equal to the length of the string to be found then return with true.
int findpattern(char mat[][5],int row,int col,char pat[],int len)
{
    char shouldfind[256]={0,};
    int count=0;
    for(int i=0;i<len;i++)
    shouldfind[pat[i]]+=1;
    
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    {
            if(shouldfind[mat[i][j]]!=0)
            {
               shouldfind[mat[i][j]]--;
               count++;                         
            }
            if(count==len)
            return 1;
    }
    return 0;
}
int main()
{
    char mat[][5]={{'A','C','P','R','C'},{'X','S','O','P','C'},{'V','O','V','N','I'},{'W','G','F','M','N'},{'Q','A','T','I','T'}};
    char pat[]="MICROSOFT";
    int result=findpattern(mat,5,5, pat,9);
    cout<<result;
    getch();
    return 0;
}

