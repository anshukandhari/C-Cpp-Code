#include <iostream.h> 
#include <conio.h> 
void findConsecutiveCharString (char str[], int size) {
  int sindex = 0, i, templen = 1 ;
  int maxlen = 1 , index = 0;
  for ( i = 1 ; i < size ; i ++ ) {
    if ( str[i] == (str[sindex]+templen) )
      templen ++ ;
    else {
      if ( templen > maxlen ) {
        index = sindex ;
        maxlen = templen ;
      }
      sindex = i ;
      templen = 1 ;
    }
  }
  printf ( "\nStart index = %d, maxLength = %d", index, maxlen) ;
}
int main(void) 
{
  int n;
  char *s;
  cout<<"Enter the size of string: ";
  cin>>n;
  s=new char[n];
  cout<<"Enter the string: ";
  cin>>s;
  findConsecutiveCharString(s,n);
  getch();
  return 0;
}
