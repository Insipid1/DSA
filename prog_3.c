#include <stdio.h>
#include <stdlib.h> // malloc yesma huncha


struct Node {
int data;
struct Node* next;
};


struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}


void insertEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);


if (*head == NULL) {
*head = newNode;
return;
}


struct Node* temp = *head;
while (temp->next != NULL)
temp = temp->next;


temp->next = newNode;
}




void traverseReverse(struct Node* head) {
if (head == NULL)
return;


traverseReverse(head->next);
printf("%d -> ", head->data);
}


int main() {
struct Node* head = NULL;


insertEnd(&head, 10);
insertEnd(&head, 20);
insertEnd(&head, 30);
insertEnd(&head, 40);


printf("\nReverse Traversal:\n");
traverseReverse(head);
printf("NULL\n");


return 0;
}