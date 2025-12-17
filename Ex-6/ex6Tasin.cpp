#include <iostream>
using namespace std;


typedef struct Node {
    int row, col, val;
    struct Node *next;
} Node;


bool isSparseMatrix(int A[20][20], int m, int n) {
    int zeroCount = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 0)
                zeroCount++;

    
    return (zeroCount > (m * n) / 2);
}


void toTripletForm(int A[20][20], int m, int n,
                   int rowArr[], int colArr[], int valArr[], int &count) {
    count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                rowArr[count] = i;
                colArr[count] = j;
                valArr[count] = A[i][j];
                count++;
            }
        }
    }
}

Node* toLinkedListForm(int A[20][20], int m, int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                Node *temp = new Node;
                temp->row = i;
                temp->col = j;
                temp->val = A[i][j];
                temp->next = NULL;

                if (head == NULL) {
                    head = temp;
                    tail = temp;
                } else {
                    tail->next = temp;
                    tail = temp;
                }
            }
        }
    }
    return head;
}


void displayLinkedList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << "(" << curr->row << " " << curr->col << " " << curr->val << ")";
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}


int main() {
    int m, n;
    int A[20][20];

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    cout << "Enter matrix elements row by row:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    if (isSparseMatrix(A, m, n)) {
        cout << "\nThis is a sparse matrix.\n";

        
        int rowArr[100], colArr[100], valArr[100], count;
        toTripletForm(A, m, n, rowArr, colArr, valArr, count);

        cout << "\nTriplet Representation:\n";
        cout << "Row:    ";
        for (int i = 0; i < count; i++) cout << rowArr[i] << " ";
        cout << "\nColumn: ";
        for (int i = 0; i < count; i++) cout << colArr[i] << " ";
        cout << "\nValue:  ";
        for (int i = 0; i < count; i++) cout << valArr[i] << " ";
        cout << endl;

    
        Node *head = toLinkedListForm(A, m, n);
        cout << "\nLinked List Representation:\n";
        displayLinkedList(head);

    } else {
        cout << "\nThis is NOT a sparse matrix.\n";
    }

    return 0;
}

