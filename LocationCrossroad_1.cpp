#include "Location.h"

class AllLocation4 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "Вы стоите на детской площадке. "
			"На западе Вы видите административный корпус, "
			"на севере – столовую. На восток уходит  тропинка к Вашему домику.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locLamp; // топаем к фонарю
		if (dir==DirWest)
			return locAdministration; // топаем в адинистрацию
		if (dir==DirNorth)
			return locKitchen; // топаем на кухню
		return NULL;
	}
};

static AllLocation4 location;

Location *locCrossroad_1 = &location;