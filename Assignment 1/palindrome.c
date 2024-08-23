#include<stdio.h>
#include<string.h>
int isPalindrome(char str[]){
  int i = 0;
  int j = strlen(str) - 1;
  while(i<j){
    if(str[i] != str[j]){
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}
int main(){
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  isPalindrome(str) ? printf("The string is a palindrome.\n") : printf("The string is not a palindrome.\n");

return 0;
}