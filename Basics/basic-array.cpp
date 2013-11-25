#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int x[20];
	for (int i = 0; i < 20; i++) {
		x[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < 20; i++) {
		sum += x[i];
	}
	cout << "Sum is: " << sum << endl;

	string fruits [20];
	ifstream infile;
	infile.open("list.txt");
	ofstream outfile;
	int i = 0;

	while (!infile.eof()) {
		if (i == 20) {
			break;
		}
		infile >> fruits[i++];
	}

	infile.close();

	for (int i = 0; i < 20; i++) {
		if (fruits[i] == "") {
			break;
		}
		cout << fruits[i] << endl;
	}

	system("pause");
}