#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

void ReadFile(ifstream&, int, int, int[][MAX_SIZE]);

int CalculateSum(int, int, int[][MAX_SIZE], int[][2]);

void Swap(int[][2]);

int main() {
	int x, y;
	ifstream infile;
	infile.open("matrix.txt");
	infile >> x >> y;
	int matrix[MAX_SIZE][MAX_SIZE], sequence[2][2];
	ReadFile(infile, x, y, matrix);

	cout << "Input the sequence you want the sum of: ";
	cin >> sequence[0][0] >> sequence[0][1] >> sequence[1][0] >> sequence[1][1];

	cout << CalculateSum(x, y, matrix, sequence) << endl;
	system("pause");
}

void ReadFile(ifstream& infile, int x, int y, int matrix[][MAX_SIZE]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			infile >> matrix[i][j];
		}
	}
	infile.close();
}

int CalculateSum(int x, int y, int matrix[][MAX_SIZE], int sequence[][2]) {
	if (sequence[0][0] > sequence[1][0] || 
		(sequence[0][0] == sequence[1][0] && sequence[0][1] > sequence[1][1])) {
		Swap(sequence);
	}
	int sum = 0, j = sequence[0][1];
	for (int i = sequence[0][0]; i <= sequence[1][0]; i++) {
		if (i == sequence[1][0]) {
			y = sequence[1][1] + 1;
		}
		for (j; j < y; j++) {
			sum += matrix[i][j];
		}
		j = 0;
	}
	return sum;
}

void Swap(int sequence[][2]) {
	int temp;
	temp = sequence[0][0];
	sequence[0][0] = sequence[1][0];
	sequence[1][0] = temp;
	temp = sequence[0][1];
	sequence[0][1] = sequence[1][1];
	sequence[1][1] = temp;
}