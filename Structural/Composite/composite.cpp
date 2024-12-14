#include <iostream>
#include <vector>

class Employee {
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}

    virtual void display() const = 0;

protected:
    std::string name;
    double salary;
};

class Developer : public Employee {
public:
    Developer(const std::string& name, double salary) : Employee(name, salary) {}

    void display() const override {
        std::cout << "Developer: " << name << ", Salary: " << salary << std::endl;
    }
};

class Designer : public Employee {
public:
    Designer(const std::string& name, double salary) : Employee(name, salary) {}

    void display() const override {
        std::cout << "Designer: " << name << ", Salary: " << salary << std::endl;
    }
};

class Company : public Employee {
public:
    Company(const std::string& name) : Employee(name, 0) {}

    void addEmployees(Employee* emp) {
        employees.push_back(emp);
    }

    void display() const override {
        std::cout << "Company: " << name << std::endl;
        for (const auto& employee : employees) {
            employee->display();
        }
    }

private:
    std::vector<Employee*> employees;
};

int main() {

    Developer dev1("Telman", 450000);
    Developer dev2("Hovhannes", 820000);
    Designer dev3("Katrin", 568000);
    Designer dev4("Mher", 470000);

    Company back("inOne");
    back.addEmployees(&dev1);
    back.addEmployees(&dev2);

    back.display();

    std::cout << "--------------" << std::endl;

    Company company("Technologist");
    company.addEmployees(&dev3);
    company.addEmployees(&dev4);
    company.addEmployees(&back);

    company.display();

    return 0;
}
