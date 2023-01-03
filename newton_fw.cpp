#include <iostream>

void print_arr(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<"\n";
    }
}

void array_copy(int *first, int *second, int size_first, int size_sec)
{
    int size;
    if(size_first>size_sec)
        size = size_sec;
    else
        size = size_first;
    for(int i=0;i<size;i++)
    {
        second[i] = first[i];
    }
}

int newton_fw(int *x, int *y, int size)
{
    int *d_y = (int *)malloc(sizeof(int)*(size-1));
    int sub_arr_size = size-1;

    for(int k=0;k<3;k++)
    {
        for(int i=0,j=0;i<(size-1);i++,j++)
        {
            d_y[j] = y[i+1]-y[i];
        }
        sub_arr_size--;


        print_arr(d_y, size-1);
    }
    return 0;
}


int main(void)
{
    int x[4] = {5,10,15,20}; 
    int y[4] = {222,444,555,666}; 
    newton_fw(x,y,4);
}
