#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a =100;
    int *ptr = &a;
    int ***arr = (int ***)malloc(sizeof(int **)*2);
    arr[0] = (int **)malloc(sizeof(int **));
    arr[1] = (int **)malloc(sizeof(int **)*2);

    arr[0][0] = ptr;
    // arr[0][1] = 2;
    // arr[1][1] = 4;
    // arr[1][0] = 3;

    printf("%d",*arr[0][0]);
}