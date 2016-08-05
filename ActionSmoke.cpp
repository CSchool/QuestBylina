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
				// �������� ��� ���� ��					
				std::cout << "�� ���������� �������� ����� � ��� ��� �������! ��, ���������!\n";
				player.removeObject(curObject) ;
				setStateFlag(FlagShishka, FVShishkaYes);
			}
			else std::cout << "������ ��� �������!\n" ;
		}
		else std::cout << "� ��� ��� ������ ��������!\n" ;
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"�������", "��������", "���������", "������", "�����", "��������", "������", 0};
		return names;
	}
};

static ActionSmoke action;

const Action *actionSmoke = &action;