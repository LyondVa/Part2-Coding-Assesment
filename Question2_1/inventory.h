// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

struct Product {
    std::string name;
    double price;
    int quantity;
};

// Calculates the total value of the inventory
double calculateTotalValue(const std::vector<Product>& inventory);

// Finds the most expensive product in the inventory
Product findMostExpensiveProduct(const std::vector<Product>& inventory);

// Checks if a product with the given name is in stock
bool isProductInStock(const std::vector<Product>& inventory, const std::string& name);

// Sorts the inventory by price or quantity in ascending or descending order
void sortProducts(std::vector<Product>& inventory, bool byPrice, bool descending);

#endif // INVENTORY_H