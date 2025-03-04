#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }

    Student() {}

    // Serialize the Student object to a binary file
    void serialize(fstream &file) const {
        size_t nameLength = name.size();
        file.write((char *)&nameLength, sizeof(nameLength)); // Write the length of the name
        file.write(name.c_str(), nameLength);               // Write the name string
        file.write((char *)&age, sizeof(age));              // Write the age
    }

    // Deserialize the Student object from a binary file
    void deserialize(fstream &file) {
        size_t nameLength;
        file.read((char *)&nameLength, sizeof(nameLength)); // Read the length of the name
        name.resize(nameLength);
        file.read(&name[0], nameLength);                   // Read the name string
        file.read((char *)&age, sizeof(age));              // Read the age
    }
};

void serializeStudents(const vector<Student> &students, const string &filename) {
    fstream file(filename, ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open the file for writing.\n";
        return;
    }

    size_t count = students.size();
    file.write((char *)&count, sizeof(count)); // Write the number of students

    for (const auto &student : students) {
        student.serialize(file); // Serialize each student
    }

    file.close();
}

vector<Student> deserializeStudents(const string &filename) {
    fstream file(filename, ios::in | ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open the file for reading.\n";
        return {};
    }

    size_t count;
    file.read((char *)&count, sizeof(count)); // Read the number of students

    vector<Student> students;
    for (size_t i = 0; i < count; ++i) {
        Student stu;
        stu.deserialize(file); // Deserialize each student
        students.push_back(stu);
    }

    file.close();
    return students;
}

int main() {
    // Create multiple students
    vector<Student> students = {
        Student("Kartik", 21),
        Student("Arjun", 22),
        Student("Meera", 20)
    };

    list<Student> l1;

    l1.push_back(Student("Some", 41));
    l1.push_back(Student("Some2", 42));
    
    list <Student>::iterator i = l1.begin();

    for(Student stu : l1)
    {
        cout << stu.name;
    }

    // Serialize the students
    string filename = "students.dat";
    serializeStudents(students, filename);

    // Deserialize the students
    vector<Student> loadedStudents = deserializeStudents(filename);

    // Print the deserialized students
    for (const auto &student : loadedStudents) {
        cout << "Name: " << student.name << ", Age: " << student.age << endl;
    }

    return 0;
}
