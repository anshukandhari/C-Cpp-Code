//kth smallest element in the union of 2 arrays:
1. Check that k<len(A)+ len(B)
2. go to mid=kth/2 element of both the arrays.
3. if(A[mid]>B[mid]=> the new range for A will be 0 to mid and for B mid-len(B)
4. newmid= mid/2; A's mid = 0+newmid, B's mid = newmid +mid;
5. if any time A[mid] is the first element of A i.e. A[0] && A[mid]< B[mid] then B[k] is the kth smallest element. Just return that.
6. if we have array of 2 left in A and in B each, then select the 2nd smallest among them.

void kthsmallest(int a[],int n, int b[],int m, int k,int a[0], int b[0])
{
   /* This checking is done before calling this function
     if(k> m+n)
     {
           cout<<"wrong k value";
     }
   /*  
     int mid=k/2;
     if(mid>m &&mid>n)
     {
         while(mid>0)
         {                     
                     if(a[mid]>b[mid])
                     {
                       if(a[mid]==a[0];
                       return 
                       kthsmallest(a,mid,b+mid,m-mid,k/2);
                     else 
                      kthsmallest(a+mid,n-mid,b,mid,k/2);
         }           
     }
