#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Hello world" << endl;
	
	int x;
	cout << "Input a number between 1 and 5: ";
	cin >> x;
	switch (x) {
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		default:
			cout << "Couldn't recognize the number";
			break;
		
	}
	if (x == 1) {
		cout << "one";
	} else if (x == 2) {
		cout << "two";
	} else if (x == 3) {
		cout << "three";
	} else {
		cout << "Couldn't recognize the number";
	}
	return 0;
}
