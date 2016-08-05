#include "Location.h"

class AllLocation7 : public Location
{
public:
	AllLocation7()
	{
		addObject(new ObjShishka);
		addObject(new ObjFrog);	
	}
	virtual std::string getDescription() const
	{

		return "Ух, Вы забрались в самую чащу леса. Вокруг вас деревья, "
			"болотца, кочки и кучи веток.  Вы помните, что тропинка к "
			"фонарю где-то позади вас, то есть на юге.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locLamp; // топаем из леса к фонарю
		return NULL;
	}
};

static AllLocation7 location;

Location *locForest = &location;