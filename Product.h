#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    int price;
    int quantity;
    
    friend istream& operator>>(istream &is, Product &product);
    friend ostream& operator<<(ostream &os, const Product &product);
};

int show_menu();
void print_products(Product *product, int size);
void add_product(Product* &product, int &size); 
void delete_product(Product* &product, int &size);

#endif