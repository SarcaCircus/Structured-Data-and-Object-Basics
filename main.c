#include <stdlib.h>
void insert(const int* from, int* to, int value, size_t location, size_t toLength) {
	int fromIndex = 0;
	for (int toIndex = 0; toIndex < toLength; ++toIndex) {
		if (toIndex != location) {
			to[toIndex] = from[fromIndex];
			++fromIndex; }
		else {
			to[toIndex] = value;
		}
	}
}
void remove(const int* from, int* to, size_t location, size_t fromLength) {
	int blank = 0;
	for (int remove = 0; remove < fromLength; ++remove) {
		
		if (remove == location) {
			insert(from, to, from[remove], (size_t)remove, sizeof(to));
			insert(to, from, blank, from[remove], fromLength);
			
		}
	}
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int arr2[6];
	insert(arr, arr2, 15, 5, 6);
	int arr3[5];
	remove(arr2, arr3, 3, 6);
}

