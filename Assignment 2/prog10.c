/*Write a C program to search an element in an Array using dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,i,*ptr, target;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  ptr = (int*)malloc(n * sizeof(int));
  if(ptr == NULL){
    printf("Memory not allocated\n");
    exit(0);
  }
  printf("Enter the elements: ");
  for(i = 0; i < n; i++){
    scanf("%d", ptr + i);
  }
  printf("Enter the element to search: ");
  scanf("%d", &target);
  for(i=0; i<n; i++){
    if(*(ptr + i) == target){
      printf("Element found at index %d\n", i);
      break;
    }
  }
  if(i == n){
    printf("Element not found\n");
  }
  free(ptr);
  return 0;
}