#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
protected:
    std::string name;
    double wage;
    double hours;

public:
    Employee(std::string theName, double theWage, double theHours);
    double calcPay() const;
    std::string getName() const;
};

#endif 
