#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 20;

int main() {
	// Input file stream used for reading from a file
	ifstream infile;
	infile.open("list.txt");
	string values[SIZE];
	int size = 0;

	while (!infile.eof()) {
		infile >> values[size++];
	}

	infile.close();

	// Output file steam used for writing to a file
	ofstream outfile;
	outfile.open("results.txt");
	int i = 0;
	while (i < SIZE) {
		outfile << values[i++] << endl;
	}

	int my_array[20];
	for (int i = 0; i < 20; i++) {
		cout << my_array[i] << endl;
	}

	outfile.close();

	system("pause");
	return 0;
}