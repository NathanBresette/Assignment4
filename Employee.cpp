#include <string>
#include "Employee.h"

Employee::Employee(std::string theName, double theWage, double theHours) {
    name = theName;
    wage = theWage;
    hours = theHours;
}

double Employee::calcPay() const {
    return wage * hours;
}

std::string Employee::getName() const {
    return name;
}
