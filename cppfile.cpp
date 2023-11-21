#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add_new_student() {
    ofstream outfile;
    outfile.open("students.txt", ios::app);
    string name, reg_no;
    int cse1001, cse1002;
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the registration number of the student: ";
    cin >> reg_no;
    cout << "Enter the marks obtained in CSE1001: ";
    cin >> cse1001;
    cout << "Enter the marks obtained in CSE1002: ";
    cin >> cse1002;
    outfile << name << " " << reg_no << " " << cse1001 << " " << cse1002 << endl;
    outfile.close();
    cout << "Student added successfully!" << endl;
}

void delete_student() {
    ifstream infile;
    ofstream outfile;
    infile.open("students.txt");
    outfile.open("temp.txt");
    string reg_no;
    bool found = false;
    cout << "Enter the registration number of the student to be deleted: ";
    cin >> reg_no;
    string name, reg, cse1001, cse1002;
    while (infile >> name >> reg >> cse1001 >> cse1002) {
        if (reg != reg_no) {
            outfile << name << " " << reg << " " << cse1001 << " " << cse1002 << endl;
        } else {
            found = true;
        }
    }
    infile.close();
    outfile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) {
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "No student found with the given registration number." << endl;
    }
}

void show_all_students() {
    ifstream infile;
    infile.open("students.txt");
    string name, reg, cse1001, cse1002;
    cout << "Name\tRegistration Number\tCSE1001\tCSE1002" << endl;
    while (infile >> name >> reg >> cse1001 >> cse1002) {
        cout << name << "\t" << reg << "\t" << cse1001 << "\t" << cse1002 << endl;
    }
    infile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Show all students" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                add_new_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                show_all_students();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
