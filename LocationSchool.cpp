#include "Location.h"
#include "Flags.h"

class AllLocation13 : public Location
{
public:
	AllLocation13()
	{
		addObject(new HumanSerega);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
		{
			if (getStateFlag(FlagSerega) == FVSeregaAccept)
				return "Вы зашли в кабинет,  на партах стоят ноутбуки,  "
						"роботы и валяются кучи разных проводов.  Детей нет – занятия уже закончились."
						"На западе выход из кабинета и учебного корпуса. ";

			else return "Вы зашли в кабинет,  на партах стоят ноутбуки, "
					"роботы и валяются кучи разных проводов. За партами сидят дети, "
					"значит, занятия по робототехнике идут полным ходом. А вот и Сергей, вовсю рассказывает "
					"про программирование и логику роботов.  На западе выход из кабинета и учебного корпуса.";
		}
					
		else return "Уже поздно и учебный корпус сейчас закрыт. Хотя это может быть и не так, но лучше это не проверять…";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirWest) 
			return locCrossroad_3; // топаем на перекрёсток 3.
		return NULL;
	}
};

static AllLocation13 location;

Location *locSchool = &location;