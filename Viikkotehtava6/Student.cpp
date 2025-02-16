#include "Student.h"
#include <algorithm>

Student::Student(string n, int a) : name(n), age(a) {}

void Student::setName(string n) {
    name = n;
}

void Student::setAge(int a) {
    age = a;
}

string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

void Student::printStudentInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void Student::sortByName(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });
}

void Student::sortByAge(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getAge() < b.getAge();
    });
}

void Student::findAndPrintStudent(const vector<Student>& students, const string& searchName) {
    auto it = find_if(students.begin(), students.end(), [&searchName](const Student& s) {
        return s.getName() == searchName;
    });
    if (it != students.end()) {
        it->printStudentInfo();
    } else {
        cout << "Student not found." << endl;
    }
}
