/*#include<iostream.h>
#include<conio.h>

int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
int n=sizeof(a)/sizeof(a[0]);
int count=0,row_size=n/3;
void swap(int *a, int *b) 
{
     *a=*a^*b;
     *a=*a^*b;
     *a=*a^*b;
}
int main()
{

	int j=1,loc=j;
	for(int i=1;i<n-1;i++)
	{
		loc=(3*loc+loc/row_size)%n;
		if(j!=loc)
			swap(&a[j],&a[loc]);
		else
		{
			j++;
			loc=j;
		}
	}
	for(int pos=0;pos<n;pos++)
		cout<<"  "<<a[pos];
	getch();
	return 0;
}
#include<iostream.h>
#include<conio.h>

void transpose(int a[], int n);
void swap(int *a, int *b) 
{
     *a=*a^*b;
     *a=*a^*b;
     *a=*a^*b;
}
int main() 
	{
	
		int array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
				
		
	
		transpose(array,12); // n = 4
		for(int i =0 ;i<12;i++)
        cout<<array[i]<<"\n";
        getch();
	    return 0;
	}


void transpose(int a[], int n) 
	{
			for(int i =0 ;i<n;i++)
			{
                  if(i%n <= i/n)
				{
					continue;
				}
				int secondIndexToSwap = (i%n)* n + i/n;   
                    if(secondIndexToSwap<n)                 
                    swap(&a[i],&a[secondIndexToSwap]);
                    
			}
	}
	//			
//				if(i%n <= i/n)
//				{
//					continue;
//				}
//				
//					int secondIndexToSwap = (i%n)* n + i/n;
//					swap(a[i], a[secondIndexToSwap]);
//				
//			

*/
#include <stdio.h>
#include <conio.h> 
int get_index(int idx, int N) {
    return (idx % 3) * N + (idx / 3);
}
 
void swap(int *a,int *b)
{
        int t=*a;
        *a=*b;
        *b=t;
}
 
void transform_array2(int *s, int len) {
    int N = len / 3,i;
    for(i = 0; i < len; i++) {
        int new_idx = get_index(i, N);
        while(new_idx < i) {
            new_idx = get_index(new_idx, N);
        }
        printf("i: %d; new_idx: %d\n", i, new_idx);
        swap(&s[i], &s[new_idx]);
    }
    for(i = 0; i < len; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}
 
int main()
{
        int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
        transform_array2(arr,12);
        getch();
        return 0;
}
