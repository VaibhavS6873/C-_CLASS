#include<iostream>

const double baseSalaryOfEmployee = 1000.0;

class Employee
{
    private:
        int empId;
        double empSal;

    public:
        Employee(int _id):empId(_id),empSal(baseSalaryOfEmployee)
        {
        }

        //Inheritor
        int getId()const
        {
            return empId;
        }

        double getSalary()const
        {
            return empSal;
        }
};

class Manager : public Employee
{
    private:
        int teamSize;

    public:
        Manager(int _id, int _teamSize):Employee(_id),teamSize(_teamSize)
        {}

        //Derived specific function
        int getTeamSize()const
        {
            return teamSize;
        }

        double getSalary()const
        {
            double baseSal = this->Employee::getSalary();
            double manSal = 1.25 * baseSal;
            return manSal;
        }
};

void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    Employee* pEmployee = new Employee(1);
    std::cout<<"pEmployee->getId():"<<pEmployee->getId()<<std::endl;
    std::cout<<"pEmployee->getSalary():"<<pEmployee->getSalary()<<std::endl;

    Manager* pManager = new Manager(2,10);
    //Inheritor
    std::cout<<"pManager->getId():"<<pManager->getId()<<std::endl;

    //Overridden function for extension(extendor)
    std::cout<<"pManager->getSalary():"<<pManager->getSalary()<<std::endl;

    //Derived specific behaviour
    std::cout<<"pManager->getTeamSize():"<<pManager->getTeamSize()<<std::endl;

    delete pEmployee;
    pEmployee = nullptr;

    delete pManager;
    pManager = nullptr;
}
