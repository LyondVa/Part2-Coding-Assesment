// inventory.cpp
#include "inventory.h"
#include <iostream>
#include <algorithm>
#include <limits>

// Calculates the total value of the inventory
double calculateTotalValue(const std::vector<Product> &inventory) {
    double total = 0.0;
    for (const Product &product: inventory) {
        total += product.price * product.quantity;
    }
    return total;
}

// Finds the most expensive product in the inventory
Product findMostExpensiveProduct(const std::vector<Product> &inventory) {
    Product mostExpensive = inventory[0];
    for (const Product &product: inventory) {
        if (product.price > mostExpensive.price) {
            mostExpensive = product;
        }
    }
    return mostExpensive;
}

// Checks if a product with the given name is in stock
bool isProductInStock(const std::vector<Product>& inventory, const std::string& name) {
    return std::any_of(inventory.begin(), inventory.end(),
                       [name](const Product& product) { return product.name == name; });
}

// Sorts the inventory by price or quantity in ascending or descending order
void sortProducts(std::vector<Product> &inventory, const bool byPrice, bool descending) {
    if (byPrice) {
        std::sort(inventory.begin(), inventory.end(), [descending](const Product &a, const Product &b) {
            if (descending) {
                return a.price > b.price; // Sort by price descending
            } else {
                return a.price < b.price; // Sort by price ascending
            }
        });
    } else {
        std::sort(inventory.begin(), inventory.end(), [descending](const Product &a, const Product &b) {
            if (descending) {
                return a.quantity > b.quantity; // Sort by quantity descending
            } else {
                return a.quantity < b.quantity; // Sort by quantity ascending
            }
        });
    }
}

int main() {
    std::vector<Product> inventory = {
        {"Laptops", 999.99, 5},
        {"Smartphones", 499.99, 10},
        {"Tablets", 299.99, 0},
        {"Smartwatch", 199.99, 3}
    };

    // Calculate the total inventory value
    const double totalValue = calculateTotalValue(inventory);
    std::cout << "Total inventory value: " << totalValue << std::endl;

    // Find the most expensive product
    const Product mostExpensive = findMostExpensiveProduct(inventory);
    std::cout << "Most expensive product: " << mostExpensive.name << std::endl;

    // Check if "Headphones" are in stock
    const bool isHeadphonesInStock = isProductInStock(inventory, "Headphones");
    std::cout << "Headphones in stock: " << (isHeadphonesInStock ? "true" : "false") << std::endl;

    char userInput;

    // Get user input for sorting by price
    do {
        std::cout << "Sort products by price? (y - price/n - quantity): ";
        std::cin >> userInput;
    } while (userInput != 'y' && userInput != 'n');

    const bool byPrice = userInput == 'y';

    // Get user input for sorting order
    do {
        std::cout << "Sort products in descending order? (y - descending/n - ascending): ";
        std::cin >> userInput;
    } while (userInput != 'y' && userInput != 'n');

    const bool isDescending = userInput == 'y';

    // Flush the input buffer to avoid unexpected behavior in subsequent input operations
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Sort products by price in descending order
    sortProducts(inventory, byPrice, isDescending);

    // Print the sorted products
    std::cout << "Sorted products:\n";
    for (const auto &[name, price, quantity] : inventory) {
        std::cout << name << " " << price << " " << quantity << std::endl;
    }

    return 0;
}