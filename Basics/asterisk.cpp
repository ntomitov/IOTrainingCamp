#include <iostream>

using namespace std;

void PrintAsterisk(int, int k = 0);

int main() {
	PrintAsterisk(8);
	system("pause");
}

void PrintAsterisk(int n, int k) {
	if (n == k) {
		return;
	}
	for (int i = 0; i < k - 1; i++) {
		cout << "* ";
	}
	cout << endl;
	PrintAsterisk(n, k + 1);
	for (int i = 0; i < k; i++) {
		cout << "* ";
	}
	cout << endl;
}