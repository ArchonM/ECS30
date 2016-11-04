#include<stdio.h>
#include<math.h>

int main(){
    int N = 100000
    int prime[N];
    int i, j, num = 0;
    for(i=2; i<N; i++)
    {  for(j=2; j<=sqrt(i); j++)
         if( j%i==0 ) break;
       if( j>sqrt(i) ) prime[num++] = i;
    }
 for(i=2; i<100; i++) {
    if( prime[i] )printf("%d ",i);

 return 0;
}
