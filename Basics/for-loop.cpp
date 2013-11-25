#include <iostream>

using namespace std;

int main() {
	for (int x = 0; x <= 20; x++)
	{
		cout << x << ": " << (x % 2 == 0 ? "even" : "odd") << endl;
	}
	return 0;
}
