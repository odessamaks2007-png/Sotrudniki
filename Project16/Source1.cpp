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
    virtual void ShowCard() const = 0;
};

class Programmer : public Employee
{
private:
    double baseSalary;
    int linesOfCode;
public:
    Programmer(string name, int exp, double base, int lines) : Employee(name, exp), baseSalary(base), linesOfCode(lines) {}
    void Work()
    {
        cout << fullName << " writes code, lines: " << linesOfCode << endl;
    }
    double GetSalary() const
    {
        return baseSalary + (experience * 1500);
    }
    void ShowCard() const
    {
        cout << "+----------------------------------------------+" << endl;
        cout << "| Position: [Computer Programmer]              |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Name: " << fullName << "                       |" << endl;
        cout << "| Experience: " << experience << " years                         |" << endl;
        cout << "| Salary: " << GetSalary() << " USD                          |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Action: Writes code and fixes bugs           |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
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
        cout << fullName << " makes concept arts and interfaces" << endl;
    }
    double GetSalary() const
    {
        return baseSalary + (projectsCount * 200);
    }
    void ShowCard() const
    {
        cout << "+----------------------------------------------+" << endl;
        cout << "| Position: [UI/UX Designer]                   |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Name: " << fullName << "                          |" << endl;
        cout << "| Experience: " << experience << " years                         |" << endl;
        cout << "| Salary: " << GetSalary() << " USD                          |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Action: Creates concept arts and interfaces  |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
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
        cout << fullName << " works with clients and makes deals" << endl;
    }
    double GetSalary() const
    {
        return baseSalary + (successfulDeals * 300);
    }
    void ShowCard() const
    {
        cout << "+----------------------------------------------+" << endl;
        cout << "| Position: [Project Manager]                  |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Name: " << fullName << "                        |" << endl;
        cout << "| Experience: " << experience << " years                         |" << endl;
        cout << "| Salary: " << GetSalary() << " USD                          |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "| Action: Works with clients and deals         |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
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
    cout << "\n=== COMPANY REPORT (CARDS) ===" << endl << endl;
    for (int i = 0; i < size; i++)
    {
        company[i]->ShowCard();
        totalSalary += company[i]->GetSalary();
    }
    cout << "================================================" << endl;
    cout << " Total salary of all employees: " << totalSalary << " USD" << endl;
    cout << "================================================" << endl;
    for (int i = 0; i < size; i++)
    {
        delete company[i];
    }
    return 0;
}