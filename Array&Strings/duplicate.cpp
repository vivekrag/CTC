#include<stdio.h>
#include<stdlib.h>
 
void printRepeating(int arr[], int size)
{
  //int *count = (int *)calloc(sizeof(int), (size - 2));
  int *count = new int[size];
  int i;
   
  printf("Repeating elements are ");
  for(i = 0; i < size; i++)
  {  
    if(count[arr[i]] == 1){
      printf(" %d ", arr[i]);
      count[arr[i]]++;
    }
    else
     count[arr[i]]++;
  }
  delete [] count;    
}     
 
int main()
{
  int arr[] = {7,8, 4, 5, 2, 3, 1,3,3,3,3,4,4,5,5,9};
  int arr_size = sizeof(arr)/sizeof(arr[0]);  
  printRepeating(arr, arr_size);
  getchar();
  return 0;
}
