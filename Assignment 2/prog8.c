/*Write a program to allocate memory using malloc ( ) and then reallocate the previously
allocated memory using realloc( ). Display the elements which have been taken after
reallocation.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
  int n, i, *ptr;
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
  printf("The elements are: ");
  for(i = 0; i < n; i++){
    printf("%d ", *(ptr + i));
  }
  printf("\nEnter the new size: ");
  scanf("%d", &n);
  ptr = (int*)realloc(ptr, n * sizeof(int));
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
