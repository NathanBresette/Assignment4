#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"
#include "Manager.h"

using namespace std;

int main() {
    int numManagers;
    cout << "Enter the number of managers: ";
    cin >> numManagers;

    // Assuming 100 managers or less
    Manager* managers[100]; 

    // Get data for managers
    for (int managerIndex = 0; managerIndex < numManagers; managerIndex++) {
        string name;
        double wage; 
        double hours; 
        double bonus;

        cout << "\nEnter manager " << managerIndex << " name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter manager " << managerIndex << " hourly wage: ";
        cin >> wage;

        cout << "Enter manager " << managerIndex << " hours worked: ";
        cin >> hours;

        cout << "Enter manager " << managerIndex << " bonus: ";
        cin >> bonus;

        // Create a Manager object and store the pointer 
        managers[managerIndex] = new Manager(name, wage, hours, bonus);
    }

    double highestPay = 0.0;
    string highestPaidManagerName;
    double totalPay = 0.0;

    // Find the highest paid manager and calculate the total pay
    for (int managerIndex = 0; managerIndex < numManagers; managerIndex++) {
        double managerPay = managers[managerIndex]->calcPay();
        totalPay += managerPay;

        if (managerPay > highestPay) {
            highestPay = managerPay;
            highestPaidManagerName = managers[managerIndex]->getName();
        }
    }

    // Calculate the average 
    double averagePay = totalPay / numManagers;

    // Output
    cout << "\nHighest paid manager is " << highestPaidManagerName << " who is paid $"
        << fixed << setprecision(2) << highestPay << endl;
    cout << "Average pay is $" << fixed << setprecision(2) << averagePay << endl;

    // Deallocate memory 
    for (int managerIndex = 0; managerIndex < numManagers; managerIndex++) {
        delete managers[managerIndex];
    }

    return 0;
}
