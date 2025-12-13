#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 26

// Structure for static sequential list
typedef struct {
    char data[MAX_SIZE];
    int length;
} SeqList;

// Initialize the list (capacity = 26, length = 0)
void InitList(SeqList *list) {
    list->length = 0;
}

// Check if list is full
int IsFull(SeqList *list) {
    return list->length == MAX_SIZE;
}

// Check if list is empty
int IsEmpty(SeqList *list) {
    return list->length == 0;
}

// Append (PushBack) a letter to the list
int PushBack(SeqList *list, char ch) {
    if (IsFull(list)) {
        return -1; // Error code
    }
    list->data[list->length++] = ch;
    return 0; // Success
}

// Print list in order; if flag is set, print uppercase
void PrintList(SeqList *list, int upperFlag) {
    for (int i = 0; i < list->length; i++) {
        if (upperFlag)
            printf("%c ", toupper(list->data[i]));
        else
            printf("%c ", list->data[i]);
    }
    printf("\n");
}

// (Optional) Clear the list
void ClearList(SeqList *list) {
    list->length = 0;
}

int main() {
    SeqList list;
    InitList(&list);

    char ch;
    printf("Enter letters (non-letters ignored, max 26):\n");

    while (1) {
        ch = getchar();

        if (ch == EOF) break; // End of input
        if (!isalpha(ch)) {
            printf("Non-letter ignored: %c\n", ch);
            continue;
        }

        if (PushBack(&list, ch) == -1) {
            printf("List is full. Printing result:\n");
            PrintList(&list, 1); // Print in uppercase
            break;
        }
    }

    return 0;
}

