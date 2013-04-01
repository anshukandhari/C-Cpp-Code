#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include <string.h>

   
      
int main ()
{//
//  char str[] ="This is a simple string";
//  char * pch;
//  pch = strstr (str,"simple");
//  strncpy (pch,"sample",6);
//  puts (str);
    char name[20];
    cout<<"Enter city :";
    cin>>name;
    cout<<"City is "<<name;
    cout<<"Enter city name again: \n";
    cin>>name;
    cout<<"City name now is:"<<name<<" \n";
    getch();
    return 0;
}
