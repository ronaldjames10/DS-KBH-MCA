/*Write a program that reads two 2D matrices from the console, verifies if matrices
multiplication is possible or not. Then multiplies the matrices and prints the 3rd matrices.*/
#include<stdio.h>
#define MAX 10

void displayMatrices(int matrix[MAX][MAX], int row, int col){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
void inputMatrices(int matrix[MAX][MAX], int row, int col){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
}
int main(){
  int matrix1[MAX][MAX], matrix2[MAX][MAX], sum[MAX][MAX], row1, col1, row2, col2;
  printf("Enter the number of rows and columns of the first matrix: ");
  scanf("%d %d", &row1, &col1);
  printf("Enter the number of rows and columns of the second matrix: ");
  scanf("%d %d", &row2, &col2);
  if(col1 != row2){
    printf("Matrix multiplication is not possible\n");
    return 0;
  }
  printf("Enter the elements of the first matrix: \n");
  inputMatrices(matrix1, row1, col1);
  printf("Enter the elements of the second matrix: \n");
  inputMatrices(matrix2, row2, col2);
  printf("The first matrix is: \n");
  displayMatrices(matrix1, row1, col1);
  printf("The second matrix is: \n");
  displayMatrices(matrix2, row2, col2);
  // Multiplying the matrices
  for(int i = 0; i < row1; i++){
    for(int j = 0; j < col2; j++){
      sum[i][j] = 0;
      for(int k = 0; k < col1; k++){
        sum[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  printf("The resultant matrix is: \n");
  displayMatrices(sum, row1, col2);
  return 0;
}