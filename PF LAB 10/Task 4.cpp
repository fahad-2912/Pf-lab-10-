#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

struct TravelPackage {
    char name[50];
    char destination[50];
    int duration;
    float cost;
    int seatsAvailable;
};

void bookPackage(struct TravelPackage packages[], int packageCount);
void displayPackages(struct TravelPackage packages[], int packageCount);
void addPackage(struct TravelPackage packages[], int *packageCount);

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    do {
        printf("\nTravel Package Management System\n");
        printf("1. Add a Travel Package\n");
        printf("2. Book a Travel Package\n");
        printf("3. Display Available Packages\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPackage(packages, &packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                displayPackages(packages, packageCount);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addPackage(struct TravelPackage packages[], int *packageCount) {
    if (*packageCount >= MAX_PACKAGES) {
        printf("Cannot add more packages. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter details for the new travel package:\n");
    printf("Package Name: ");
    scanf(" %[^\n]", packages[*packageCount].name);
    printf("Destination: ");
    scanf(" %[^\n]", packages[*packageCount].destination);
    printf("Duration (in days): ");
    scanf("%d", &packages[*packageCount].duration);
    printf("Cost: ");
    scanf("%f", &packages[*packageCount].cost);
    printf("Seats Available: ");
    scanf("%d", &packages[*packageCount].seatsAvailable);

    (*packageCount)++;
    printf("Travel package added successfully!\n");
}

void bookPackage(struct TravelPackage packages[], int packageCount) {
    char packageName[50];
    int seatsToBook;
    int found = 0;

    if (packageCount == 0) {
        printf("No travel packages available to book.\n");
        return;
    }

    printf("\nEnter the name of the travel package you want to book: ");
    scanf(" %[^\n]", packageName);

    for (int i = 0; i < packageCount; i++) {
        if (strcmp(packages[i].name, packageName) == 0) {
            found = 1;
            printf("Enter the number of seats to book: ");
            scanf("%d", &seatsToBook);

            if (seatsToBook > packages[i].seatsAvailable) {
                printf("Not enough seats available. Only %d seats left.\n", packages[i].seatsAvailable);
            } else {
                packages[i].seatsAvailable -= seatsToBook;
                printf("Booking successful! You have booked %d seat(s) for the %s package.\n", seatsToBook, packages[i].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Package not found.\n");
    }
}

void displayPackages(struct TravelPackage packages[], int packageCount) {
    if (packageCount == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("\nPackage: %s\n", packages[i].name);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
    }
}


