/*Write a program to display n number of elements. Memory should be allocated
dynamically using calloc( ).*/
#include<stdio.h>
#include<stdlib.h>
int main(){
  int n, i, *ptr;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  ptr = (int*)calloc(n, sizeof(int));
  if(ptr == NULL){
    printf("Memory not allocated\n");
    exit(0);
  }
  printf("Enter the elements: ");
  for(i = 0; i < n; i++){
    scanf("%d", ptr + i);
  }
  printf("The elements are: ");
  for(i = 0; i < n; i++){
    printf("%d ", *(ptr + i));
  }
  free(ptr);
  return 0;
}