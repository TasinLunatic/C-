#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 26


typedef struct {
    char data[MAX_SIZE];
    int length;
} SeqList;

// Initialize the list (capacity = 26, length = 0)
void InitList(SeqList *list) {
    list->length = 0;
}


int IsFull(SeqList *list) {
    return list->length == MAX_SIZE;
}

int IsEmpty(SeqList *list) {
    return list->length == 0;
}

int PushBack(SeqList *list, char ch) {
    if (IsFull(list)) {
        return -1; 
    }
    list->data[list->length++] = ch;
    return 0; 
}


void PrintList(SeqList *list, int upperFlag) {
    for (int i = 0; i < list->length; i++) {
        if (upperFlag)
            printf("%c ", toupper(list->data[i]));
        else
            printf("%c ", list->data[i]);
    }
    printf("\n");
}


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

        if (ch == EOF) break; 
        if (!isalpha(ch)) {
            printf("Non-letter ignored: %c\n", ch);
            continue;
        }

        if (PushBack(&list, ch) == -1) {
            printf("List is full. Printing result:\n");
            PrintList(&list, 1); 
            break;
        }
    }

    return 0;
}

