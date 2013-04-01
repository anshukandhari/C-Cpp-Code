#include<iostream.h>
#include<conio.h>
class G
{
      public:
      int x;
      G(int z)
      {
          x=z;
          cout<<x;
      }
};
class p1: virtual public G
{
      public:
      int y;
      p1(int z):G(z)
      {
          y=z;
          cout<<y;
      }
};
class p2:virtual public G
{
      public:
      int w;
      p2(int z):G(z+32)
      {
          w=z;
          cout<<w;
      }
};
class d: public p1, public p2
{
      public:
      int a;
      d(int p,int q,int r,int s): G(p),p1(q),p2(r),a(s+p)// Virtual base class constructor should be intialized by the last derived class and not 
      //by the immeadite derived class. Though the call to it shoulb be present in the immediate driving classes
      {
          
          cout<<a;
      }
};
int main()
{    
    
    d od(7,8,9,10);
    getch();
}
