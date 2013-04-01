#include<iostream.h>
#include<conio.h>
#include<stdio.h>

// Input a number that ends with 3 and then find its multiple which has all 1's 
void  print_multiple_of_all_ones(int num)
{
    int count=1,rem=1;
    while(rem)
    {
        rem = ( rem*10 + 1 ) % num;
        cout<<rem<<"\n";
        count++;
    }



    while(count--)
        printf("1");

    printf("\n");
}



int main()
{
    int num;
    scanf("%d",&num);
    print_multiple_of_all_ones(num);
    getch();
    return 0;
}
/*class x
{
      static int a;
     public:
      ~x()
      {
          cout<<"Running";
          cout<<a<<"\n";
          getch();
      }
      
         static void printt()
              {
                 cout<<a<<"\n";
              }
};
int x :: a =0;
static int c;
int main()
{
    
    x obj;
    obj.printt();
    int a,b,c;
    
    a=6;
    b=3;
    
    cout<<a<<"\n";
    getch();
    return 0;
}
*/
