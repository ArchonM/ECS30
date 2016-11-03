#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void product_matrix(int m, int n);
void dynamic_arr(int*** arr, int m, int n);
void input_arr_a(int*** arr, int m, int n);
void input_arr_b(int*** arr, int m, int n);
void free_arr_b(int*** arr, int x);

int main()
{
    int m, n;

    printf("Please enter the number of rows: \n");
    scanf("%d",&m);
    printf("Please enter the number of columns: \n");
    scanf("%d",&n);
    product_matrix(m, n);

    return 0;
}

void product_matrix(int m, int n)
{
    int x, y;
    int** arr_a;
    int** arr_b;
    int** arr_res;

    input_arr_a(&arr_a, m, n);
    input_arr_b(&arr_b, n, m);
    dynamic_arr(&arr_res, m, m);

    printf("A + B =\n");
    for(x = 0; x < m; x++)
    {
        for(y = 0; y < m; y++)
        {
            printf("%d ", arr_a[x][y]+arr_b[x][y]);
        }
        printf("\n");
    }

    free_arr(&arr_a, m);
    free_arr(&arr_b, n);
    free_arr(&arr_res, m);

}

void dynamic_arr(int*** arr, int m, int n)                          //申请动态数组
{
    int i;
    *arr = (int **)malloc(sizeof(int *) * m);

    for(i = 0; i < m; i++)
    {
        (*arr)[i] = (int *)malloc(sizeof(int) * n);
        memset((*arr)[i], 0, sizeof(int) * n);
    }
}

void input_arr_a(int*** arr, int m, int n)                            //输入数组
{
    int i, j;

    dynamic_arr(arr, m, n);

    printf("Enter Matrix A \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &(*arr)[i][j]);
    }
}
void input_arr_b(int*** arr, int m, int n)                            //输入数组
{
    int i, j;

    dynamic_arr(arr, m, n);

    printf("Enter Matrix B \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &(*arr)[i][j]);
    }
}

/*void free_arr(int*** arr, int x)                                      //释放占用的内存
{
    int i;

    for(i = 0; i < x; i++)
    {
        free((*arr)[i]);
        (*arr)[i] = 0;
    }

    free(*arr);
    *arr = 0;
}*/
