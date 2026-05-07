#include "Product.h"

int main() {
    int size = 0;
    Product *product = new Product[size];
    
    while(true) {
        int chose = show_menu();
        system("cls");
        
        switch(chose) {
            case 1: print_products(product, size); break;
            case 2: add_product(product, size); break;
            case 3: delete_product(product, size); break;
            case 0: cout << "Goodbye!"; delete[] product; return 0;
            default: cout << "Not available" << endl;
        }
        
        cout << "Do you want to continue ? (1/0) ";
        bool is_continue;
        cin >> is_continue;
        if(!is_continue) break;
    }
    delete[] product; 
    return 0;
}