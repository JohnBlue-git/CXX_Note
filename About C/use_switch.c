#include <stdio.h>

int main() {
    int choice;

    printf("Enter a number between 1 and 5: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You entered 1.\n");
            break;
        case 2:
            printf("You entered 2.\n");
            break;
        case 3:
            printf("You entered 3.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
