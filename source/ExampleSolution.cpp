#include "IGalaxyPathFinder.h"
#include "CParser.hpp"


#include <iostream>

#include <vector>
#include <iomanip>

#include <map>
#include <cmath>

struct sizes
{
	int half_x;
	int half_y;
	int half_z;
};

struct posicion
{
	float x;
	float y;
	float z;
};

struct box
{
	// int id;

	// coordinates in ship container
	posicion pos;

	sizes boxSize;
	float w;
	int target;
};

struct targetPoint
{
	// int id;
	posicion pos;

	std::map<int, float> distances;
};

struct ship
{
	sizes shipSize;
	float maxFuelWeight;
	float maxCarryingWeight;
	float fuelConsumption;
};

struct NameSurnamePathFinder : public IGalaxyPathFinder
{
private:
	// std::vector<box> boxes;
	// std::vector<targetPoint> targetPoints;
	std::map<int, box> boxes;
	std::map<int, targetPoint> targetPoints;
	ship myship;

public:
	float NameSurnamePathFinder::calculateDistances(targetPoint& v1, targetPoint& v2);
	void insertDistances(std::map<int, targetPoint>& src);

	virtual void FindSolution(const char* inputJasonFile, const char* outputFileName);
	virtual const char* ShowCaptainName() { return "Name Surname"; }
};

void NameSurnamePathFinder::FindSolution(const char* inputJasonFile, const char* outputFileName)
{
	CParser mParser(inputJasonFile);

	mParser.parseJSONInput();

	// do some stuff

	// json j_out;
	// j_out["steps"] = json::array();
	// // do some stuff

	// std::ofstream o(outputFileName);
	// o << std::setw(4) << j_out << std::endl;
}

float NameSurnamePathFinder::calculateDistances(targetPoint& v1, targetPoint& v2)
{
	return sqrt(pow(v2.pos.x - v1.pos.x, 2.0) + pow(v2.pos.y - v1.pos.y, 2.0) + pow(v2.pos.z - v1.pos.z, 2.0));
}

void NameSurnamePathFinder::insertDistances(std::map<int, targetPoint>& src)
{
	for (auto i: src)
	{
		for	(auto j: src)
		{
			// if (i.id != j.id)

			// if (i.first == j.first && j != src.count)
			// 	j++;

			if (i.first != j.first)
			{
				i.second.distances.insert(std::pair<int, float>(j.first, calculateDistances(i.second, j.second)));
			}
			else
			{
				continue;
			}
		}
	}
}


int 	main(int argc, char **argv)
{
	NameSurnamePathFinder mNameSurnamePathFinder;

	mNameSurnamePathFinder.FindSolution("./jsonFiles/inputData1.json", "./test");

	return 0;
}



