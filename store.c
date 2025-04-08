#include <stdio.h>

#define MAX_PRODUCTS 5

void add_product(int *quantities, int size, int max_quantities){
    static int id = 0;
    if(id >= MAX_PRODUCTS)
    {
        printf("Max number of products added!\n");
        return;
    }
        
    quantities[id] = max_quantities;
    printf("Product id %d added with %d quantity.\n", id, quantities[id]);
    id++;
    return;
}

void remove_product(int *quantities, int size, int product_id)
{
    if(product_id >= MAX_PRODUCTS || product_id < 0)
    {
        printf("Invalid product ID\n");
        return;
    }
    if(quantities[product_id]>0)
        quantities[product_id]--;
    printf("Product with product id: %d has now %d copies left.\n", product_id, quantities[product_id]);
    return;
}

int find_max(int *quantities, int size)
{
    int max = -1;
    int id = 0;
    for(int i=0;i<size;i++)
    {
        if(quantities[i] > max)
        {
            max = quantities[i];
            id = i;
        }
    }
    return id;
}

int main(void)
{
    int quantities[5] = {0};

    add_product(quantities, 5, 8);
    add_product(quantities, 5, 2);
    add_product(quantities, 5, 4);
    add_product(quantities, 5, 6);
    add_product(quantities, 5, 9);

    remove_product(quantities, 5, 0);
    int id = find_max(quantities, 5);

    printf("Product id %d has max number of copies i.e.: %d", id, quantities[id]);

}