#include "IGalaxyPathFinder.h"
#include "CParser.hpp"
#include "CShip.hpp"


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
	int boxId;

	// coordinates in ship container
	posicion pos;

	sizes boxSize;
	float weight;
	int targetPointId;
};

struct targetPoint
{
	// int id;
	posicion pos;
	float load;
	std::map<int, float> distances;
};

struct NameSurnamePathFinder : public IGalaxyPathFinder
{
private:
	// std::vector<box> boxes;
	// std::vector<targetPoint> targetPoints;
	std::map<int, box> boxes;
	std::map<int, targetPoint> targetPoints;
	// ship myship;

public:
	float calculateDistances(targetPoint& v1, targetPoint& v2);
	void insertDistances(std::map<int, targetPoint>& src);

	virtual void FindSolution(const char* inputJasonFile, const char* outputFileName);
	virtual const char* ShowCaptainName() { return "Name Surname"; }
	void setBoxes (int id, box& box1);
};

void NameSurnamePathFinder::setBoxes(int id, box& box1)
{
	boxes.insert(std::pair<int, box>(id, box1));
}

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

box&  InitBoxes(int id)
{
	box mBox;
	
	if (id == 195)
	{
		mBox.boxSize.half_x = 32;
		mBox.boxSize.half_y = 43;
		mBox.boxSize.half_z = 11;
		mBox.weight = 24.549999237060547;
		mBox.targetPointId = 195;
		mBox.boxId = 596;
	}
	else if (id == 19545646464)
	{
		mBox.boxSize.half_x = 26;
		mBox.boxSize.half_y = 30;
		mBox.boxSize.half_z = 16;
		mBox.weight = 47.130001068115234;
		mBox.targetPointId = 195;
		mBox.boxId = 985;
	}
	else if (id == 782)
	{
		mBox.boxSize.half_x = 23;
		mBox.boxSize.half_y = 32;
		mBox.boxSize.half_z = 25;
		mBox.weight = 29.100000381469727;
		mBox.targetPointId = 782;
		mBox.boxId = 10;
	}
	else if (id == 551)
	{
		mBox.boxSize.half_x = 50;
		mBox.boxSize.half_y = 37;
		mBox.boxSize.half_z = 24;
		mBox.weight = 34.470001220703125;
		mBox.targetPointId = 551;
		mBox.boxId = 517;
	}
	else if (id == 542)
	{
		mBox.boxSize.half_x = 37;
		mBox.boxSize.half_y = 9;
		mBox.boxSize.half_z = 36;
		mBox.weight = 32.979999542236328;
		mBox.targetPointId = 542;
		mBox.boxId = 221;
	}
	else if (id == 870)
	{
		mBox.boxSize.half_x = 5;
		mBox.boxSize.half_y = 16;
		mBox.boxSize.half_z = 45;
		mBox.weight = 12.060000419616699;
		mBox.targetPointId = 870;
		mBox.boxId = 728;
	}

	return mBox;
}

int 	main(int argc, char **argv)
{
	// parser
	NameSurnamePathFinder mNameSurnamePathFinder;
	CShip mShip;

	mNameSurnamePathFinder.setBoxes(596, InitBoxes(596));
	mNameSurnamePathFinder.setBoxes(782, InitBoxes(782));
	mNameSurnamePathFinder.setBoxes(551, InitBoxes(551));
	mNameSurnamePathFinder.setBoxes(542, InitBoxes(542));
	mNameSurnamePathFinder.setBoxes(870, InitBoxes(870));

	// mNameSurnamePathFinder.FindSolution("./jsonFiles/inputData1.json", "./test");



	return 0;
}



