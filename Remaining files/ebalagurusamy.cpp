#include<iostream.h>
#include<conio.h>
#include<fstream.h>
class x
{
      char name[19];
      int cost;
      public:
             void readdata();
             {
                  cout<<"\nEnter name";
                  cin>>name;
                  cout<<"\nEnter cost";                  
                  cin>>cost;
             }
             void writedata();
             {
                  cout<<name<<endl<<cost;
             }
};             
int main()
{
    x ox[3];
    fstream file;
    file.open(("A.txt"|ios::in|ios:out);
    cout<<"Enter the details of the file\n";
    for(int i=0;i<3;i++)
    {
            ox[i].readdata();
            cin>>name;
    of<<name;
    return 0;
}
/* Operator overloading 
class x
{
      int v[3];
      public:
      x(int j)
      {
             for(int i=0;i<3;i++)
             {
                     v[i]=j++;
                     cout<<"Values are"<<v[i]<<"\n";
             }
      }
       void print()
       {
            for(int i=0;i<3;i++)
             cout<<"Values are"<<v[i]<<"\n";
       }
       void operator=(x b);
};
void x::operator=(x b)
{
     for(int i=0;i<3;i++)
     v[i]=b.v[i];
}

      
          
int main()
{
    x obj1(1),obj2(2);
    obj1=obj2;
    obj1.print();
    getch();
    return 0;
}
*/
