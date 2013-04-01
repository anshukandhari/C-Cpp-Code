//can improve the speed by using binary search. Besides the array dp[], let's have another array c[], c is pretty special, c[i] means: the minimum value of the last element of the longest increasing sequence whose length is i.
//If element is <c[1], put that element in c[1] and put 1 in the corresponding cell in the dp array. Therefore c[1] will give the minimum element of array.
//
sz = 1;// this is the iterator for the cz array and at any point will give the count of the LIS
c[1] = array[0]; /*at this point, the minimum value of the last element of the size 1 increasing sequence must be array[0]*/
dp[0] = 1;
for( int i = 1; i < len; i++ )
 {
   if( array[i] < c[1] ) 
   {
      c[1] = array[i]; /*you have to update the minimum value right now*/
      dp[i] = 1;
   }
   else if( array[i] > c[sz] ) //if the element is greater then the last element in c array then insert it in the next position in c array and put the count of sequence in dp.
   {
      c[sz+1] = array[i];
      dp[i] = sz+1;
      sz++;
   }
   else 
   {
      int k = binary_search( c, sz, array[i] ); /*you want to find k so that c[k-1]<array[i]<c[k]*/
      c[k] = array[i];
      dp[i] = k;
   }
}
