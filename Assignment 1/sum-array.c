#include<stdio.h>
int main(){
  // check the sum of all elements in an array
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  int sum = 0;
  for(int i = 0; i < size; i++){
    sum = sum + arr[i];
  }
  printf("The sum of the elements of the array is: %d\n", sum);

  return 0;
}