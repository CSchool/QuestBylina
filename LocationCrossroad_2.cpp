#include "Location.h"

class AllLocation5 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "Вы стоите у домика Вашего отряда. К югу от Вас, собственно, домик. Мимо домика проходит тропинка, ведущая к столовой на западе или к кирпичным домикам на востоке";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locCrossroad_3; // переход на развилку три, у кирпичных домиков.
		if (dir==DirWest)
			return locLamp; // топаем к фонярю по тропиночке
		if (dir==DirSouth)
			return locHome; // ход на веранду
		return NULL;
	}
};

static AllLocation5 location;

Location *locCrossroad_2 = &location;