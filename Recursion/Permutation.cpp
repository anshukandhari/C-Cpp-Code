#include<stdio.h>
#include<conio.h>
#include<iostream.h>

void swap(char *p1,char *p2)
{   
int temp;
temp = *p1;
*p1 = *p2;
*p2 = temp;
}


void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n-1)
     printf("%s\n", a);
   else
   {
        for (j = i; j <n; j++)
       {
          swap(&a[i], &a[j]);
          permute(a, i+1, n);
          swap(&a[i], &a[j]);//backtrack
       }
   }
} 
/*Now what do we do if there are duplicates in the string? The trick is to sort the characters in the alphabetical order first. 
We can then ignore the duplicates easily when generate the permutation.
Just use the following code snippet in the for loop mentioned above:
     if( lastChar == str[i] ) {
            continue;
        } else {
            lastChar = str[i];
        }
where static char lastchar=str[i];       
*/
int main()

{ 
   int n;
   cout<<"Enter the length of the string :";
   cin>>n;
   char *a = new char[n];
   cout<<"\nEnter the string";
   for (int j = 0; j < n; j++)
   cin>>a[j];
   permute(a, 0, n);   
   getch();
   return 0;
}
