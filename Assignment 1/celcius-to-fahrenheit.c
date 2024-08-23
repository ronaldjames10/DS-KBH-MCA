#include<stdio.h>
int main(){
  float celcius, fahrenheit;
  printf("Enter the temperature in celcius: ");
  scanf("%f", &celcius);
  fahrenheit = (celcius * 9/5) + 32;
  printf("The temperature in fahrenheit is: %f\n", fahrenheit);

  return 0;
}