#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
        string id;
        float price;
    public:
        unsigned int items=0;
        Product()
        {

        }
        Product(string id, float price)
        {
            this->id = id;
            this->price = price;
            this->items = 0;
        }
        Product(Product &p)
        {
            this->id = p.getId();
            this->price = p.getPrice();
            this->items = p.items;
        }
        void purchaseProduct()
        {
            this->items++;
        }
        float getPrice()
        {
            return this->price;
        }
        void setPrice(float price)
        {
            this->price = price;
        }
        string getId()
        {
            return this->id;
        }
        void calculateGst()
        {
            this->price = (this->price * 0.18) + this->price;
        }
};

class ProductManager{
    private:
        Product p[100];
        int size = 0;
    public:
        ProductManager(){

        }
        void addProduct(string id, float price)
        {
            Product newProduct(id, price);
            newProduct.calculateGst();
            this->p[size] = newProduct;
            this->size++;
        }
        void buyProduct(string id)
        {
            for(int i=0;i<this->size;i++)
            {
                if(p[i].getId() == id)
                {
                    p[i].purchaseProduct();
                    break;
                }
            }
        }
        void sortAndPrint()
        {
            for(int i=0;i<this->size;i++)
            {
                for(int j=0;j<this->size;j++)
                {
                    if(p[i].items > p[j].items)
                    {
                        Product temp = this->p[i];
                        this->p[i] = this->p[j];
                        this->p[j] = temp;
                    }
                }
            }
            for(int i=0;i<this->size;i++)
            {
                cout << "Product " <<this->p[i].getId() << " has sold " <<this->p[i].items << " copies with "<<this->p[i].getPrice() << " as price.\n";
            }
        }
};

int main(void)
{
    ProductManager pm;
    pm.addProduct("FIRST", 35);
    pm.addProduct("SECOND", 40);
    pm.addProduct("THIRD", 70);

    pm.buyProduct("FIRST");
    pm.buyProduct("FIRST");
    pm.buyProduct("FIRST");

    pm.buyProduct("SECOND");
    pm.buyProduct("SECOND");

    pm.buyProduct("THIRD");
    pm.buyProduct("THIRD");
    pm.buyProduct("THIRD");
    pm.buyProduct("THIRD");

    pm.sortAndPrint();
}