#include "Location.h"
#include "Flags.h"


class AllLocation2 : public Location
{
public:
	AllLocation2()
	{
		addObject(new HumanVita);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
			return "Вы вошли в административный корпус лагеря. "
					"За столом сидит Вита Владимировна, заполняет какие-то документы "
					"и, наверное, распределяет обязанности. Выход из корпуса к востоку от Вас.";

		else return "Уже поздно и административный корпус сейчас закрыт. Хотя это может быть и не так, но лучше это не проверять…";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locCrossroad_1; // топаем к развилке
		return NULL;
	}
};

static AllLocation2 location;

Location *locAdministration = &location;