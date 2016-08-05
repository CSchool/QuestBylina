#include "Location.h"
#include <iostream>

class AllLocation12 : public Location
{
public:
	AllLocation12()
	{
		addObject(new HumanTeacher);
	}
	
	virtual std::string getDescription() const
	{

		return "Вы стоите в комнате вожатого. "
			"На столе лежат картон, краски, кисточки, ножницы, "
			"скотч, карандаши, фломастеры и прочее барахло. "
			"Кровать застелена, всё чисто…  У детей так не бывает… =)"
			"  За вашей спиной, на востоке, находится дверь из комнаты.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast)
			return locHome; // выход из вожатской
		return NULL;
	}
};

static AllLocation12 location;

Location *locRoom = &location;