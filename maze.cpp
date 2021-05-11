#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

int maze::searchMax()
{
	int result = 0;
	for (int h = 1; h < width - 1; h++)
	{
		for (int i = 1; i < heigth - 1; i++)
		{
			for (int j = 1; j < length - 1; j++)
			{
				if (field[h][i][j] > result) { result = field[h][i][j]; }
			}
		}
	}
	return result;
}

void maze::decidRec(int xEnd, int yEnd, int zEnd, int step, std::vector <coordinate> points)
{
	std::vector <coordinate> newPoints;
	for (auto it : points)
	{
		field[it.z + 1][it.x + 1][it.y + 1] = step;
		if (it.x == xEnd && it.y == yEnd && it.z == zEnd) { continue; }
		if (field[it.z + 1][it.x][it.y + 1] != -1 && (field[it.z + 1][it.x][it.y + 1] > step || field[it.z + 1][it.x][it.y + 1] == 0))
		{
			field[it.z + 1][it.x][it.y + 1] = step;
			newPoints.push_back(coordinate(it.x - 1, it.y, it.z));
		}
		if (field[it.z + 1][it.x + 2][it.y + 1] != -1 && (field[it.z + 1][it.x + 2][it.y + 1] > step || field[it.z + 1][it.x + 2][it.y + 1] == 0))
		{
			field[it.z + 1][it.x + 2][it.y + 1] = step;
			newPoints.push_back(coordinate(it.x + 1, it.y, it.z));
		}
		if (field[it.z + 1][it.x + 1][it.y] != -1 && (field[it.z + 1][it.x + 1][it.y] > step || field[it.z + 1][it.x + 1][it.y] == 0))
		{
			field[it.z + 1][it.x + 1][it.y] = step;
			newPoints.push_back(coordinate(it.x, it.y - 1, it.z));
		}
		if (field[it.z + 1][it.x + 1][it.y + 2] != -1 && (field[it.z + 1][it.x + 1][it.y + 2] > step || field[it.z + 1][it.x + 1][it.y + 2] == 0))
		{
			field[it.z + 1][it.x + 1][it.y + 2] = step;
			newPoints.push_back(coordinate(it.x, it.y + 1, it.z));
		}
		if (field[it.z + 2][it.x + 1][it.y + 1] != -1 && (field[it.z + 2][it.x + 1][it.y + 1] > step || field[it.z + 2][it.x + 1][it.y + 1] == 0))
		{
			field[it.z + 2][it.x + 1][it.y + 1] = step;
			newPoints.push_back(coordinate(it.x, it.y, it.z + 1));
		}
		if (field[it.z][it.x + 1][it.y + 1] != -1 && (field[it.z][it.x + 1][it.y + 1] > step || field[it.z][it.x + 1][it.y + 1] == 0))
		{
			field[it.z][it.x + 1][it.y + 1] = step;
			newPoints.push_back(coordinate(it.x, it.y, it.z - 1));
		}
	}
	if (newPoints.size() != 0) { decidRec(xEnd, yEnd, zEnd, step + 1, newPoints); }
	return;
}

int maze::decid(int xStart, int yStart, int zStart, int xEnd, int yEnd, int zEnd)
{
	std::vector <maze::coordinate> initialP;
	initialP.push_back(maze::coordinate(xStart, yStart, zStart));
	decidRec(xEnd, yEnd, zEnd, 1, initialP);
	return field[zEnd][xEnd][yEnd];
}

bool maze::input(int length, int heigth, int width, std::string fileName)
{
	this->length = length + 2;
	this->heigth = heigth + 2;
	this->width = width + 2;
	field.resize(this->width);
	for (int i = 0; i < this->width; i++)
	{
		field[i].resize(this->heigth);
		for (int j = 0; j < this->heigth; j++)
		{
			field[i][j].resize(this->length, -1);
		}
	}
	std::ifstream fileInput;
	fileInput.open(fileName);
	if (!fileInput.is_open()) { return false; }
	for (int h = 1; h < width + 1; h++)
	{
		for (int i = 1; i < heigth + 1; i++)
		{
			for (int j = 1; j < length + 1; j++)
			{
				fileInput >> field[h][i][j];
			}
		}
	}
	return true;
}

void maze::print()
{
	int max = searchMax(), value = 0;
	while (value != max)
	{
		system("cls");
		value++;
		for (int h = 1; h < width - 1; h++)
		{
			for (int i = 0; i < heigth; i++)
			{
				for (int j = 0; j < length; j++)
				{
					if (field[h][i][j] == value) { std::cout << " + "; }
					else if (field[h][i][j] == -1) { std::cout << "###"; }
					else { std::cout << "   "; }
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		Sleep(700);
	}
	return;
}