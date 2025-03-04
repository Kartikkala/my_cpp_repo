// Create student class and make student admission registration. 
// Make Base fee of MCA course and calculate the scholarship on previous qualification.
// And display all student information and the pending dues of each student.

#include <iostream>
#include <vector>
#include <string>

class Student{
    private:
        static const int base_fee = 100000;
        std::string name = "Unnamed";
        int roll_no = 0;
        int new_base_fee = 100000;
        float scholarship = 0;

        public:
            Student(std::string name, int roll_no)
            {
                this->name = name;
                this->roll_no = roll_no;
            }
            static float scholarship_12th(float percentage){
                if(percentage > 100 || percentage < 0)
                {
                    return -1;
                }
                else if(percentage > 75 && percentage < 85)
                {
                    return ((base_fee * 25)/100);
                }
                else if(percentage > 85 && percentage < 95)
                {
                    return ((base_fee * 30)/100);
                }
                else if(percentage > 95.0)
                {
                    return ((base_fee * 40)/100);
                }
                return 0;
            }

            static float scholarship_lpunest(float percentage)
            {
                if(percentage > 100 || percentage < 0)
                {
                    return -1;
                }
                else if(percentage > 75 && percentage < 85)
                {
                    return ((base_fee * 25)/100);
                }
                else if(percentage > 85 && percentage < 95)
                {
                    return ((base_fee * 30)/100);
                }
                else if(percentage > 95)
                {
                    return ((base_fee * 40)/100);
                }
                return 0;
            }

            float apply_scholarship(float percent_12, float percent_lpunest)
            {
                if(percent_12 > 100 || percent_12 < 0 || percent_lpunest > 100 || percent_lpunest <0)
                {
                    throw std::runtime_error("Percentage can only be between 0 and 100. Invalid input!!!");
                }
                int s_12th = scholarship_12th(percent_12);
                int s_lpunest = scholarship_lpunest(percent_lpunest); 
                this->scholarship = std::max(s_12th, s_lpunest);
                this->new_base_fee = base_fee - this->scholarship;
                return this->new_base_fee;
            }

            float get_scholarship()
            {
                return this->scholarship;
            }

            void print_student_details()
            {
                std::cout << "\n\nName: " << this->name << std::endl;
                std::cout << "Roll no: " << this->roll_no << std::endl;
                std::cout << "Scholarship applied: " << this->scholarship << std::endl;
                std::cout << "Original fee: " << this->base_fee << std::endl;
                std::cout << "New fee: " << this->new_base_fee << std::endl;
            }

};

class StudentManager{
    private:
        std::vector<Student> students = {};
    public:
        StudentManager()
        {

        }
        StudentManager(std::vector<Student> students)
        {
            this->students = students;
            std::cout << "Students vector initialized successfully!!!";
        }
        void create_and_add_new_student(std::string name, int roll_no, float percent_12th, float percent_lpunest)
        {
            Student new_student = Student(name, roll_no);
            new_student.apply_scholarship(percent_12th, percent_lpunest);

            this->students.push_back(new_student);

            std::cout << "New student added sucessfully!\n";
        }

        void print_details_of_all_students()
        {
            for(int i=0;i< this->students.size();i++)
            {
                students[i].print_student_details();
            }
        }
};

int main(void)
{
    StudentManager student_manager = StudentManager();
    int number_students = 0;
    std::cout << "Enter total number of students: ";
    std::cin >> number_students;
    for(int i=0;i<number_students;i++)
    {
        system("clear");
        std::string name = "Unnamed";
        int roll_no = 0;
        float percentage_12th = 0;
        float percentage_lpunest = 0;
        std::cout << "Enter student name: ";
        std::cin >> name;
        std::cout << "Enter roll no: ";
        std::cin >> roll_no;
        std::cout << "Enter 12th class percentage: ";
        std::cin >> percentage_12th;
        std::cout << "Enter lpunest percentage: ";
        std::cin >> percentage_lpunest;

        student_manager.create_and_add_new_student(name, roll_no, percentage_12th, percentage_lpunest);
    }
    system("clear");
    student_manager.print_details_of_all_students();
}