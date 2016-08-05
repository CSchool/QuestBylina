#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionInventory : public Action
{

	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		if (!player.isEmpty())
		{
			std::cout << "У Вас сейчас есть: ";
			player.printItems();
		}
		else 
		{
			std::cout << "У Вас сейчас нет предметов." << std::endl;
		}
		getProgress();
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"инвентарь", "рюкзак", "карман", "хранилище",  0};
		return names;
	}
};

static ActionInventory action;

const Action *actionInventory = &action;