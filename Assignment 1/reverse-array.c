#include<stdio.h>
int main(){
  // print reverse of the array
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("The reverse of the array is: ");
  for(int i = size-1; i >= 0; i--){
    printf("%d ", arr[i]);
  }
  return 0;

}