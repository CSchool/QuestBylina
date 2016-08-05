#include "Location.h"
#include "Flags.h"

class AllLocation1 : public Location
{
public:
	AllLocation1()
	{
		addObject(new HumanKsuha) ;
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo) 
			return "Вы находитесь на веранде.  На стене висит доска, "
				"на которой написаны части программ, решений и тому "
				"подобные вещи. На партах стоят ноутбуки, за одним из "
				"них сидит девушка из Вашего отряда – Ксюша. За вашей "
				"спиной, на севере, находится дверь, из которой вы пришли.";

		else return "Вы находитесь на веранде.  На стене висит доска, "
				"на которой написаны части программ, решений и тому "
				"подобные вещи. За вашей "
				"спиной, на севере, находится дверь, из которой вы пришли.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locHome; //идет в коридор дома, то бишЬ(пишется с ь - Mixser) в домик))) бред, (Запятая! Mixser) но всё же.
		return NULL;
	}
};

static AllLocation1 location;

Location *locVerandah = &location;