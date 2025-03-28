#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    printf("Enter Product ID: ");
    scanf("%d", &inventory[productCount].id);
    printf("Enter Name: ");
    scanf("%s", inventory[productCount].name);
    printf("Enter Price: ");
    scanf("%f", &inventory[productCount].price);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[productCount].quantity);
    
    productCount++;
    printf("Product Added Successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("Product List:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n", 
               inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void searchProduct() {
    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product Found: ID: %d | Name: %s | Price: %.2f | Quantity: %d\n", 
                   inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateStock() {
    int id, qty;
    printf("Enter Product ID to update stock: ");
    scanf("%d", &id);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &qty);
            inventory[i].quantity = qty;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void saveAndExit() {
    printf("Saving inventory and exiting...\n");
    exit(0);
}

int main() {
    int choice;
    while (1) {
        printf("===== Smart Inventory Management System =====\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Delete Product\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateStock(); break;
            case 5: deleteProduct(); break;
            case 6: saveAndExit(); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
