#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const char full = 'X', empty = 'O';
	const int floor = 8;
	const int room = 10;
	char map [room][floor];
	
	for (int i = 0; i < floor + 1; i++)
	{
		for (int j = 0; j < room; j++)
			map [i][j] = empty;
	}

	cout << endl << "  O = VACANT   X = TAKEN" << endl << endl;
	cout << "    A   B   C   D   E   F   G   H   I   J";
	for (int i = 1; i < floor + 1; i++)
	{
		cout << endl << endl << i;
		for (int j = 0; j < room; j++)
			cout << setw(3) << " " << map [i][j];
	}
}
