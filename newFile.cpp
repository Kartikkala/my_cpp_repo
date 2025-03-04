#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Student {
    char name[100];
    int age;

public:
    void setData(char* n, int a) {
        strncpy(name, n, sizeof(name));
        name[sizeof(name) - 1] = '\0';
        age = a;
    }

    void write(char* filename) {
        std::ofstream outfile(filename);
        for (int i = 0; name[i] != '\0'; i++) {
            outfile.put(name[i]);
        }
        outfile.put('\n');
        char ageStr[4];
        sprintf(ageStr, "%d", age);
        for (int i = 0; ageStr[i] != '\0'; i++) {
            outfile.put(ageStr[i]);
        }
        outfile.put('\n');
        outfile.close();
    }

    void read(char* filename) {
        std::ifstream infile(filename);
        char ch;
        int i = 0;
        while (infile.get(ch) && ch != '\n') {
            name[i++] = ch;
        }
        name[i] = '\0';
        i = 0;
        char ageStr[4];
        while (infile.get(ch) && ch != '\n') {
            ageStr[i++] = ch;
        }
        ageStr[i] = '\0';
        age = atoi(ageStr);
        infile.close();
    }

    void display() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Number of vowels in name: " << countVowels() << std::endl;
    }

private:
    int countVowels() {
        int count = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            char ch = std::tolower(name[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Student s;
    s.setData("Kartik", 20);
    s.write("student.txt");
    s.read("student.txt");
    s.display();
    return 0;
}
