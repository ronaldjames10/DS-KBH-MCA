/*Write a program that reads a 2D metrics and checks if the metrics is a symmetric metrics
or not.*/
#include <stdio.h>
int main(){
  int n;
  int isSymmetric = 1;
  
  // Read the size of the matrix
  printf("Enter the size of the matrix (n x n): ");
  scanf("%d", &n);

  int matrix[n][n];

  // Read the matrix elements
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
    }
  }
  // Check if the matrix is symmetric
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != matrix[j][i]) {
        isSymmetric = 0;
          break;
        }
    }
    if(isSymmetric == 0) {
      break;
    }
  }
  if(isSymmetric==1){
    printf("The matrix is symmetric.\n");
  } else {
    printf("The matrix is not symmetric.\n");
  }
  return 0;
}