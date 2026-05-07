#include "Product.h"

istream& operator>>(istream &is, Product &product) {
    cout << "Name: ";
    is.ignore(); 
    getline(is, product.name);
    cout << "Price: ";
    is >> product.price;
    cout << "Quantity: ";
    is >> product.quantity;
    return is;
}

ostream& operator<<(ostream &os, const Product &product) {
    os << "Name: " << product.name << ", Price: " << product.price << ", Quantity: " << product.quantity;
    return os;
}

int show_menu() {
    int chose;
    cout << "===== MENU =====" << endl;
    cout << "1. Show the list" << endl;
    cout << "2. Add new item" << endl;
    cout << "3. Delete item" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
    cin >> chose;
    return chose;
}

void print_products(Product *product, int size) {
    if (size == 0) {
        cout << "No product." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << product[i] << endl;
        }
    }
}

void add_product(Product* &product, int &size) {
    Product new_product;
    cin >> new_product;
    
    Product *tmp = new Product[size + 1];
    for (int i = 0; i < size; i++) tmp[i] = product[i];
    tmp[size] = new_product;
    
    delete[] product;
    product = tmp;
    size++;
}

void delete_product(Product* &product, int &size){
	cout << "Name of item ";
	string delete_name;
	cin.ignore();
	getline(cin, delete_name);
	int deleted_index = -1;
	
	for (int i =0; i < size; i++){
		if(!delete_name.compare(product[i].name)){
			deleted_index = i;
			break;
		}
	}		
	
	if (deleted_index == -1){
		cout << "Product not found " << endl;
		return;
	}

	for(int i = deleted_index; i < size -1; i++){
		product[i] = product[i+1];
	}
	size--;
	Product *tmp_product = new Product[size];
	
	for (int i = 0; i < size; i++){
		tmp_product[i] = product[i];
	}
	
	delete[] product;
	product = tmp_product;
	cout << "Delete success!" << endl;
}