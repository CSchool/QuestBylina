#include "Action.h"
#include "Player.h"
#include <iostream>
#include "Flags.h"
#include "Object.h"

class ActionTake : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation();
		Object *curObject = curLocation->getObject(parameter1);
		if (curObject != NULL)
		{
			if (curObject->canHandle())
			{
				player.takeObject(curObject);
				curLocation->removeObject(curObject);
				if ((curObject->getKind() != OKSonnik) && (curObject->getKind() != OKShishka) && (curObject->getKind() != OKBall))
				{
					setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
					getProgress();
				}
			}
			else std::cout << "Вы не можете это взять!\n";
		}
		else std::cout << "Здесь нет такого предмета!\n"; 
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"взять", "поднять", "получить", "забрать", 0};
		return names;
	}
};

static ActionTake action;

const Action *actionTake = &action;