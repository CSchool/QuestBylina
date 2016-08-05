#include "Action.h"
#include "Player.h"
#include "Flags.h"
#include <iostream>

class ActionSmoke : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		Object *curObject = player.getObject(parameter1) ;
		if (curObject != NULL)
		{
			if (curObject->getKind() == OKShishka)
			{	
				// проверка где есть ГГ					
				std::cout << "Вы попытались выкурить шишку и Вам это удалось! Ух, понеслась!\n";
				player.removeObject(curObject) ;
				setStateFlag(FlagShishka, FVShishkaYes);
			}
			else std::cout << "Нельзя это скурить!\n" ;
		}
		else std::cout << "У вас нет такого предмета!\n" ;
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"скурить", "скурнуть", "укуриться", "дунуть", "вдуть", "выкурить", "курить", 0};
		return names;
	}
};

static ActionSmoke action;

const Action *actionSmoke = &action;