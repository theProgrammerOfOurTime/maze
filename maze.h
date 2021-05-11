#pragma once
#include <string>
#include <vector>

class maze
{
private:
	struct coordinate
	{
		int x, y, z;
		coordinate() : x(0), y(0), z(0) { }
		coordinate(int x, int y, int z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};
	std::vector<std::vector<std::vector<int>>> field;
	int length, heigth, width;// length - x, heigth - y, width - z
	int searchMax();
	void decidRec(int, int, int, int, std::vector <coordinate>);
public:
	maze() : length(0), heigth(0), width(0) { }
	bool input(int, int, int, std::string);
	void print();
	int decid(int, int, int, int, int, int);
};