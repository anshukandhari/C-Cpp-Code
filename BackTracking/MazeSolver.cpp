#include<iostream.h>
#include<conio.h>
#define n 5
// Solving maze problem
 int IsSafe(int m[n][n], int i, int j)
 {
      if(i>=0 && i<n && j>=0 && j<n && m[i][j]==1)
      return 1;
      
      return 0;
 }
 
 bool SolveMazeUtil(int m[n][n], int x, int y, int sol[n][n])
 {
     //base case
     if(x==n-1 && y==n-1)
     {
               sol[x][y]=1;
               return true;
     } 
     if(IsSafe(m,x,y))
     {
               sol[x][y]=1;
               if(SolveMazeUtil(m,x+1,y,sol))//try down first
               return true;
               if(SolveMazeUtil(m,x,y+1,sol))//try right after this
               return true;
               if(SolveMazeUtil(m,x-1,y,sol))
               return true;
               if(SolveMazeUtil(m,x,y-1,sol))
               return true;
               
               sol[x][y]=0;// backtracking i.e. if we do not find a path after reaching a particular node then we will mark that node and the path we traversed to reach that node as=0
               return false;
     }
     return false;
 }
  
  void print(int sol[n][n])
 {
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
             cout<<sol[i][j]<<"\t";
             cout<<"\n";
    }
}
 
 bool SolveMaze(int m[n][n])
 {
      int sol[n][n]={0,};
      if(!SolveMazeUtil(m,0,0,sol))
      return false;
      print(sol);
      return true;
 }
 


int main()
{
    int m[n][n]={{1,1,1,0,0}, {1,1,1,1,0},{0,0,1,0,1},{0,0,1,1,1}};
    SolveMaze(m);
    getch();
    return 0;
}
