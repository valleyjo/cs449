#include <stdio.h>

int main(){
  double weight;
  
  printf("Enter the weight you'd like to convert: ");
  scanf("%lf", &weight);
  
  printf("\nHere is your weight on other planets:");
  printf("\n\n%-10s %.0lf lbs\n", "Mercury", weight * .38);
  printf("%-10s %.0lf lbs\n", "Venus",  weight * .91);
  printf("%-10s %.0lf lbs\n", "Mars", weight * .38);
  printf("%-10s %.0lf lbs\n", "Jupiter", weight * 2.54);
  printf("%-10s %.0lf lbs\n", "Saturn", weight * 1.08);
  printf("%-10s %.0lf lbs\n", "Uranus", weight * .91);
  printf("%-10s %.0lf lbs\n", "Neptune", weight * 1.19 );
  return 0;
}
