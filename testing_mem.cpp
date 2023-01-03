#include <iostream>
#define MEM_POOL_SIZE_BYTES 524288000

struct chunk
{
    /* data */
    chunk *next;
};

template <size_t chunksize, size_t number_of_chunks>
class mempool
{
    private:
        size_t size_of_block;
    public:
        static void *allocate(size_t size);
        static void deallocate(void *ptr);
        static chunk *allocate_pool();
};

template <size_t chunksize, size_t number_of_chunks> chunk *mempool<chunksize, number_of_chunks>::allocate_pool()
{
    size_t size_of_pool = chunksize*number_of_chunks;
    std::cout<<"Pool size: "<<size_of_pool;
    chunk *pool_head = (chunk *)malloc(chunksize);
    size_t i =0;
    for(i=0;i<number_of_chunks;i++)
    {
        pool_head[i]->next = malloc(chunksize);
        pool_head[i] = pool_head[i]->next;
    }
    std::cout<<"\n"<<i<<"\n";
    // pool[size_of_pool-1].next = nullptr;
    return pool_head;
}

template <size_t chunksize, size_t number_of_chunks> void *mempool<chunksize, number_of_chunks>::allocate(size_t size)
{

}

int main(void)
{
    int a;
    char *first = (char *)mempool<1, 524288000>::allocate_pool();
    std::cin>>a;

}



