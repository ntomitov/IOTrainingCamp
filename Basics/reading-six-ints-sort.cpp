#include <iostream>

using namespace std;

bool sortPass(int&, int&, int&, int&, int&, int&);

int main() {
	int x, y, z, a, b, c;
	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:
			cin >> x;
			break;
		case 1:
			cin >> y;
			break;
		case 2:
			cin >> z;
			break;
		case 3:
			cin >> a;
			break;
		case 4:
			cin >> b;
			break;
		case 5:
			cin >> c;
			break;
		default:
			break;
		}
	}
	bool result = true;
	while (result) {
		result = sortPass(x, y, z, a, b, c);
	}
	cout << x << ' ' << y << ' ' << z << ' ' << a << ' ' << b << ' ' << c << endl;
	system("pause");
	return 0;
}

bool sortPass(int &x, int &y, int &z, int &a, int &b, int &c) {
	int temp;
	bool changed = false;
	if (x > y) {
		temp = y;
		y = x;
		x = temp;
		changed = true;
	}
	if (y > z) {
		temp = z;
		z = y;
		y = temp;
		changed = true;
	}
	if (z > a) {
		temp = a;
		a = z;
		z = temp;
		changed = true;
	}
	if (a > b) {
		temp = b;
		b = a;
		a = temp;
		changed = true;
	}
	if (b > c) {
		temp = c;
		c = b;
		b = temp;
		changed = true;
	}
	return changed;
}