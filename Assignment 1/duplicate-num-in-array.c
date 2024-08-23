#include<stdio.h>
int main(){
  // duplicate number in an array
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("The duplicate numbers in the array are: ");
  for(int i = 0; i< size; i++){
    for(int j = 0; j < size; j++){
      if(i != j && arr[i] == arr[j]){
        printf("%d ", arr[i]);
        break;
      }
    }
  }
return 0;
}