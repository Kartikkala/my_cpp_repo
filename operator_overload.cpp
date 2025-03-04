#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    private: 
        int real, imag;
        
    public: 
        Complex(int r = 0, int i = 0) : real(r), imag(i) {}
      
        friend Complex operator + (Complex const &c1, Complex const &c2);
        
        friend Complex operator - (Complex const &obj);

        friend Complex operator < (Complex const &first, Complex const &second); 
        
        operator int() const { return real; }
      
        void print() { cout << real << " + i" << imag << "\n"; }   
}; 

Complex operator < (const Complex& c1, const Complex& c2) {
    int mag1 = sqrt(c1.real * c1.real + c1.imag * c1.imag);
    int mag2 = sqrt(c2.real * c2.real + c2.imag * c2.imag);
    
    return (mag1 < mag2);
}

Complex operator +(Complex const &c1, Complex const &c2) {
   return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator - (Complex const &obj) {
    return Complex(-obj.real, -obj.imag);
} 
    
int main() {
   Complex c1(4,5), c2(-3,-7), c3;
   cout<<"First complex number is ";c1.print();
   cout<<"Second complex number is ";c2.print();
      
   c3 = c1 + c2; 
   cout << "Resultant Complex Number after adding two complex numbers: ";
   c3.print();
    
   -c2;
   cout << "Negated Second complex number: ";
   c2.print();

   int x = c1;
   cout << "Integer value extracted from Complex Object: " << x << endl;
    

    return 0;
}
