#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class InventoryItem {
public:
	InventoryItem(string sku, double price, size_t quantity, bool onSale) : _sku(sku), _price(price), _quantity(quantity), _onSale(onSale)
	{}
	string getSku() const { return _sku; }
	double getPrice() const { return _price; }
	size_t getQuantity() const { return _quantity; }
	bool getSale() { return _onSale; }
	void sellItem( InventoryItem item) {
		_quantity -= 1;
	}
	void addInventory( size_t stock) {
		_quantity += stock;
	}
		void toggleSaleStatus(bool onSale) {
		_onSale = !_onSale;
	}
	friend ostream& operator<<(ostream& stream, const InventoryItem& item) {
		return
	stream<<cout << "item: " << item._sku << " price: " << item._price << " quant: " << item._quantity << "Sale: " << item._onSale;
	}

private:
	string _sku;
	double _price;
	size_t _quantity;
	bool _onSale;
};

	int main() {
		InventoryItem item0 = { "1523041125", 12.00, 14, false };
		InventoryItem item1 = { "aksdjflajf", 15.99, 8, true };
		InventoryItem item2 = { "12kefe1j38", 1.72, 33, false };
		vector<InventoryItem> items = { item0, item1, item2 };
		for (size_t i = 0; i <items.size(); ++i) {
			cout <<items.at(i) << endl;
		}
		// sell some stuff
		items.at(1).sellItem(items.at(1));
		items.at(2).sellItem(items.at(2));
		items.at(2).sellItem(items.at(2));
		items.at(0).sellItem(items.at(0));
		items.at(0).sellItem(items.at(0));
		items.at(2).sellItem(items.at(2));
		items.at(0).sellItem(items.at(0));
		// get new inventory
		items.at(0).addInventory(5);
		items.at(1).addInventory(15);
		items.at(2).addInventory(40);
	

		// have a sale
		size_t markdown = 20;
		for (size_t i = 0; i < items.size(); ++i) {
			if (items.at(i).getQuantity > markdown && !(items.at(i).getSale()))
			 items.at(i).toggleSaleStatus(items.at(i).getSale());
		}
		// print results
		for (size_t i = 0; i <items.size(); ++i) {
			cout << items.at(i) << endl;
		}
	}
