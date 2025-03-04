#include <iostream>
#include <fstream>
#include <cctype> 

int countVowels(const char name[], int length) {
    int vowelCount = 0;
    for (int i = 0; i < length; i++) {
        char ch = std::tolower(name[i]); 
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

char *integerToCharArray(int num)
{
    char *numArr = new char(10);
    int i=0;
    for(i=0;num>0;i++)
    {
        numArr[i] = (char)((num % 10) + '0');
        num = num/10;
    }
    for(int j=0,k=i-1;j<k;j++,k--)
    {
        char character = numArr[j];
        numArr[j] = numArr[k];
        numArr[k] = character; 
    }
    return numArr;
}

int main() {
    const char filename[] = "person.txt";
    char name[] = "Kartik Kala";
    int age = 20;

    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    for (int i = 0; name[i] != '\0'; i++) {
        outfile.put(name[i]);
    }

    outfile.put('\n'); 
    char *ageStr;
    ageStr = integerToCharArray(age);


    for (int i = 0; ageStr[i] != '\0'; i++) {
        outfile.put(ageStr[i]);
    }
    outfile.put('\n'); 
    outfile.close();

    std::cout << "Data written to file successfully using `put()`!" << std::endl;

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    char readName[100];
    int index = 0;
    char ch;

    while (infile.get(ch) && ch != '\n') { 
        readName[index++] = ch;
    }

    readName[index] = '\0';

    char ageStrRead[4];
    index = 0;

    while (infile.get(ch) && ch != '\n') {
        ageStrRead[index++] = ch;
    }

    ageStrRead[index] = '\0'; 
    int readAge = atoi(ageStrRead);
    infile.close();

    std::cout << "Read from file using `get()`:" << std::endl;
    std::cout << "Name: " << readName << std::endl;
    std::cout << "Age: " << readAge << std::endl;

    int vowelCount = countVowels(readName, index);
    std::cout << "Number of vowels in the name: " << vowelCount << std::endl;

    return 0;
}
