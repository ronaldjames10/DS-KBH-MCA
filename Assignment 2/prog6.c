/*Write a program to display n number of elements. Memory should be allocated
dynamically using malloc ( ).*/
#include<stdio.h>
#include<stdlib.h>
int main(){
  int n, i, *ptr;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  ptr = (int*)malloc(sizeof(int) * n);
  if(ptr == NULL){
    printf("Memory not allocated\n");
  }
  else{
    printf("Memory allocated successfully\n");
    printf("Enter the elements: ");
    for(i=0; i<n; i++){
      scanf("%d", ptr+i);
    }
    printf("Elements are: ");
    for(i=0; i<n; i++){
      printf("%d ", *(ptr+i));
    }
  }
  return 0;
}