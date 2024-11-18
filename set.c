#include <stdio.h>
#include <stdlib.h>

#define SIZE 11 // Define the bit string size (adjust as needed)

// Function to print a set as elements
void printSet(int set[]) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1) // Print only if the bit is set (1)
            printf("%d ", i);
    }
    printf("}\n");
}

// Function to print a set as a bit-string
void printSetAsBitString(int set[]) {
    // Print as a set of elements first
    printf("Set representation: ");
    printSet(set);

    // Print as a bit-string
    printf("Bit string: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", set[i]);
    }
    printf("\n");
}

// Function to perform union operation on two sets
void unionSet(int setA[], int setB[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] | setB[i];
}

// Function to perform intersection operation on two sets
void intersectionSet(int setA[], int setB[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] & setB[i];
}

// Function to perform difference operation (A - B)
void differenceSet(int setA[], int setB[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] & ~setB[i];
}

int main() {
    int setA[SIZE] = {0}, setB[SIZE] = {0}, result[SIZE] = {0};
    int choice, n, elem;

    // Input for Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &n);
    printf("Enter elements (0-%d) for Set A: ", SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        if (elem >= 0 && elem < SIZE)
            setA[elem] = 1; // Set bit corresponding to the element
    }

    // Input for Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &n);
    printf("Enter elements (0-%d) for Set B: ", SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        if (elem >= 0 && elem < SIZE)
            setB[elem] = 1; // Set bit corresponding to the element
    }

    // Menu-driven loop for set operations
    while (1) {
        printf("\nChoose the set operation:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (A - B)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                unionSet(setA, setB, result);
                printf("Union of Set A and Set B:\n");
                printSetAsBitString(result); // Print both representations
                break;
            case 2:
                intersectionSet(setA, setB, result);
                printf("Intersection of Set A and Set B:\n");
                printSetAsBitString(result); // Print both representations
                break;
            case 3:
                differenceSet(setA, setB, result);
                printf("Difference (A - B):\n");
                printSetAsBitString(result); // Print both representations
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}



