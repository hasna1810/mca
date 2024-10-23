#include <stdio.h>
#include <stdlib.h>

// Global variable for the count of nodes
int c = 0;

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global variable for the head of the stack (top of the stack)
struct Node* top = NULL;

// Function prototypes
void push(); // To insert an element (push onto the stack)
void pop();  // To delete an element (pop from the stack)
void display(); // To display the stack contents

int main() {
    int choice;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to push a new node onto the stack
void push() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = top; // Link the new node to the current top
    top = newNode; // Update the top to the new node
    c++; // Increment the count of nodes
    printf("Node with data %d pushed. Current count: %d\n", newNode->data, c);
}

// Function to pop a node from the stack
void pop() {
    if (top == NULL) {
        printf("The stack is empty, nothing to pop.\n");
        return; // No node to pop
    }
    struct Node* temp = top;
    top = top->next; // Move top to the next node
    printf("The popped element is %d.\n", temp->data); // Print the popped node's data
    free(temp); // Free the memory of the popped node
    c--; // Decrement the count of nodes
}

// Function to display the contents of the stack
void display() {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Count: %d\n", c); // Display the count of nodes
}
