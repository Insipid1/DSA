#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    free(delNode);
}

void disp(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original list:\n");
    disp(head);

    insertAfter(second, 25);
    printf("\nAfter inserting 25 after 20:\n");
    disp(head);

    deleteNode(&head, second->next);
    printf("\nAfter deleting 25:\n");
    disp(head);

    return 0;
}
