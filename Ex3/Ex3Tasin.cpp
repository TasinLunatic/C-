#include <iostream>
#include <cctype>   
using namespace std;


struct Node {
    char data;
    Node* next;
};


struct LinkedList {
    Node* head;
    int size;
    int capacity;
};


void InitList(LinkedList &list) {
    list.head = NULL;
    list.size = 0;
    list.capacity = 26;   
}


bool IsEmpty(LinkedList &list) {
    return (list.size == 0);
}


bool IsFull(LinkedList &list) {
    return (list.size == list.capacity);
}

void InsertItem(LinkedList &list, char letter) {
    Node* newNode = new Node;
    newNode->data = letter;
    newNode->next = NULL;

    if (list.head == NULL) {
        list.head = newNode;
    } else {
        Node* temp = list.head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    list.size++;
}


void PrintList(LinkedList &list) {
    Node* temp = list.head;
    while (temp != NULL) {
        cout << (char)toupper(temp->data) << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DeleteList(LinkedList &list) {
    Node* temp = list.head;
    while (temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    list.head = NULL;
    list.size = 0;
}

int main() {
    LinkedList list;
    InitList(list);

    char ch;
    cout << "Enter characters (letters only, others ignored). Program stops at 26 letters.\n";
    while (!IsFull(list) && cin.get(ch)) {
        if (isalpha(ch)) {
            InsertItem(list, ch);
        } else if (ch != '\n') {
            cout << "Ignored non-letter input: " << ch << endl;
        }
    }

    cout << "\nStored letters (" << list.size << "):\n";
    PrintList(list);

    DeleteList(list);
    return 0;
}

