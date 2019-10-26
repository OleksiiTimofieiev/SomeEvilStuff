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
	int pointId;
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
	void calculateMaxLoad();
	void setTargetPoint (int id, targetPoint& currentTargetPoints);
};

void NameSurnamePathFinder::setBoxes(int id, box& box1)
{
	boxes.insert(std::pair<int, box>(id, box1));
}

void NameSurnamePathFinder::setTargetPoint(int id, targetPoint& currentTargetPoints)
{
	targetPoints.insert(std::pair<int, targetPoint>(id, currentTargetPoints));
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

void NameSurnamePathFinder::calculateMaxLoad()
{
	for (auto j: boxes)
	{
		targetPoints.find(j.second.targetPointId)->second.load += j.second.weight;
	}
}

box&  InitBoxes(int id, int tmp)
{
	box mBox;
	
	if (id == 195 && tmp == 0)
	{
		mBox.boxSize.half_x = 32;
		mBox.boxSize.half_y = 43;
		mBox.boxSize.half_z = 11;
		mBox.weight = 24.549999237060547;
		mBox.boxId = 596;
	}
	else if (id == 195 && tmp == 1)
	{
		mBox.boxSize.half_x = 26;
		mBox.boxSize.half_y = 30;
		mBox.boxSize.half_z = 16;
		mBox.weight = 47.130001068115234;
		mBox.boxId = 985;
	}
	else if (id == 782 && tmp == 0)
	{
		mBox.boxSize.half_x = 23;
		mBox.boxSize.half_y = 32;
		mBox.boxSize.half_z = 25;
		mBox.weight = 29.100000381469727;
		mBox.boxId = 10;
	}
	else if (id == 782 && tmp == 1)
	{
		mBox.boxSize.half_x = 34;
		mBox.boxSize.half_y = 50;
		mBox.boxSize.half_z = 33;
		mBox.weight = 27.510000228881836;
		mBox.boxId = 189;
	}
	else if (id == 551 && tmp == 0)
	{
		mBox.boxSize.half_x = 50;
		mBox.boxSize.half_y = 37;
		mBox.boxSize.half_z = 24;
		mBox.weight = 34.470001220703125;
		mBox.boxId = 517;
	}
	else if (id == 551 && tmp == 1)
	{
		mBox.boxSize.half_x = 33;
		mBox.boxSize.half_y = 1;
		mBox.boxSize.half_z = 25;
		mBox.weight = 44.139999389648438;
		mBox.boxId = 388;
	}
	else if (id == 542)
	{
		mBox.boxSize.half_x = 37;
		mBox.boxSize.half_y = 9;
		mBox.boxSize.half_z = 36;
		mBox.weight = 32.979999542236328;
		mBox.boxId = 221;
	}
	else if (id == 870)
	{
		mBox.boxSize.half_x = 5;
		mBox.boxSize.half_y = 16;
		mBox.boxSize.half_z = 45;
		mBox.weight = 12.060000419616699;
		mBox.boxId = id;
	}

	mBox.targetPointId = id;
	return mBox;
}

targetPoint&  InitTargetPoints(int id)
{
	targetPoint mTargetPoint;
	
	if (id == 195)
	{
		mTargetPoint.pos.x = 70;
		mTargetPoint.pos.x = -72;
		mTargetPoint.pos.x = 85;
	}
	else if (id == 782)
	{
		mTargetPoint.pos.x = -99;
		mTargetPoint.pos.x = 78;
		mTargetPoint.pos.x = -88;
	}
	else if (id == 551)
	{
		mTargetPoint.pos.x = 83;
		mTargetPoint.pos.x = -37;
		mTargetPoint.pos.x = 99;
	}
	else if (id == 0)
	{
		mTargetPoint.pos.x = 80;
		mTargetPoint.pos.x = -30;
		mTargetPoint.pos.x = 0;
	}

	mTargetPoint.pointId = id;
	return mTargetPoint;
}

int 	main(int argc, char **argv)
{
	// parser
	NameSurnamePathFinder mNameSurnamePathFinder;
	CShip mShip;

	// set targetPoints
	mNameSurnamePathFinder.setTargetPoint(0, InitTargetPoints(0));
	mNameSurnamePathFinder.setTargetPoint(195, InitTargetPoints(195));
	mNameSurnamePathFinder.setTargetPoint(782, InitTargetPoints(782));
	mNameSurnamePathFinder.setTargetPoint(551, InitTargetPoints(551));

	// set box
	mNameSurnamePathFinder.setBoxes(195, InitBoxes(195, 0));
	mNameSurnamePathFinder.setBoxes(195, InitBoxes(195, 1));
	mNameSurnamePathFinder.setBoxes(782, InitBoxes(782, 0));
	mNameSurnamePathFinder.setBoxes(782, InitBoxes(782, 1));
	mNameSurnamePathFinder.setBoxes(551, InitBoxes(551, 0));
	// mNameSurnamePathFinder.setBoxes(542, InitBoxes(542));
	// mNameSurnamePathFinder.setBoxes(870, InitBoxes(870));
	// mNameSurnamePathFinder.FindSolution("./jsonFiles/inputData1.json", "./test");

	return 0;
}



