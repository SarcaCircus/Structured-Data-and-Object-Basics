#include <stdio.h>
void reverse(int* values, size_t size) {
	
	int begin = 0;
	int end = size-1;
	while (begin <= end) {
		int temp =  values[begin];
		values[begin] = values[end];
		values[end] = temp;
		begin++;
		end--;
	}
}
	int main() {
		const int SIZE = 10;
		int values[] = { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 };
		for (int i = 0; i < SIZE; ++i) {
			printf("Value: %d\t", values[i]); 
		}
		printf("\n");
		reverse(values, SIZE);
		for (int i = 0; i < SIZE; ++i) { 
			printf("Reversed: %d\t", values[i]); 
		}    
		printf("\n");
	}
