#include <iostream>
#include <string>
#include <vector>

class Student{
    private:
        std::string name;
        int roll_no;
        std::vector<float> marks;
        float total, avg, min, max;

        bool set_details(const std::string &name, int roll_no, const std::vector<float> &marks)
        {
            this->total = 0;
            this->min = 101;
            this->max = -1;
            if(marks.size() !=3)
            {
                return false;
            }
            for(int i=0;i<marks.size();i++)
            {
                if(marks[i] > 100 || marks[i] < 0)
                {
                    throw std::runtime_error("Marks cannot be greater than 100 or less than 0!");
                }
                this->min = std::min(this->min, marks[i]);
                this->max = std::max(this->max, marks[i]);
                this->total += marks[i];
            }
            avg = total / 3;

            this->name = name;
            this->roll_no = roll_no;
            this-> marks = marks;
            return true;
        }
    public:

        Student(const std::string &name, int roll_no, const std::vector<float> &marks)
        {
            this->set_details(name, roll_no, marks);
        }

        bool print_details()
        {
            std::cout << "Hii! "<< name << "." << "Your details are : \n"<< std::endl;
            std::cout << "Roll number : " << roll_no << std::endl;
            std::cout << "Your total marks are : "<< total << std::endl;
            std::cout << "Your average marks are: "<< this->avg << std::endl;
            std::cout << "Your min marks are: "<< this->min << std::endl;
            std::cout << "Your max marks are: "<< this->max << std::endl;
            
            return true;
        }

        std::string get_name()
        {
            return this->name;
        }

        int get_roll_number()
        {
            return this->roll_no;
        }
};

class StudentManager{
    private:
        std::vector<Student> stu_arr;

    public:
        void add_student(Student &student)
        {
            this->stu_arr.push_back(student);
        }
        Student get_student(std::string &name)
        {
            for(int i=0;i < this->stu_arr.size() ; i++)
            {
                if(stu_arr[i].get_name() == name)
                {
                    return stu_arr[i];
                }
            }
            throw std::runtime_error("Student not found");
        }
};

int main(void)
{
    std::vector <float> marks;
    std::string name;
    int roll_no = 0;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your roll number: ";
    std::cin >> roll_no;
    for(int i=0;i<3;i++)
    {
        int mark = 0;
        std::cout << "Enter marks of subject " << i << ": ";
        std::cin >> mark;
        marks.push_back(mark);
    }
    StudentManager stu_manager = StudentManager();
    Student obj = Student(name, roll_no, marks);

    stu_manager.add_student(obj);
    obj = stu_manager.get_student(name);
    obj.print_details();
}