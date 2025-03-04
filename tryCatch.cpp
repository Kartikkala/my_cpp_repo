#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string mobile;

public:
    Employee(const string& number)
    {
        if (number.length() > 10) {
            throw "Error: Mobile number cannot be more than 10 digits.";
        }
        mobile = number;
    }

    void display() const {
        cout << "Mobile Number: " << mobile << std::endl;
    }
};

int main() {
    try {
        string number;
        cout << "Enter your mobile number: ";
        cin >> number;

        Employee m(number);
        m.display();

    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
