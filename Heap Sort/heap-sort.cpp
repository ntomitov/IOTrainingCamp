#include <iostream>
#include "heap.h"

using namespace std;

void main(void) {
	Heap<int> heap = Heap<int>();

	int new_array [15];
	new_array[0] = 6;
	new_array[1] = 5;
	new_array[2] = 3;
	new_array[3] = 1;
	new_array[4] = 8;
	new_array[5] = 7;
	new_array[6] = 3;
	new_array[7] = 4;
	new_array[8] = 10;
	new_array[9] = 0;
	new_array[10] = -5;
	new_array[11] = -11;
	new_array[12] = 9;
	new_array[13] = -1;
	new_array[14] = 100;
	for (int i = 0; i < 15; i++) {
		heap.Insert(new_array[i]);
	}
	int sorted [15], index = 0;
	while (!heap.IsEmpty()) {
		sorted[index++] = heap.DeleteByIndex(0);
	}
}