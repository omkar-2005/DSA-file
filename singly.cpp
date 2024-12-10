#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertbeg(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->next = head;
    head = newnode;
}

void insertend(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void insertloc(int item, int l) {
    if (l <= 0) {
        cout << "Invalid location. It must be greater than 0.\n";
        return;
    }
    node* newnode = new node;
    newnode->data = item;

    if (l == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        node* ptr = head;
        node* pre = NULL;
        int c = 1;
        while (ptr != NULL && c < l) {
            pre = ptr;
            ptr = ptr->next;
            c++;
        }
        if (c == l) {
            newnode->next = ptr;
            pre->next = newnode;
        } else {
            cout << "Location out of bounds. Inserting at the end.\n";
            insertend(item);
        }
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

void deletebeg() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    node* ptr = head;
    head = head->next;
    cout << "Deleted node is " << ptr->data << "\n";
    delete ptr;
    cout << "Linked List after deletion: \n";
    display();
}

void count() {
    int count = 0;
    node* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    cout << "Number of nodes in the linked list: " << count << "\n";
}

int main() {
    int item, l, ch;
    do {
        cout << "\n1. Insertion at beginning";
        cout << "\n2. Insertion at end";
        cout << "\n3. Insertion at location";
        cout << "\n4. Display";
        cout << "\n5. Count nodes";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> item;
                insertbeg(item);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> item;
                insertend(item);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> item;
                cout << "Enter location at which you want to insert: ";
                cin >> l;
                insertloc(item, l);
                break;
            case 4:
                display();
                break;
            case 5:
                count();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 6);

    return 0;
}
