#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionGive : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation() ;
		Object *curObject = player.getObject(parameter1) ;
		Object *man = curLocation->getObject(parameter2) ;

		if (curObject == NULL)
		{
			std::cout << "� ��� ��� ������ ��������!\n" ; 
			return;
		}
		if (man == NULL)
		{
			std::cout << "����� ��� ������ ��������.\n";
			return;
		}
		if (!man->canTalk())
		{
			std::cout << "���������� ������ ���� �������������� ��������.\n" ;
			return;
		}
		if (man->give(curObject))
		{
			player.removeObject(curObject) ;
			delete curObject;
		}

	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"����", "������", "��������", "������", 0};
		return names;
	}
};

static ActionGive action;

const Action *actionGive = &action;