#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
	maze maz;
	if (maz.input(10, 4, 4, "maze.txt")) { cout << maz.decid(0, 0, 0, 3, 9, 4) << endl; maz.print(); }
	return 0;
}
