#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
// class Car
// {
//     public:
//         virtual ~Car()
//         {
//             std::cout << "Car destructor called! \n";
//         }
// };

// class SportsCar : public Car
// {
//     public:
//         SportsCar()
//         {
//             std::cout << "Sports Car constructor called! \n";
//         }
//         ~SportsCar()
//         {
//             std::cout << "Sports car destructor called! \n";
//         }
// };

template <typename T>
class Vector{
    public:
        T i = 0;
        T j = 0;
        T k = 0;
};

template <typename T>
class Complex{
    public:
        T real = 0;
        T imaginary = 0;

        Complex (){}
        Complex(T number){
            this->real = number;
        }

        Complex(Complex &complexNumber)
        {
            this->real = complexNumber.real;
            this->imaginary = complexNumber.imaginary;
        }

        Complex(Vector<T> &vector)
        {
            this->real = vector.i * vector.j;
            this->imaginary = vector.k;
        }

        operator Vector<T>()
        {
            Vector<int> v;
            v.i = this->real;
            v.j = this->imaginary;
            v.k = this->real;
            return v;
        }

        operator T()
        {
            return this->real;
        }
};

class abs{
    public:
        virtual void dosomething() = 0;
};

template <typename T> T sum(T x, T y)
{
    return x+y;
}

template <typename A, typename B> double sum(A x, B y)
{
    return x + y;
}



int main(void)
{
    std::vector<int> v = {4,2,5,1,9};
    std::sort(v.begin(), v.end());
    std::list<int> l = {4,5,7,3,2};
    auto num = l.begin();

    v.insert(v.begin() + 1, {2,3,4,5});

    int * arr = new int[2];

    arr[0] = 3;
    arr[1] = 5;

    std::cout << " Array:"<< arr[0] << "," << arr[1] << "," << arr[3]<<std::endl;


    for(int i=0;i<l.size();i++)
    {
        std::cout << *num<<std::endl;
        std::advance(num, 1);
    }

    std::for_each(v.begin(), v.end(), [](int a){ std::cout << a <<std::endl; });
    Complex<int> c1,c2 = 34;
    Vector<int> v1;

    Vector<int> v2 = c1;
   

    std::cout <<"("<<c1.real << ","<<c1.imaginary<<")";
    std::cout <<"("<<c2.real << ","<<c2.imaginary<<")"<<std::endl;
    c1 = v1;
    std::cout <<"("<<c1.real << ","<<c1.imaginary<<")";
    std::cout <<"("<<c2.real << ","<<c2.imaginary<<")"<<std::endl;
    std::cout << "(" << sum(4.1, 6) << ")"<<std::endl;
}