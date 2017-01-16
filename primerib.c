#include<stdio.h>
#include<math.h>

int main(){
  double ribWeigh = 0;
  int hr,mn;
  double temp = 0;
  hr = mn =0;
  double sec;
  printf("How many pounds is your prime rib?");
  scanf("%lf",&ribWeigh);
  hr = 2;
  temp = ribWeigh*5;
  mn = (int)temp;
  sec = 60 * (temp - mn);
  if (mn >= 60){
    mn = mn - 60;
    hr += 1;

  }
  printf("\nYour rib will be in the oven for %d hours, %d minutes, and %.0lf seconds.\n", hr,mn,sec);
  return 0;
}
