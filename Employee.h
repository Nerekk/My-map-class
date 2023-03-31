#ifndef UNTITLED2_EMPLOYEE_H
#define UNTITLED2_EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    string position;
    int age;


    Employee() {
        this->name = "";
        this->position = "";
        this->age = 0;
    }

    Employee(string name, string position, int age) {
        this->name = name;
        this->position = position;
        this->age = age;
    }

    friend ostream& operator<<(ostream& os, const Employee& employee) {
        os << "name: " << employee.name << ", position: " << employee.position << ", age: " << employee.age;
        return os;
    }
};


#endif
