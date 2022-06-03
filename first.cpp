#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


//--------------------------------------*****--------------------------------
//--------------------------------------Class--------------------------------
//--------------------------------------*****--------------------------------
class Arr_operations
{
    private:
        int *arr=NULL;
        int *reversed_arr;
        bool size_set;
        int arr_size;
        void setsize();
    public:
        void setArr(int *ptr_to_base_user_array);
        void getArr();
        void getsize(int legnth);
        bool isPalindrome();
        int* reverse();
};


//----------------------------------------------------------***********---------------------------------------------------
//----------------------------------------------------------*Functions*---------------------------------------------------
//----------------------------------------------------------***********---------------------------------------------------


void Arr_operations :: setArr(int *ptr_to_base_user_arr)
{
    
    int i=0;
    while(ptr_to_base_user_arr[i]!='\0')
    {
        i++;
    }

    getsize(i);
    arr = (int*)malloc(sizeof(int)*arr_size);


    for(i=0;i<arr_size;i++)
    {
        arr[i] = ptr_to_base_user_arr[i];
    }
    
    
}

void Arr_operations :: getArr()
{
    start:
    if(size_set)
    {
        arr = (int*)malloc(sizeof(int)*arr_size);
        for(int i=0;i<arr_size;i++)
        {
            printf("Enter element (%d): ",i+1);
            scanf("%d",&arr[i]);
        }
        return;
    }
    else
    {
        setsize();
        goto start;
    }
}   

void Arr_operations :: getsize(int legnth)
{
    size_set =1;
    arr_size = legnth;
    return;
}

void Arr_operations :: setsize()
{
    std::cout << "\nEnter size of this array: ";
    std::cin >> arr_size;
    size_set = 1;
    return;
}



bool Arr_operations :: isPalindrome()
{
    start:
    if(arr!=NULL)
    {
        reverse();
        for(int i=0;i<arr_size;i++)
        {
            if(arr[i]!=reversed_arr[i])
            {
                return 0;
            }
            else
            {
                break;
            }
        }
        return 1;
    }
    else
    {
        getArr();
        goto start;
    }

}
int* Arr_operations :: reverse()
{
    start:
    if(arr!=NULL)
    {
        reversed_arr = (int *)malloc(sizeof(int)*arr_size);
        for(int i=0,j=arr_size-1;i<arr_size;i++,j--)
        {
            reversed_arr[i] = arr[j];
        }
        return reversed_arr;
    }
    else
    {
        getArr();
        goto start;
    }

}



//------------------------------------------------------***************---------------------------------------------------------
//------------------------------------------------------**Driver Code**---------------------------------------------------------
//------------------------------------------------------**Driver Code**---------------------------------------------------------
//------------------------------------------------------**Driver Code**---------------------------------------------------------
//------------------------------------------------------***************---------------------------------------------------------



int main(void)
{
    int size_of_array;
    Arr_operations array;
    int arrays[4] = {3,4,4,3};
    array.setArr(arrays);
    printf("%i",array.isPalindrome());

}

