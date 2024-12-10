#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int rollno;
    char name[30];
    float sgpa;
};

void display(struct Student s[], int n);
void bubbleSort(struct Student s[], int n);
void insertionSort(struct Student s[], int n);
void binarySearch(struct Student s[], int n, char data[]);

int main() {
    struct Student s[30];
    int n, ch;
    char na[30];

    cout << "Enter total students: ";
    cin >> n;

    cout << "\nEnter student information: ";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter roll number, name and SGPA: ";
        cin >> s[i].rollno >> s[i].name >> s[i].sgpa;
    }
    display(s, n);

    do {
        cout << "\n\nMenu:";
        cout << "\n1. Bubble Sort (Sorting by roll numbers)";
        cout << "\n2. Insertion Sort (Sorting by names)";
        cout << "\n3. Binary Search (Search by name)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                bubbleSort(s, n);
                break;
            case 2:
                insertionSort(s, n);
                break;
            case 3:
                cout << "\nEnter name to search: ";
                cin >> na;
                binarySearch(s, n, na);
                break;
            case 4:
                break;
            default:
                cout << "\nInvalid choice.";
        }
    } while (ch != 4);

    return 0;
}

void display(struct Student s[], int n) {
    cout << "\nRoll No\tName\tSGPA";
    for (int i = 0; i < n; i++) {
        cout << "\n" << s[i].rollno << "\t" << s[i].name << "\t" << s[i].sgpa;
    }
}

void bubbleSort(struct Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rollno > s[j + 1].rollno) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    cout << "\nSorted data by Roll Numbers:";
    display(s, n);
}

void insertionSort(struct Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
    cout << "\nSorted data by Names:";
    display(s, n);
}

void binarySearch(struct Student s[], int n, char data[]) {
    // Sort array by name before binary search
    insertionSort(s, n);
    
    int left = 0, right = n - 1, mid, flag = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(s[mid].name, data) == 0) {
            cout << "\nRoll No: " << s[mid].rollno;
            cout << "\nName: " << s[mid].name;
            cout << "\nSGPA: " << s[mid].sgpa;
            flag = 1;
            break;
        } else if (strcmp(data, s[mid].name) < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (!flag) {
        cout << "\nData not found.";
    }
}