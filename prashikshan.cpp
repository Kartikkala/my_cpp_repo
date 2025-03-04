#include <iostream>

class EzBoy{
    private:
        int *a = new int(12);
        int b = 13;
    public:

        void print()
        {
            std::cout << "A : " <<*a << "\nB : " << b;
        }

        ~EzBoy()
        {
            delete a;
        }   
};

int main(void)
{
    EzBoy one;
    EzBoy *ptr = &one;
    ptr->print();

    ptr = 0;
    ptr->print();

    // std::cout << (*ptr).a;

}
