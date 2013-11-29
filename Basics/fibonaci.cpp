#include <iostream>

using namespace std;

const int MAX_SIZE = 200;

int fib(int);
int fibIterative(int);

int main() {
	cout << fibIterative(100) << endl;
	system("pause");
}

int fib(int n) {
	if (n < 3) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int fibIterative(int n) {
	if (n < 2) {
		return 1;
	}
	int list[MAX_SIZE], i = 2;
	list[0] = 1;
	list[1] = 1;
	while (i < n) {
		list[i] = list[i - 1] + list[i - 2];
		i++;
	}
	return list[i - 1];
}