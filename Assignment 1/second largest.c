#include<stdio.h>
int main(){

  //largest and second largest element in an array using one loop.
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i<size; i++){
    scanf("%d", &arr[i]);
  }

  int largest = arr[0];
  int second_largest = arr[0];
  for(int i=0; i<size; i++){
    if(arr[i]> largest){
      second_largest = largest;
      largest = arr[i];
    }
    else if(arr[i]>second_largest && arr[i]!=largest){
      second_largest = arr[i];
    }
  }
  printf("The largest element is: %d\n", largest);
  printf("The second largest element is: %d\n", second_largest);

return 0;
}