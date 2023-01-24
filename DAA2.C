// question 2 week1
#include<stdio.h>
void binary_search(int arr[] , int l , int r , int n , int key )
{
  int no_comparision = 0 , flag = 0 ;
  while(l <= r)
  {
      no_comparision++ ;
      int mid = (l+r)/2;
      if(key == arr[mid]){
          printf("present %d",no_comparision);
          flag = 1 ;
          break ;
      }
      else if(key > arr[mid]){
          l = mid+1 ;
      }
      else{
          r = mid-1 ;
      }   
  }
  if(flag == 0 ){
      printf("not present %d",no_comparision);
  }
}
int main()
{
int i , j , n , N  ,  key ;
 scanf("%d",&N);
 while(N>0)
 {
     scanf("%d",&n);
     int arr[n]  ;
     printf("enter the elements\n");
     for(i = 0 ; i < n ; i++ )
     {
         scanf("%d",&arr[i]);
     }
     printf("enter the key:\n");
     scanf("%d",&key);
     binary_search( arr , 0 , n-1 , n , key);
     N-- ;
 }
 return 0 ;
}