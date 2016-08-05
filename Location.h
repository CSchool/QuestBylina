#ifndef LOCATION_H 
#define LOCATION_H

#include <string>
#include "Object.h"
enum Direction
{
	DirUnknown,
	DirNorth,
	DirSouth,
	DirEast,
	DirWest
};

class Location : public ObjectsContainer
{
public:
	virtual std::string getDescription() const = 0;
	virtual Location *getDirection(Direction dir) const = 0;
	void printDescription() const ;
};

extern Location *locAdministration;
extern Location *locCourt;
extern Location *locCrossroad_1;
extern Location *locCrossroad_2;
extern Location *locCrossroad_3;
extern Location *locForest;
extern Location *locHome;
extern Location *locKitchen;
extern Location *locLamp;
extern Location *locRiver;
extern Location *locRoom;
extern Location *locSchool;
extern Location *locStone_House;
extern Location *locVerandah;

#endif