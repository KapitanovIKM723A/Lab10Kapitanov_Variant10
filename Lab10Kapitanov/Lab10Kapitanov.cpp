#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

struct Student {
    string surname;
    int id;
    bool stypendia;
    double avgGrade;
};

const int MAX_STUDENTS = 100;

void inputStudentData(Student students[], int& n) {
    cout << "Введiть кiлькiсть студентiв: ";
    cin >> n;
    if (n > MAX_STUDENTS) n = MAX_STUDENTS;

    for (int i = 0; i < n; ++i) {
        cout << "Введiть прiзвище, порядковий номер, отримує стипендiю (1 - так, 0 - нi), середнiй бал для студента " << i + 1 << ": ";
        cin >> students[i].surname >> students[i].id >> students[i].stypendia >> students[i].avgGrade;
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Прiзвище: " << students[i].surname
            << ", Порядковий номер: " << students[i].id
            << ", Стипендiя: " << (students[i].stypendia ? "Так" : "Нi")
            << ", Середнiй бал: " << students[i].avgGrade << endl;
    }
}

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].avgGrade < students[j + 1].avgGrade) {
                // Swap
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ukr");

    Student students[MAX_STUDENTS];
    int n = 0;

    inputStudentData(students, n);

    cout << "\nПовний список студентів:\n";
    printStudents(students, n);

    sortStudents(students, n);

    cout << "\nСписок студентів за убуванням середнього бала:\n";
    printStudents(students, n);

    return 0;
}