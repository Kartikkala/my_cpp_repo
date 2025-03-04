#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    public:

    // Default
        Student() {
            rollNumber = 0;
            subjects = {};
            name = "Untitled";
        }

    // Parametrized

        Student(string name, int rollNumber, const vector<string>& subjects) {
            this->name = name;
            this->rollNumber = rollNumber;
            this->subjects = subjects;
        }

        //Copuy

        Student(const Student& other) {
            name = other.name;
            rollNumber = other.rollNumber;
            subjects = other.subjects;
        }

        // Destructor

        ~Student() {
            std::cout << "\nDestructor called for student";
        }

        int getRollNumber() const {
            return rollNumber;
        }

        const vector<string>& getSubjects() const {
            return subjects;
        }

        std::string getName()
        {
            return name;
        }

    private:
        std::string name;
        int rollNumber;
        vector<string> subjects;
};

int main(void) {
    Student student1;
    Student student2("Kartik",123, {"Math", "Science", "English"});
    Student student3 = student2;

    cout << "Student 1: Name = " << student1.getName() << endl;
    cout << "Student 1: Roll Number = " << student1.getRollNumber() << endl;
    cout << "Student 2: Name = " << student2.getName() << endl;
    cout << "Student 2: Roll Number = " << student2.getRollNumber() << ", Subjects = ";
    for (const string& subject : student2.getSubjects()) {
        cout << subject << ", ";
    }

    cout << endl;

    return 0;
}