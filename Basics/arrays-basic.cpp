#include <iostream>

using namespace std;

int main() {
	int my_array[20], sum = 0;
	for (int i = 0; i < 20; i++) {
		my_array[i] = i;
	}
	for (int i = 0; i < 20; i++) {
		sum += my_array[i];
	}
	system("pause");
	return 0;
}