#include <iostream>
#include <string>
using namespace std;

class IWorker
{
public:
    virtual void Work() = 0;
    virtual double GetSalary() const = 0;
};

class Employee : public IWorker
{
protected:
    string fullName;
    int experience;
public:
    Employee(string name, int exp) : fullName(name), experience(exp) {}
    virtual void PrintInfo() const
    {
        cout << "Fio: " << fullName << " | : " << experience << " Year`s:" << endl;
    }
};

class Programmer : public Employee
{
private:
    double baseSalary;
    int linesOfCode;

public:
    Programmer(string name, int exp, double base, int lines): Employee(name, exp), baseSalary(base), linesOfCode(lines) {}
    void Work()
    {
        cout << fullName << " working about code: " << linesOfCode << ")." << endl;
    }

    double GetSalary() const
    {
        return baseSalary + (experience * 1500);
    }

    void PrintInfo() const
    {
        cout << "[Computer Programer] ";
        Employee::PrintInfo();
        cout << "Salary: " << GetSalary() << " USD" << endl;
    }
};

class Designer : public Employee
{
private:
    double baseSalary;
    int projectsCount;
public:
    Designer(string name, int exp, double base, int projects) : Employee(name, exp), baseSalary(base), projectsCount(projects) {}
    void Work()
    {
        cout << fullName << " Making a consept arts and grafiсal interface" << endl;
    }

    double GetSalary() const
    {
        return baseSalary + (projectsCount * 200);
    }

    void PrintInfo() const
    {
        cout << "[Disigner] ";
        Employee::PrintInfo();
        cout << "Salary: " << GetSalary() << " USD" << endl;
    }
};

class Manager : public Employee
{
private:
    double baseSalary;
    int successfulDeals;
public:
    Manager(string name, int exp, double base, int deals) : Employee(name, exp), baseSalary(base), successfulDeals(deals) {}
    void Work()
    {
        cout << fullName << " working with clients and make collaboration " << endl;
    }
    double GetSalary() const
    {
        return baseSalary + (successfulDeals * 300);
    }
    void PrintInfo() const
    {
        cout << "[Manager] ";
        Employee::PrintInfo();
        cout << "Salary: " << GetSalary() << " USD" << endl;
    }
};

int main()
{
    const int size = 3;
    Employee* company[size];
    company[0] = new Programmer("Kristina Cherkezyn", 3, 2000.0, 450);
    company[1] = new Designer("Inna Nochevkina", 2, 1800.0, 6);
    company[2] = new Manager("Alexander Ivanov", 4, 2200.0, 10);
    double totalSalary = 0.0;
    cout << "=== Employee report ===" << endl << endl;
    for (int i = 0; i < size; i++)
    {
        company[i]->PrintInfo();
        company[i]->Work();
        totalSalary += company[i]->GetSalary();
        cout << "--------------------------------------------------" << endl;
    }
    cout << "Общая сумма зарплат всех сотрудников: " << totalSalary << " USD" << endl;
    for (int i = 0; i < size; i++)
    {
        delete company[i];
    }
    return 0;
}