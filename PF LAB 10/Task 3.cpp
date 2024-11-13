#include <stdio.h>
#include <string.h>

#define MAX_CARS 100


struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

void addCar(struct Car cars[], int *carCount);
void displayCars(struct Car cars[], int carCount);
void searchCars(struct Car cars[], int carCount);

int main() {
    struct Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    
    do {
        printf("\nCar Dealership Management System\n");
        printf("1. Add New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
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

void addCar(struct Car cars[], int *carCount) {
    if (*carCount >= MAX_CARS) {
        printf("Car list is full. Cannot add more cars.\n");
        return;
    }

    printf("\nEnter details for the new car:\n");
    printf("Make: ");
    scanf(" %[^\n]", cars[*carCount].make);
    printf("Model: ");
    scanf(" %[^\n]", cars[*carCount].model);
    printf("Year: ");
    scanf("%d", &cars[*carCount].year);
    printf("Price: ");
    scanf("%f", &cars[*carCount].price);
    printf("Mileage: ");
    scanf("%f", &cars[*carCount].mileage);

    (*carCount)++;
    printf("Car added successfully!\n");
}


void displayCars(struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\nList of Available Cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("\nCar %d\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %.2f miles\n", cars[i].mileage);
    }
}


void searchCars(struct Car cars[], int carCount) {
    char search[50];
    int found = 0;

    if (carCount == 0) {
        printf("No cars available to search.\n");
        return;
    }

    printf("Enter make or model to search: ");
    scanf(" %[^\n]", search);

    printf("\nSearch Results:\n");
    for (int i = 0; i < carCount; i++) {
        if (strstr(cars[i].make, search) || strstr(cars[i].model, search)) {
            printf("\nCar %d\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %.2f miles\n", cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found with make or model '%s'.\n", search);
    }
}

