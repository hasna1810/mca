#include <stdio.h>
#include <stdlib.h>

#define SIZE 11 // Define the bit string size (adjust as needed)

// Function prototypes
void create();
void unionSet();
void intersectionSet();
void differenceSet();
void printSetAsBitString(int set[]);
void printSet(int set[]);

// Global variables
// Initializing the sets directly
int setA[SIZE] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; // Example set A
int setB[SIZE] = {1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1}; // Example set B
int result[SIZE] = {0};

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create Sets (This is now disabled in this example)\n");
        printf("2. Union\n3. Intersection\n4. Difference (A - B)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Create Sets is now disabled, as the sets are initialized.\n");
                break;
            case 2:
                unionSet();
                break;
            case 3:
                intersectionSet();
                break;
            case 4:
                differenceSet();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to perform the union operation
void unionSet()
{
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] | setB[i];

    printf("Union of Set A and Set B:\n");
    printSetAsBitString(result);
}

// Function to perform the intersection operation
void intersectionSet()
{
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] & setB[i];

    printf("Intersection of Set A and Set B:\n");
    printSetAsBitString(result);
}

// Function to perform the difference operation (A - B)
void differenceSet()
{
    for (int i = 0; i < SIZE; i++)
        result[i] = setA[i] & ~setB[i];

    printf("Difference (A - B):\n");
    printSetAsBitString(result);
}

// Function to print a set as elements
void printSet(int set[])
{
    printf("{ ");
    for (int i = 0; i < SIZE; i++)
    {
        if (set[i] == 1) // Print only if the bit is set (1)
            printf("%d ", i);
    }
    printf("}\n");
}

// Function to print a set as a bit-string
void printSetAsBitString(int set[])
{
    printf("Set representation: ");
    printSet(set);
    printf("Bit string: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d", set[i]);
    printf("\n");
}
