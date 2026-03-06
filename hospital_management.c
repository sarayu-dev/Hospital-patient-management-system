#include <stdio.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    float bill;
};

struct Patient p[100];
int count = 0;
int nextID = 1;

void addPatient() {
    if (count == 100) {
        printf("Hospital is full. Cannot add more patients.\n");
        return;
    }

    p[count].id = nextID;
    nextID++;

    printf("Patient ID assigned: %d\n", p[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p[count].disease);

    printf("Enter Bill Amount: ");
    scanf("%f", &p[count].bill);

    count++;

    printf("Patient added successfully!\n");
}

void displayPatients() {
    if (count == 0) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n%-5s %-20s %-5s %-20s %-10s\n", "ID", "Name", "Age", "Disease", "Bill");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %-20s %-10.2f\n",
               p[i].id,
               p[i].name,
               p[i].age,
               p[i].disease,
               p[i].bill);
    }
}

void searchPatient() {
    int id, found = 0;

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nPatient Found:\n");
            printf("Name: %s\n", p[i].name);
            printf("Age: %d\n", p[i].age);
            printf("Disease: %s\n", p[i].disease);
            printf("Bill: %.2f\n", p[i].bill);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

void deletePatient() {
    int id, index = -1;

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        p[i] = p[i + 1];
    }

    count--;

    printf("Patient deleted successfully.\n");
}

void updateBill() {
    int id, found = 0;

    printf("Enter Patient ID to update bill: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter new bill amount: ");
            scanf("%f", &p[i].bill);
            printf("Bill updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

void totalRevenue() {
    float total = 0;

    if (count == 0) {
        printf("No patient records found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        total += p[i].bill;
    }

    printf("Total Hospital Revenue: %.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n--- Hospital Patient Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Update Bill\n");
        printf("6. Show Total Revenue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: updateBill(); break;
            case 6: totalRevenue(); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}
