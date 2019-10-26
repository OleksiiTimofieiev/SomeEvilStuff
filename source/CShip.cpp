#include "CShip.hpp"

CShip::CShip() {}
CShip::~CShip() {}

struct sizes
{
	int half_x;
	int half_y;
	int half_z;
};

struct property
{
	sizes shipSize;
    float maxResourcesWeight;
    float maxCarryingWeight;
    float resourcesConsumption;
	// float maxFuelWeight;
	// float maxCarryingWeight;
	// float fuelConsumption;
};

void    CShip(void)
{
    property mProperty;
    
    mProperty.shipSize.half_x = 607;
    mProperty.shipSize.half_y = 261;
    mProperty.shipSize.half_z = 248;
    mProperty.maxResourcesWeight = 175.75;
    mProperty.maxCarryingWeight = 388.6400146484375;
    mProperty.maxCarryingWeight = 0.17000000178813934;
}

void    CShip::ShipCreate(void)
{

}

// seter geter struct property