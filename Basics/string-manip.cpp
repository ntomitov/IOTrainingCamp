#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "Hello World!";
	cout << s[0] << endl;
	cout << "Length: " << s.length() << endl;
	cout << "l appears first at: " << s.find_first_of('l') << " and last at" << s.find_last_of('l') << endl;

	cout << s.substr(s.find("World"), 5) << endl;
	cout << s.substr(0, 6) << endl;
	system("pause");
}