#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_matrix(int m, int n){
    int arr_a[m][n];
    int arr_b[m][n];
    int i,j;
    printf("Enter Matrix A\n");
    for (i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr_a[i][j]);
        }
    }
    printf("Enter Matrix B\n");
    for (i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr_b[i][j]);
        }
    }
    printf("A + B =\n");
    for (i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr_a[i][j]+arr_b[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int m, n;

    printf("Please enter the number of rows: \n");
    scanf("%d",&m);
    printf("Please enter the number of columns: \n");
    scanf("%d",&n);
    add_matrix(m, n);

    return 0;
}
