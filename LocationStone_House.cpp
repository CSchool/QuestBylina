#include "Location.h"
#include "Flags.h"


class AllLocation14 : public Location
{
public:
	AllLocation14()
	{
		addObject(new ObjPeople);
		addObject(new ObjBrush);
		addObject(new ObjWC);
		addObject(new ObjDoor);
		addObject(new ObjCorridor);
		addObject(new ObjTap);
		addObject(new ObjBed);
	}
	virtual std::string getDescription() const
	{

		if (getStateFlag(FlagNight) == FVNightNo)
			return "Вы находитесь в кирпичном домике ваших потенциальных жертв. "
					"Осмотритесь – здесь много мест, где можно сделать ловушки… Надо только "
					"собрать все вещи и прийти сюда ночью… А пока что здесь делать нечего. Выход из домика к югу от Вас";

		else return "Вы находитесь в кирпичном домике ваших потенциальных жертв. Осмотритесь – здесь много мест, где "
					"можно сделать ловушки… Наконец-то их можно расставить. Здесь Вы видите: спящих детей, "
					"стакан с зубными щётками, туалет, пол в коридор, ручку двери, краны горячей и холодной воды,  много кроватей.\n";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locCrossroad_3; // топаем к развилке 3
		return NULL;
	}
};

static AllLocation14 location;

Location *locStone_House = &location;