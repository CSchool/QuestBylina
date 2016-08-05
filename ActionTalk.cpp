#include "Action.h"
#include "Player.h"
#include "Flags.h"
#include <iostream>

class ActionTalk : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation() ;
		Object *curObject = curLocation->getObject(parameter1) ;
		if (curObject != NULL)
		{
			if (curObject->canTalk()) 
			{
				if ((getStateFlag(FlagShishka)) == FVShishkaYes)
				{
					std::cout << "(" << curObject->getName() << ") �����-�� �� �������� �������... ��, �� ���� �������?\n"
						"(��) �-��-��-��!! �-��-��-���!! ��� ��� ������ ������, �� � �� ����.. ����, ��� ����! �-��-��-���!\n"
						"(" << curObject->getName() << ") �-�-�-�! �� ��� ������?..\n"
						"(��) ��... ��? ��! ���� �! ��-��-��! ����, ��� ����� ����... ��-��!!!\n"
						"(" << curObject->getName() << ") � ����! �� ������� �����!!\n" 
						"(��) ��-����?...\n\n"
						"����� ���� ����� �� ����������� � ��������� ����� ����. ��� ��������� �� ������ � ������ ��� "
						"������� ����� ��������. � ��� ������ ������ ������ ������� � ����! "
						"�� �� ������ ����������� ����� ���������� ��������, ���� ���������. �� ��������!\n";
					system("pause");
					exitGame();

				}
				curObject->talk();
				
			}
			else std::cout << "�������� �� �������������!\n";
		} 
		else 
		{
			std::cout << "������ �������� ����� ���!\n";
		}
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"��������", "�������������", "����������", "��������", "����������", "�������", "���������", 0};
		return names;
	}
};

static ActionTalk action;

const Action *actionTalk = &action;