#include<stdio.h>
int main(){
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i<size; i++){
    scanf("%d", &arr[i]);
  }
  printf("The elements of the array are: ");
  for(int i = 0; i<size; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}