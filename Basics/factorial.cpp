#include <iostream>
#include <cassert>

using namespace std;

int fact(int);

int main() {
	cout << fact(10) << endl;
	system("pause");
	return 0;
}

int fact(int x) {
	assert(x >= 0);
	if (x == 0) {
		return 1;
	}
	return x * fact(x - 1);
}