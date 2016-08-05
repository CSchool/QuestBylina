#include "Location.h"
#include "Object.h"
#include "Flags.h"


class AllLocation9 : public Location
{
public:
	AllLocation9()
	{
		addObject(new HumanCook);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
			return "Вы стоите в столовой. На кухне виднеются повара, "
					"готовящие ужин. Опять, наверное, каша «Дружба» будет. Сергею понравится… За вашей спиной, на юге, находится выход";

		else return "Уже поздно и столовая сейчас закрыта. Хотя это может быть и не так, но лучше это не проверять…";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locCrossroad_1; // топаем к развилке
		return NULL;
	}
};

static AllLocation9 location;

Location *locKitchen = &location;