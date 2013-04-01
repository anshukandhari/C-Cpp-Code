#include<iostream.h>
#include<conio.h>
//http://www.leetcode.com/2010/10/amazon-bar-raiser-interview-question.html
void findColName(int j);
int main()
   {
          int n;
           cout<<"enter the column number: ";
           cin>>n;

           //String s="ABZ";
           //int i=s.charAt(0);
           //System.out.println(i);

           findColName(n);
           getch();
           return 0;
   }    

/*int findColumnNumber(String s)
    {
        int base = 26, result = 0, digit = 0;
        for (int i = 0; i < s.length(); i++) {
            digit = s.charAt(i) - 'A' + 1;
            result = base * result + digit;
        }
        return result;
    }

DO CONSIDER THIS :
  */          
  /*          
            void findColName(int n) 
{
  char x= ('a' + n%26);
  n = n/26;
  while (n != 0) {
    cout<<(char)('a' + (n-1)%26);
    cout<<x;
    n = (n-1)/26;
  }
  
}

*/
void findColName(int j)
    {
            if(j==0)
              return;
       findColName((j-1)/26);
       cout<< (char)((j-1)%26+'A');

    }

