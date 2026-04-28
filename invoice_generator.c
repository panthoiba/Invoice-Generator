#include <stdio.h>
#define MAX_PRODUCTS 100

// Product structure to store product details
typedef struct {
    char name[50];
    float price;
    int quantity;
    float discount; // New field for product-specific discount
} Product;

// Function to generate and display the invoice
void printInvoice(Product products[], int count) {

    float total = 0.0;

    // Print invoice header
    printf("\n=========================== INVOICE ===========================\n");
    printf("-------------------------------------------------------------\n");
    printf("| Item Name            | Price   | Qty | Disc | Total       |\n");
    printf("-------------------------------------------------------------\n");

    // Loop to process each product and calculate totals
    for (int i = 0; i < count; i++) {
        float itemTotal = products[i].price * products[i].quantity;
        float discountAmount = (products[i].discount / 100) * itemTotal;
        float finalItemTotal = itemTotal - discountAmount;

        printf("| %-20s | $%-6.2f | %3d | %4.1f%% | $%-10.2f |\n", 
               products[i].name, products[i].price, products[i].quantity, products[i].discount, finalItemTotal);

        total += finalItemTotal;
    }

    // Print total amount due
    printf("-------------------------------------------------------------\n");
    printf("Total Amount Due: $%.2f\n", total);
    printf("===============================================================\n");
    printf("-----------------:THANK YOU, HAVE A NICE DAY:------------------");
}

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    char moreProducts;

    printf("=============================================================\n");
    printf("           WELCOME TO THE SIMPLE INVOICE GENERATOR           \n");
    printf("=============================================================\n");

    // Loop to gather product information from the user
    do {
        if (productCount >= MAX_PRODUCTS) {
            printf("Maximum number of products reached.\n");
            break;
        }

        // Input product details
        printf("\nEnter details for product %d:\n", productCount + 1);
        printf("-------------------------------------------------------------\n");
        printf("Product Name: ");
        scanf("%s", products[productCount].name);
        printf("Product Price: ");
        scanf("%f", &products[productCount].price);
        printf("Product Quantity: ");
        scanf("%d", &products[productCount].quantity);
        printf("Product Discount (in %%): ");
        scanf("%f", &products[productCount].discount);

        productCount++;

        // Check if the user wants to add another product
        printf("\nWould you like to add another product? (y/n): ");
        scanf(" %c", &moreProducts);
    } while (moreProducts == 'y' || moreProducts == 'Y');

    // Call the function to print the invoice
    printInvoice(products, productCount);

    return 0;
}
