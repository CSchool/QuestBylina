#include "Location.h"
#include "Flags.h"
#include <iostream>

class AllLocation8 : public Location
{
public:
	virtual std::string getDescription() const
	{
		if ((getStateFlag(FlagUseProgress)) == 7) 
		{
			return "Вы прибежали в свой домик и радостно рассказали друзьям из отряда, что Вы только что сделали. "
				"Оказалось, атаковано было большое количество домиков, да и Ваш в том числе. Никто не заподозрит конкретно Вас! "
				"На утро был отъезд пионеров из лагеря и Вы, вместе со всеми, благополучно уехали домой, очень довольные собой. "
				"Поздравляем Вас - всё шалости сделаны! Вы победили!!!";
			system("pause");
			exitGame();
		}
		return "Вы стоите в коридоре своего домика, перед "
			"вами красивый отрядный уголок, стены увешаны "
			"грамотами и наградами. На западе вы видите дверь в вожатскую, на юге – дверь на веранду, на севере - дверь на улицу";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locCrossroad_2; // переход на развилку два, у домика ГГ.
		if (dir==DirWest)
			return locRoom; // ход в вожатскую
		if (dir==DirSouth)
			return locVerandah; // ход на веранду
		return NULL;
	}
};

static AllLocation8 location;

Location *locHome = &location;