#include<iostream.h>
#include<conio.h>
//copied from http://rosettacode.org/wiki/Sorting_algorithms/Shell_sort and then modified to understand
void shell_sort (int *a, int n) {
    int h, i, j, k;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            k = a[i];
            for (j = i; j >= h; j -= h) 
            {
                if(k < a[j - h])
                {
                a[j] = a[j - h];
               
                }
                else 
                break;
            }
            a[j] = k;
        }
    }
}
 
int main (int ac, char **av) {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    shell_sort(a, n);
    
    for(int i=0;i<10;i++)
    cout<<a[i]<<"\n";
    getch();
    return 0;
}

