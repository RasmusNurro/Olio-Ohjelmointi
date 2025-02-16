#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

int main() {
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student age: ";
            cin >> age;
            studentList.emplace_back(name, age);
            break;
        }
        case 1:
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 2:
            Student::sortByName(studentList);
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 3:
            Student::sortByAge(studentList);
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 4: {
            string searchName;
            cout << "Enter student name to search: ";
            cin >> searchName;
            Student::findAndPrintStudent(studentList, searchName);
            break;
        }
        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}
