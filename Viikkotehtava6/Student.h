#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a);

    void setName(string n);
    void setAge(int a);

    string getName() const;
    int getAge() const;

    void printStudentInfo() const;

    static void sortByName(vector<Student>& students);
    static void sortByAge(vector<Student>& students);
    static void findAndPrintStudent(const vector<Student>& students, const string& searchName);
};

#endif
