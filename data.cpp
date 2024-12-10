#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int rollno;
    char name[30];
    char division[5];
    char address[50];
};

// Function declarations
void addRecord();
void displayRecords();
void searchRecord(int rollno);
void deleteRecord(int rollno);

int main() {
    int choice, rollno;

    do {
        cout << "\nMenu:";
        cout << "\n1. Add Records";
        cout << "\n2. Display All Records";
        cout << "\n3. Search Record by Roll No";
        cout << "\n4. Delete Record by Roll No";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "\nEnter roll number to search: ";
                cin >> rollno;
                searchRecord(rollno);
                break;
            case 4:
                cout << "\nEnter roll number to delete: ";
                cin >> rollno;
                deleteRecord(rollno);
                break;
            case 5:
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice! Try again.";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a record to the file
void addRecord() {
    ofstream outfile("students.dat", ios::binary | ios::app);
    if (!outfile) {
        cout << "Error opening file!";
        return;
    }

    Student s;
    cout << "\nEnter Roll Number: ";
    cin >> s.rollno;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(s.name, 30);
    cout << "Enter Division: ";
    cin >> s.division;
    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(s.address, 50);

    outfile.write(reinterpret_cast<char*>(&s), sizeof(s));
    outfile.close();
    cout << "Record added successfully.";
}

// Function to display all records
void displayRecords() {
    ifstream infile("students.dat", ios::binary);
    if (!infile) {
        cout << "Error opening file or file is empty!";
        return;
    }

    Student s;
    cout << "\nRoll No\tName\tDivision\tAddress";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        cout << "\n" << s.rollno << "\t" << s.name << "\t" << s.division << "\t" << s.address;
    }
    infile.close();
}

// Function to search for a record by roll number
void searchRecord(int rollno) {
    ifstream infile("students.dat", ios::binary);
    if (!infile) {
        cout << "Error opening file!";
        return;
    }

    Student s;
    bool found = false;
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.rollno == rollno) {
            cout << "\nRecord Found:";
            cout << "\nRoll No: " << s.rollno;
            cout << "\nName: " << s.name;
            cout << "\nDivision: " << s.division;
            cout << "\nAddress: " << s.address;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord with Roll No " << rollno << " not found.";
    }

    infile.close();
}

// Function to delete a record by roll number
void deleteRecord(int rollno) {
    ifstream infile("students.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
    if (!infile || !tempFile) {
        cout << "Error opening file!";
        return;
    }

    Student s;
    bool found = false;
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.rollno == rollno) {
            found = true;
            cout << "\nRecord with Roll No " << rollno << " deleted.";
        } else {
            tempFile.write(reinterpret_cast<char*>(&s), sizeof(s));
        }
    }

    infile.close();
    tempFile.close();
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (!found) {
        cout << "\nRecord with Roll No " << rollno << " not found.";
    }
}