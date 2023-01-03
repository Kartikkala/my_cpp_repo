#include <iostream>
#include <chrono>
#define MEM_POOL_SIZE_BYTES 524288000

using namespace std::chrono;


struct mem_block
{
    bool in_use;
    char data;
};

mem_block * mempool = (mem_block*)malloc(sizeof(mem_block)*MEM_POOL_SIZE_BYTES);        //Mempool


void *allocate(size_t size)
{
    for(int i=0;i<MEM_POOL_SIZE_BYTES;i++)
    {
        if(mempool[i].in_use)
            continue;
        else
        {
            for(int j=0;j<size;j++)
            {
                if(mempool[j].in_use)
                {
                    i=j;
                    break;
                }
                else
                    continue;
            }
            if(mempool[i].in_use)
                continue;
            else
            {
                return &mempool[i];
            }
        }
    }


}

int main()
{
    auto start = high_resolution_clock::now();
    for(int i=0;i<524288000;i++)
        mempool[i] = NULL;
    auto stop = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>(stop - start);
    int a;
    printf("Memory starts from: %d\n", mempool);
    scanf("%d", &a);

    void *mem_ptr = mempool;
    int *mem_ptr2 = (int *)mem_ptr;
    printf(" Ptr to: %d\n", mem_ptr2);

    start = high_resolution_clock::now();
    for(int i=0;i<131072000;i++)
    {
        mem_ptr2[i] = i+1;
        if(i<10)
            printf("Using block: %d", &mem_ptr2[i]);
    }
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop - start);

    printf("Used until: %d\n", &mem_ptr2[131071999]);

    scanf("%d", &a);

    std::cout<<"Done!!!!!";

    // for(int i=0;i<131072000;i++)
    //     std::cout<<mem_ptr2[i]<<'\n';

    scanf("%d", &a);
    free(mempool);

    printf("Duration 1: %d, Duration 2: %d", duration1, duration2);
}