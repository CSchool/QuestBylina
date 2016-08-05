#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionSay : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation() ;
		Object *man = curLocation->getObject(parameter2) ;
		if (man == NULL)
		{
			std::cout << "�� �������� � ��������. ���� ��� �� ������ � ������, ���������� ��� �������! :)\n" ;
			return;
		}
		else man->hear(parameter1) ;
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"�������", "��������", 0};
		return names;
	}
};

static ActionSay action;

const Action *actionSay = &action;