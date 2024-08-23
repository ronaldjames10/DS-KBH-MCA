/* Write a C program to read a 2D array (with most of the elements as 0s) and then
represent the same array as Sparse Metrics.*/
#include<stdio.h>
#define MAX 10
int main(){
  int row, col;
  int matrix[MAX][MAX];
  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &row, &col);
  printf("Enter the elements of the array: \n");
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  // display the original matrix
  printf("The original matrix is: \n");
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  // check whether the matrix is sparse or not
  int zeroElement = 0;
  int nonZeroElement = 0;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(matrix[i][j] == 0){
        zeroElement++;
      }
      else{
        nonZeroElement++;
      }
    }
  }
  if(nonZeroElement > zeroElement){
    printf("The matrix is not sparse\n");
  }
  else{
    printf("The matrix is sparse\n");
  // represent the matrix as sparse matrix
    int sparse[nonZeroElement][3];
    int k = 0;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(matrix[i][j] != 0){
          sparse[k][0] = i;
          sparse[k][1] = j;
          sparse[k][2] = matrix[i][j];
          k++;
        }
      }
    }
    // display the sparse matrix
  printf("The sparse matrix is: \n");
  for(int i=0; i<nonZeroElement; i++){
    for(int j=0; j<3; j++){
      printf("%d ", sparse[i][j]);
    }
    printf("\n");
  }
  }
  return 0;
}