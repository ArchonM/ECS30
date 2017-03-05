#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{
   int i;
   for( i = 0 ; i < 6 ; i++ )
   {
       char c = 'a'+i;
       printf("%c ",c);
   }

   return(0);
}
