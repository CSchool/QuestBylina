#include "Location.h"

class AllLocation6 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "Вы стоите у кирпичных домиков. "
			"На юге простирается спортивная площадка, "
			"на востоке виднеется учебный корпус, на севере домик «из камней», "
			"на запад от Вас уходит тропинка к развилке у Вашего домика.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locSchool; // топаем в учебный корпус
		if (dir==DirWest)
			return locCrossroad_2; // топаем к развилке 2, которая у домика ГГ
		if (dir==DirNorth)
			return locStone_House;  // входим в домик "из камней"
		if (dir==DirSouth)
			return locCourt; // идет на спортивную площадку
		return NULL;
	}
};

static AllLocation6 location;

Location *locCrossroad_3 = &location;