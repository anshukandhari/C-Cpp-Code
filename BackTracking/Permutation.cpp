#include<stdio.h>
#include<conio.h>
#include<iostream.h>

void swap(int *,int*);
void permute(void);
int noofpermutations();
void display(void);

int m,n,noofterms,count=0;
char a[100];

void swap(char *p1,char *p2)
{   
int temp;
temp = *p1;
*p1 = *p2;
*p2 = temp;
}

int noofpermutations()
{   
    int permutations=1,x;
    for(x=1;x<=noofterms;x++)
    permutations=permutations*x;
    return permutations;
}

void display()
{   
    int x;
    for(x=0;x<noofterms;x++)
        printf("%d  ",a[x]);    
    printf("\n");
    count++;
}

void permute()
{   
    int x,y,n;
    n=noofpermutations();
    while(count<n)
    {
        for(y=0;y<noofterms-1;y++)
        {
            swap(&a[y],&a[y+1]);
            display();
        }
        swap(&a[0],&a[1]);
        display();
        for(y=noofterms-1;y>0;y--)
        { 
            swap(&a[y],&a[y-1]);
            display();
        }
        swap(&a[noofterms-1],&a[noofterms-2]);
        display();
    }
}

int main()

{ 

int x;      
printf("Enter no. of terms : ");
scanf("%d",&noofterms);
printf("Enter the terms : ");
for(x=0;x<noofterms;x++)
scanf("%c",&a[x]);// if I use %c then it will consider pressing enter from keyboard as a character input also. Try this!!!
printf("\n%d",x);
printf("\nPermutations are : \n");
permute();
printf("\nTotal Permutations : %d",count);
getch();
return 0;
}
