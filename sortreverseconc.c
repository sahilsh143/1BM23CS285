#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}


int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}


int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}


void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}


int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}


int peekQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}


int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;


    append(&list1, 3);
    append(&list1, 1);
    append(&list1, 2);

    printf("Original List1:\n");
    display(list1);

    sortList(list1);
    printf("Sorted List1:\n");
    display(list1);

    reverseList(&list1);
    printf("Reversed List1:\n");
    display(list1);

    append(&list2, 5);
    append(&list2, 4);

    concatenateLists(&list1, list2);
    printf("Concatenated List1 + List2:\n");
    display(list1);


    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Stack after pushes:\n");
    display(stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Stack after pop:\n");
    display(stack);

    printf("Peek top element: %d\n", peek(stack));


    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    enqueue(&queueFront, &queueRear, 300);
    printf("Queue after enqueues:\n");
    display(queueFront);

    printf("Dequeued element: %d\n", dequeue(&queueFront, &queueRear));  // Pass both front and rear
    printf("Queue after dequeue:\n");
    display(queueFront);

    printf("Peek front element: %d\n", peekQueue(queueFront));

    return 0;
}
