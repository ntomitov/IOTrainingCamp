#include <iostream>
#include <math.h>

using namespace std;

const float WINDOW_SIZE = 1.5;
const int DOOR_SIZE = 2;
const int FLOOR_PAINT_PRICE = 15;
const int WALL_PAINT_PRICE = 10;
const int CEIL_PAINT_PRICE = 8;

// Calculates the price of the floor painting
float CalculateFloor(float, float);
// Calculates the price of the walls painting
float CalculateWalls(float, float, float, int, int);
// Calculates the price of the ceiling painting
float CalculateCeil(float, float);
// Prints out the result
void PrintOutResults(float, float, float);

int main() {
	float x, y, z, windows, doors;
	// Read the input
	cin >> x >> y >> z >> windows >> doors;
	float floor, walls, ceiling;
	// Do calc
	floor = CalculateFloor(x, y);
	walls = CalculateWalls(x, y, z, windows, doors);
	ceiling = CalculateCeil(x, y);
	// END do calc
	PrintOutResults(floor, walls, ceiling);
	return 0;
}
// CalculateFloor prototype definition
float CalculateFloor(float x, float y)
{
	return ceil(x * y) * FLOOR_PAINT_PRICE;
}
// CalculateWalls prototype definition
float CalculateWalls(float x, float y, float z, int windows, int doors)
{
	return ceil(2*(x*z + y*z) - windows * WINDOW_SIZE - doors * DOOR_SIZE) * WALL_PAINT_PRICE;
}
// CalculateCeil prototype definition
float CalculateCeil(float x, float y)
{
	return ceil(x * y) * CEIL_PAINT_PRICE;
}

void PrintOutResults(float floor, float walls, float ceiling)
{
	cout << "The floor costs: " << floor << endl;
	cout << "The walls cost: " << walls << endl;
	cout << "The ceiling costs: " << ceiling << endl;
	cout << "Total: " << floor + walls + ceiling << endl;
}
