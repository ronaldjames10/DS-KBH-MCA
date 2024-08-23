/*. Write a C program to pass an array to a function using Call by Value, update the array values in the function, print the array elements both in the function and in the calling function.*/
#include<stdio.h>
#define MAX 10
void updateArray(int arr[], int n){
  printf("The elements of the array in the function are: \n");
  for(int i=0; i<n; i++){
    arr[i] = arr[i] + 10;
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main(){
  int arr[MAX];
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements of the array: \n");
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  printf("The elements of the array before calling the function are: \n");
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  updateArray(arr, n);
  printf("The elements of the array after calling the function are: \n");
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}