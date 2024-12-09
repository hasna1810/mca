#include <stdio.h>

int i, setA[10], setB[10], setC[20], m, n;
void create();
void unionset();
void is_disjoint();

int main()
{
    int c;
    while (1)
    {
        printf("\n1. Creation\n2. Union\n3. Check Disjoint\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                create();
                break;
            case 2:
                unionset();
                break;
            case 3:
                is_disjoint();
                break;
            case 4:
                return 0;

            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}

void create()
{
    printf("Enter the limit of the first set: ");
    scanf("%d", &m);
    printf("Enter the first set:\n");
    for (i = 1; i <= m; i++)
        scanf("%d", &setA[i]);
    printf("Enter the limit of the second set: ");
    scanf("%d", &n);
    printf("Enter the second set:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &setB[i]);
    printf("\nSET A: {");
    for (i = 1; i <= m; i++)
        printf("%d,", setA[i]);
    printf("}\n");
    printf("SET B: {");
    for (i = 1; i <= n; i++)
        printf("%d,", setB[i]);
    printf("}\n");
}

void unionset()
{
    int j;
    for (i = 1; i <= m; i++)
        setC[i] = setA[i];
    j = m + 1;
    for (i = 1; i <= n; i++)
    {
        setC[j] = setB[i];
        j++;
    }
    printf("\nUNION SET: {");
    for (i = 1; i <= m + n; i++)
        printf("%d,", setC[i]);
    printf("}\n");
}

void is_disjoint()
{
    int isDisjoint = 1; // Flag to check if sets are disjoint
    for (i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (setA[i] == setB[j])
            {
                isDisjoint = 0; // Common element found
                break;
            }
        }
        if (!isDisjoint)
            break;
    }

    if (isDisjoint)
        printf("\nThe sets are disjoint.\n");
    else
        printf("\nThe sets are not disjoint.\n");
}
