#include "Location.h"

class AllLocation3 : public Location
{
public:
	AllLocation3()
	{
		addObject(new ObjBall);
		addObject(new ObjBasket);
	}
	virtual std::string getDescription() const
	{

		return "Вы вышли на спортивную площадку. Перед вами баскетбольные кольца, "
			"теннисный стол. На юг ведёт тропинка к речке, на север – дорожка к домикам.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth)
			return locRiver; // топаем к берегу речки
		if (dir==DirNorth)
			return locCrossroad_3; // топаем к развилочке 3, у кирпичных домиков
		return NULL;
	}
};

static AllLocation3 location;

Location *locCourt = &location;