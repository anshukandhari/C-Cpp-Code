/*String Similarity (25 Points)

For two strings A and B, we define the similarity of the strings to be the length of the longest prefix common to both strings. For example, the similarity of strings "abc" and "abd" is 2, while the similarity of strings "aaa" and "aaab" is 3.

Calculate the sum of similarities of a string S with each of it's suffixes.

Input:
The first line contains the number of test cases T. Each of the next T lines contains a string each.

Output:
Output T lines containing the answer for the corresponding test case.

Constraints:
1 <= T <= 10
The length of each string is at most 100000 and contains only lower case characters.

Sample Input:
2
ababaa
aa

Sample Output:
11
3

Explanation:
For the first case, the suffixes of the string are "ababaa", "babaa", "abaa", "baa", "aa" and "a". The similarities of each of these strings with the string "ababaa" are 6,0,3,0,1,1 respectively. Thus the answer is 6 + 0 + 3 + 0 + 1 + 1 = 11.

For the second case, the answer is 2 + 1 = 3.

*/
#include<iostream>
#include<assert.h>

char a[100001];
int CalculateSimilarity(char p[],int m)
{
    int k=0,j,*x, count=0;
    x=new int[m];
    x[k]=m;
    for(int i=1;i<m;i++)
    {
            j=i;
            while(p[j]==p[k] && j<m)
            {
                   j++;
                   k++;
            }
            x[i]=j-i;             
            k=0;            
    }
    for(int i=0;i<m;i++)
        count+=x[i];
    return count;
}
int main()
{
    int t,*ans,x=0;
    scanf("%d",&t);
    assert(t>0 && t<=10);
    ans=new int[t];
    while(t>0)
    {
        int j=0;
        scanf("%s",&a);
        while(a[j++]);
        j--;
        ans[x++]=CalculateSimilarity(a,j);
        t--;
    }
   for(int i=0;i<x;i++)
    printf("%d\n", ans[i]);
    
    return 0;
}
