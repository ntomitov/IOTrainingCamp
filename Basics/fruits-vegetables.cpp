#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 20;

// Reads a files of strings and saves it into
// a string buffer
void ReadFile(ifstream &, string[]);

// Compares the values and outputs the results
void CompareAndOutput(ofstream &, string[], string[], string[]);

void main(void) {
	ifstream infile;
	string fruits[MAX_SIZE], vegetables[MAX_SIZE], list[MAX_SIZE];

	infile.open("fruits.txt");
	ReadFile(infile, fruits);
	infile.open("vegetables.txt");
	ReadFile(infile, vegetables);
	infile.open("list.txt");
	ReadFile(infile, list);
	ofstream outfile;
	outfile.open("results.txt");
	CompareAndOutput(outfile, list, fruits, vegetables);
}

void ReadFile(ifstream & infile, string buffer[]) {
	int size = 0;
	while (!infile.eof() && size < MAX_SIZE) {
		infile >> buffer[size++];
	}
	infile.close();
}

void CompareAndOutput(ofstream & outfile, string list[], string fruits[], string vegetables[]) {
	bool found;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i] == "") {
			break;
		}
		found = false;
		for (int j = 0; j < MAX_SIZE; j++) {
			if (fruits[j] != "") {
				if (list[i] == fruits[j]) {
					outfile << list[i] << ": fruit" << endl;
					found = true;
					break;
				}
			}
		}
		for (int j = 0; j < MAX_SIZE && !found; j++) {
			if (vegetables[j] != "") {
				if (list[i] == vegetables[j]) {
					outfile << list[i] << ": vegetable" << endl;
					found = true;
					break;
				}
			}
		}
		if (!found) {
			outfile << list[i] << ": unknown" << endl;
		}
	}
}