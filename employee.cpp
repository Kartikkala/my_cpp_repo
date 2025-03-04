#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <any>


class Employee{
    public:
        static const int max_bpay = 100000;
        static const int min_bpay = 10000;
        Employee()
        {

        }
        Employee(std::string name, int basic_pay)
        {
            if(name.size() >= 1 && name.size() <= 40 && basic_pay >= Employee::min_bpay && basic_pay <= Employee::max_bpay)
            {
                this->name = name;
                this->basic_pay = basic_pay;
            }
            else
            {
                throw std::runtime_error("\nInvalid input range for name or basic pay.");
            }
        }
    private:
        std::string name;
        int basic_pay;
        int bonus = 0;
        int regular_working_hours = 8;
        int additional_working_hours = 0;
    public:
        int reset_basic_pay(int amount)
        {
            if(amount >= Employee::min_bpay && amount <= Employee::max_bpay)
            {
                this->basic_pay = amount;
                return amount;
            }
            return -1;
        }

        int getBasicPay()
        {
            return this->basic_pay;
        }
        int getAdditionalWorkingHours()
        {
            return additional_working_hours;
        }
        int getWorkingHours()
        {
            return this->regular_working_hours + this->additional_working_hours;
        }
        int grant_additional_bonus(int additional_hours)
        {
            this->bonus = (additional_hours * 500);
            return this->bonus;
        }

        std::string getEmployeeName()
        {
            return this->name;
        }

        // friend void print_name(Employee &emp);
};

// void print_name(Employee &emp)
// {
//     std::cout << emp.name;
// }

class EmployeeManager{
    private:
        std::unordered_map<std::string, Employee> employees;
    public:
        bool create_new_employee(std::string name, int basic_pay)
        {
            try{
                Employee emp = Employee(name, basic_pay);
                this->employees[name] = emp;
                return true;
            }
            catch(std::exception err){
                std::cout << "Invalid basic pay or name. Failed to create a new employee!" << std::endl;
            }
            return false;
        }
        void print_employee_data(std::string name)
        {
            if(this->employees.contains(name))
            {
                Employee curr_employee = this->employees[name];
                std::cout << "Employee name: " << curr_employee.getEmployeeName() << std::endl;
                std::cout << "Your basic pay is: " << curr_employee.getBasicPay() << std::endl;
                std::cout << "Your regular working hours are: " << curr_employee.getWorkingHours() << std::endl;
                std::cout << "Your additional working hours is: "<< curr_employee.getAdditionalWorkingHours() << std::endl;
                std::cout << "Your bonus for additonal working hours is: "<< curr_employee.getAdditionalWorkingHours() * 500 << std::endl;
            }
        }

        bool set_additional_working_hours(std::string name, int additional_working_hours)
        {
            if(this->employees.contains(name))
            {
                this->employees[name].grant_additional_bonus(additional_working_hours);
                return true;
            }
            return false;
        }
};

void print_help()
{
    std::string helpMenu = 
        "Help Menu:\n"
        "q - Quit the program\n"
        "m - Print help menu\n"
        "a - Add a new employee\n"
        "c - Change the basic pay of a current employee\n"
        "b - Grant bonus to an employee\n";
    std::cout << helpMenu;
}

void create_new_employee(EmployeeManager &emp_man)
{
    std::string name;
    int basic_pay=0;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter basic pay: ";
    std::cin >> basic_pay;
    if(emp_man.create_new_employee(name, basic_pay))
    {
        std::cout << "\nEmployee created succesfully" << std::endl;
    }
}

template <typename FuncType, typename... Args>
void callFunction(std::any& func, Args&&... args) {
    try {
        if (func.has_value()) {
            std::any_cast<FuncType>(func)(std::forward<Args>(args)...);
        } else {
            std::cerr << "Invalid function!\n";
        }
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Function call error: " << e.what() << '\n';
    }
}


int main(void)
{
    char input;
    std::unordered_map<char, std::any> input_map;
    EmployeeManager emp_man = EmployeeManager();
    input_map['m'] = std::function<void()>(print_help);
    input_map['a'] = std::function<void(EmployeeManager&)>(create_new_employee);
    while(input != 'q')
    {
        std::cout << "Enter m for help menu or q to exit: ";
        std::cin >> input;
        callFunction<std::function<void(EmployeeManager&)>>(input_map[input], emp_man);
    }
}