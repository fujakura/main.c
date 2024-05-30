#define _CRT_SECURE_NO_WARNINGS
#include "lr.h"

int main()
{
    printf("Laboratory work or additional task? \n");
    int M;
    int choice;
    int number;
    scanf("%d", &M);

    if (M == 1)
    {
        printf("1. Find area remaining piece.\n");
        printf("2. Calculation of the sum of a series.\n");
        printf("3. Words start with a vowel letter and end with a consonant.\n");
        printf("4. Delete words containing two consecutive vowel letters.\n");
        printf("5. Print the largest sum of even and odd numbers.\n");
        printf("6. Replace the negative ones with the minimum element of the array, and the positive ones with the maximum.\n");
        printf("7. Swap pairs of binary digits in the mirror order.\n");
        printf("Enter your choice. \n");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
        case 1:
            remainingfigure();
            break;
        case 2:
            stroka();
            break;
        case 3:
            string();
            break;
        case 4:
            glasn2();
            break;
        case 5:
            massiv();
            break;
        case 6:
            dvmassiv();
            break;
        case 7:
            bits();
            break;
        }
    }

    else if (M == 2)
    {
        printf("1. Squaringc Function.\n");
        printf("2. Working Cycle For.\n");
        scanf("%d", &number);
        while (getchar() != '\n');
        switch (number)
        {
        case 1:
            squaringfunction();
            break;
        case 2:
            cyclefor();
            break;
        }
    }
    system("pause");

    return 0;
}
