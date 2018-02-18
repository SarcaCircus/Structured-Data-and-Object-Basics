#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define LENGTH 7

typedef struct {
	int id;
	double price;
	char* color;

} Item;

Item* initItem(int _id, double _price, const char* _color) {
	Item* item = malloc(sizeof(Item));
	item->id = _id;
	item->price = _price;
	item->color = _color;

}

void printItems(Item* items[], size_t size) {
	for (int i = 0; i < size; ++i) {
		printItem(items[i]);
		printf("\n");
	}
}

	int compareIdLowHigh(const void* a, const void* b) {
		const Item** pfirst = a;
		const Item** psecond = b;
		const Item* first = *pfirst;
		const Item* second = *psecond;
		
		if (first->id < second->id) return-1;
		else if (second->id < first->id) return 1;
		else return 0;
	}

	int comparePriceHighLow(const void* a, const void* b) {
		const Item** pfirst = a;
		const Item** psecond = b;
		const Item* first = pfirst;
		const Item* second = psecond;
		if (first->price > second->price) return 1;
		else if (second->price > first->price) return -1;
		else return 0;
	}

	int compareColorAlpha(const void* a, const void* b) {
		const Item** pfirst = a;
		const Item** psecond = b;
		const Item* first = pfirst;
		const Item* second = psecond;

		if (first->color > second->color) return 1;
		else if (first->color < second->color) return -1;
		else return 0;
	}
	int main() {
		//initialize items
		const size_t COUNT = LENGTH;
		Item* itemPtrs[LENGTH];
		itemPtrs[0] = initItem(0, 12.12, "red");
		itemPtrs[1] = initItem(11, 14.14, "blue");
		itemPtrs[2] = initItem(32, 1.67, "black");
		itemPtrs[3] = initItem(13, 5.54, "brown");
		itemPtrs[4] = initItem(54, 17.20, "purple");
		itemPtrs[5] = initItem(15, 20.24, "yellow");
		itemPtrs[6] = initItem(6, 99.99, "orange");
		printItems(itemPtrs, COUNT);

		// sorting items
		printItems(itemPtrs, COUNT);

		printf("sorting items by color (a-z):\n");
		
		int time = COUNT;
		for (int j = 0; j < time; ++j) {
			Item* temp;
			for (int i = j+1; i < time; i++) {
				if (compareColorAlpha(itemPtrs[i], itemPtrs[i - 1])==1) {
					temp = itemPtrs[i];

				}
				else if (compareColorAlpha(itemPtrs[i], itemPtrs[i - 1])==-1) {
					temp = itemPtrs[i - 1];
				}
			}
			itemPtrs[j] = temp;
		}
		printItems(itemPtrs, COUNT);

		//cleanup items
		for (int i = 0; i < 7; ++i) {
			free(itemPtrs[i]);
		}
	}

