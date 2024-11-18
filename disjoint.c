#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elements[MAX];
    int size;
} Set;

// Function to create a set
void createSet(Set *set, int *arr, int size) {
    set->size = size;
    for (int i = 0; i < size; i++) {
        set->elements[i] = arr[i];
    }
}

// Function to display a set
void displaySet(Set *set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

// Function to find if an element exists in a set
int findInSet(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1; // Found
        }
    }
    return 0; // Not Found
}

// Function to perform union of two sets
void unionSets(Set *setA, Set *setB, Set *result) {
    int k = 0;

    // Add all elements of setA
    for (int i = 0; i < setA->size; i++) {
        result->elements[k++] = setA->elements[i];
    }

    // Add elements of setB that are not in setA
    for (int i = 0; i < setB->size; i++) {
        if (!findInSet(setA, setB->elements[i])) {
            result->elements[k++] = setB->elements[i];
        }
    }

    result->size = k;
}

// Function to check if two sets are disjoint
int areDisjoint(Set *setA, Set *setB) {
    for (int i = 0; i < setA->size; i++) {
        if (findInSet(setB, setA->elements[i])) {
            return 0; // Not disjoint
        }
    }
    return 1; // Disjoint
}

int main() {
    Set setA, setB, unionSet;
    int choice, n, m, arrA[MAX], arrB[MAX];

    printf("Enter the number of elements in Set A: ");
    scanf("%d", &n);
    printf("Enter the elements of Set A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }
    createSet(&setA, arrA, n);

    printf("Enter the number of elements in Set B: ");
    scanf("%d", &m);
    printf("Enter the elements of Set B: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arrB[i]);
    }
    createSet(&setB, arrB, m);

    do {
        printf("\nMenu:\n");
        printf("1. Display Sets\n");
        printf("2. Union of Sets\n");
        printf("3. Check if Disjoint\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Set A: ");
                displaySet(&setA);
                printf("Set B: ");
                displaySet(&setB);
                break;
            case 2:
                unionSets(&setA, &setB, &unionSet);
                printf("Union of Set A and Set B: ");
                displaySet(&unionSet);
                break;
            case 3:
                if (areDisjoint(&setA, &setB)) {
                    printf("Set A and Set B are disjoint.\n");
                } else {
                    printf("Set A and Set B are not disjoint.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);


    return 0;
}

