#include<iostream.h>
#include<conio.h>
#define MAX 256  
void minlengthwindow(char input[], char chars[], int &start, int &finish) ;
int main()
{
    char p[]="ABBACBAA",t[]="AAB";
    int a=0,b=7;
    minlengthwindow(p,t,a,b);
    getch();
    return 0;
}

void minlengthwindow(char input[], char chars[], int &start, int &finish)  
{  
int shouldfind[MAX] = {0,};  
int hasfound[MAX] = {0,};  
int cnt = 0;  
int minwindow = INT_MAX;  
  
int charlen = strlen(chars);  
for (int i=0; i< charlen; i++)  
shouldfind[chars[i]] += 1;  
  
int iplen = strlen(input);  
start = 0;  
finish = iplen;  
int j = 0;  
  
for (int i=0; i< iplen; i++)  
{  
if (!shouldfind[input[i]])  
 continue;  
hasfound[input[i]] += 1;  
  
if (shouldfind[input[i]] >= hasfound[input[i]])  
 cnt++;       
  
if (cnt == charlen)  
{  
 while (shouldfind[input[j]] == 0 || hasfound[input[j]] > shouldfind[input[j]])  
 {    
  if (hasfound[input[j]] > shouldfind[input[j]])  
           hasfound[input[j]]--;  
        j++;  
 }  
 if (minwindow > (i - j +1))  
 {  
  minwindow = i - j +1;  
  finish = i;  
  start = j;  
 }  
}  
}  
cout << start << "  " << finish << endl;  
}  
