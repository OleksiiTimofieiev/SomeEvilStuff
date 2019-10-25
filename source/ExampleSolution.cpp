#include "IGalaxyPathFinder.h"
#include "CParser.hpp"


#include <iostream>

#include <vector>
#include <iomanip>

struct box
{
	int id;
	int x, y, z;
	float w;
	int target;
};

struct targetPoint
{
	int id;
	float x, y, z;
};

struct ship
{
	float maxFuelWeight;
	float maxCarryingWeight;
};


class NameSurnamePathFinder : public IGalaxyPathFinder
{
private:
	std::vector<box> boxes;
	std::vector<targetPoint> targetPoints;
	ship myship;

public:
	virtual void FindSolution(const char* inputJasonFile, const char* outputFileName);
	virtual const char* ShowCaptainName() { return "Name Surname"; }
};

void NameSurnamePathFinder::FindSolution(const char* inputJasonFile, const char* outputFileName)
{
// 	std::ifstream i(inputJasonFile);
	CParser mParser(inputJasonFile);

	mParser.parseJSONInput();


	
// 	json j = json::parse(i, nullptr, false);

// for (auto& el : j.items()) 
// {
// 	if (el.key() == "boxes")
// 	{
// 		// std::cout << el.key() << " : " << el.value() << "\n";
// 		// std::cout << el["maxCarryingCapacity"];

// 		auto test = el.value();

// 		auto test1 = test[0];

// 		// auto test1 = test["maxCarryingCapacity"];
		
// 		// std::cout << test1["half_x"];

// 		std::cout << test1;

// 	}
  
// }

// if (j.find("foo") != j.end()) 
// {
//   // there is an entry with key "foo"
//    std::cout << j.key() << " : " << j.value() << "\n";
// }

	// do some stuff

	// json j_out;
	// j_out["steps"] = json::array();
	// // do some stuff

	// std::ofstream o(outputFileName);
	// o << std::setw(4) << j_out << std::endl;
}

int 	main(int argc, char **argv)
{
	NameSurnamePathFinder mParserTest;

	mParserTest.FindSolution("./jsonFiles/inputData1.json", "./test");
	std::cout << argv[1] << std::endl;


	

	return 0;
}



