#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

int main() {
	int multi_dim[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			multi_dim[i][j] = 100;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cout << multi_dim[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
}