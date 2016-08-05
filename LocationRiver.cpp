#include "Location.h"
#include "Flags.h"


class AllLocation11 : public Location
{
public:
	AllLocation11()
	{
		addObject(new ObjWater);
	}
	virtual std::string getDescription() const
	{

		return "Перед Вами спуск к речке. Тут легко можно набрать воды, "
			" если она, конечно, Вам нужна… Спортивная площадка находится на севере.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locCourt; // топаем на спортивную площадку
		return NULL;
	}
};

static AllLocation11 location;

Location *locRiver = &location;