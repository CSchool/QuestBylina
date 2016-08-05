#include "Location.h"
#include "Flags.h"
#include <iostream>

class AllLocation10 : public Location
{
public:
	AllLocation10()
	{
		addObject(new HumanDA) ;
	}
	virtual std::string getDescription() const
	{

		return "Вы остановились у скамейки под светом фонаря, рядом с тропинкой.  "
			"На север ведёт  тропинка в лес, на запад – к столовой"
			" и административному корпусу, на восток – к домику Вашего отряда.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth)
			if (getStateFlag(FlagDA) == FVDABefore)
			{
				std::cout << "(Дмитрий Александрович) Тут Вам, не шуры-муры! Ну-ка брысь отсюдова!\n" ;
				return NULL;
			} 
			else return locForest; // Топаем в лес, надо добавить условие появления тропинки
		if (dir==DirWest)
			return locCrossroad_1; // топаем к столовой на развилку 1.
		if (dir==DirEast)
			return locCrossroad_2; // идём на развилку 2.
		return NULL;
	}
};

static AllLocation10 location;

Location *locLamp = &location;