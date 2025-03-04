#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem>

using namespace std;

class File
{
    private:
        fstream fileObject = fstream();
        string path;
    public:
        File(string path, ios::openmode openMode)
        {
            fileObject.open(path.c_str(), openMode);
            this->path = path;
        }

    void writeBinaryDataIntoFile(const char* data, uintmax_t size)
    {   
        fileObject.open(path, ios::binary | ios::out);
        fileObject.write(data, size);
    }

    void writeIntoFile(string &content)
    {
        fileObject.write(content.c_str(), content.size());
        fileObject.flush();
    }

    char* readFileContents()
    {
        uintmax_t size = this->fileSize();
        if (size == 0)
        {
            return nullptr;
        }
        char *buffer = new char[size];
        fileObject.seekg(0);
        fileObject.read(buffer, size);
        return buffer;
    }

    uintmax_t fileSize()
    {
        filesystem::path filePath(this->path);
        return filesystem::file_size(filePath);
    }

    void operator +(File &file)
    {
        char *content = file.readFileContents();
        string contentInString = string(content);
        this->writeIntoFile(contentInString);
        delete[] content;
    }

    void readBinaryDataFromFile(char *data)
    {
        if (fileObject.is_open())
        {
            fileObject.seekg(0);
            fileObject.read(data, this->fileSize());
        }
    }
        
};

int main(void)
{
    File f3("file.bin", ios::in);
    struct test2
    {
        char name[50];
        int age;
    };

    test2 t1, t2;
    strncpy(t1.name, "Kartik", sizeof(t1.name));
    t1.age = 21;
    
    f3.writeBinaryDataIntoFile(reinterpret_cast<const char*>(&t1), sizeof(t1));
    f3.readBinaryDataFromFile(reinterpret_cast<char *>(&t2));

    // Output the read data
    cout << "Name: " << t2.name << ", Age: " << t2.age << endl;
}