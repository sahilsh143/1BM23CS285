#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


void createList(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    *head = newNode;
}


void insertLeft(struct Node** head, int target, int data) {
    if (*head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == target) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            newNode->next = current;
            newNode->prev = current->prev;


            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {

                *head = newNode;
            }

            current->prev = newNode;

            printf("Node with value %d inserted to the left of node with value %d\n", data, target);
            return;
        }
        current = current->next;
    }

    printf("Node with value %d not found!\n", target);
}


void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {

            if (current->prev == NULL) {
                *head = current->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            } else {

                current->prev->next = current->next;


                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }

            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        current = current->next;
    }

    printf("Node with value %d not found!\n", value);
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;


    createList(&head, 10);
    display(head);


    insertLeft(&head, 10, 5);
    display(head);


    insertLeft(&head, 5, 3);
    display(head);

    deleteNode(&head, 5);
    display(head);

    deleteNode(&head, 3);
    display(head);


    deleteNode(&head, 10);
    display(head);

    return 0;
}
