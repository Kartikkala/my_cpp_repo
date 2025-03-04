#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 3 and 7: " << getMax(3, 7) << endl;       
    cout << "Max of 5.7 and 2.3: " << getMax(5.7, 2.3) << endl; 
    cout << "Max of 'a' and 'z': " << getMax('a', 'z') << endl;
    return 0;
}
