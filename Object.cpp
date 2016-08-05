#include "Object.h"
#include "Flags.h"
#include <iostream>
#include "Location.h"
#include "List"
#include "Player.h"
ObjectsContainer::~ObjectsContainer()
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
	{
		delete *i ;
	}
}

Object *ObjectsContainer::getObject(const std::string &name)
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
	{
		const char * const * names = (*i)->getNames();
		while (*names)
			if (*names++ == name)
				return *i;
	}
	
	return NULL;
}

Object *ObjectsContainer::getObject(ObjectKind kind)
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->getKind() == kind) return *i;
	return NULL;
}

void ObjectsContainer::addObject(Object *object)
{
	objects.push_back(object);
}
void ObjectsContainer::removeObject(Object *object)
{
	for (List::iterator i = objects.begin(); i != objects.end(); i++)
		if (*i == object)
		{
			objects.erase(i) ;
			return;
		}
}

void ObjectsContainer::printItems() const
{
	for (List::const_iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->canHandle() || (*i)->canTalk())
		{
			if (i == objects.begin()) 
				std::cout << (*i)->getName() ;
			else 
				std::cout << ", "  << (*i)->getName() ;
		}
	std::cout << "." << std::endl;
}

const char * const *ObjShishka::getNames() const
{
	static const char *names[] = {"�����", "�����", "�����", "�����", "������", 0};
	return names;
}

const char * const *ObjSonnik::getNames() const
{
	static const char *names[] = {"������", "�������", "�������", "��������", "�������", 0};
	return names;
}

const char * const *HumanKsuha::getNames() const
{
	static const char *names[] = {"�����", "�����" , "�����", "�����", "������", "������", "������", "�������", "���", 0};
	return names;
}

const char * const *HumanDA::getNames() const
{
	static const char *names[] = {"��", "�������", "��������", "�������", "�������", "�������", "�������������", "��������������", "��������������", "���������������", "��������������", 0};
	return names;
}

const char * const *HumanCook::getNames() const
{
	static const char *names[] = {"�����", "������" , "������", "�������", "������", 0};
	return names;
}

const char * const *HumanVita::getNames() const
{
	static const char *names[] = {"����", "����" , "����", "�����", "����", "��", 0};
	return names;
}

const char * const *HumanSerega::getNames() const
{
	static const char *names[] = {"������", "������" , "�������", "������", "������", "�����", 
		"�����", "�����", "������", "�����", "������", "������", "������", "�������", "������", 0};
	return names;
}



const char * const *HumanTeacher::getNames() const
{
	static const char *names[] = {"�������", "�������" , "�������", 0};
	return names;
}

const char * const *ObjCosmetics::getNames() const
{
	static const char *names[] = {"���������", "���������", "���������", "����������", "����������", "���������", "����������", "�����������", "����������", "����������", 0};
	return names;
}

const char * const *ObjPepper::getNames() const
{
	static const char *names[] = {"�����", "�����", "������", "�����", "�����", 0};
	return names;
}

const char * const *ObjPliers::getNames() const
{
	static const char *names[] = {"�����������", "�������������", "������������", "������������", 0};
	return names;
}

const char * const *ObjFrog::getNames() const
{
	static const char *names[] = {"�������", "�������", "�������", "��������", "�������", 0};
	return names;
}

const char * const *ObjRope::getNames() const
{
	static const char *names[] = {"������", "�������", "������", "�������", "�������", "��������", "������", "�������", 0};
	return names;
}

const char * const *ObjOil::getNames() const
{
	static const char *names[] = {"�����", "�����", "������", 0};
	return names;
}

const char * const *ObjSugar::getNames() const
{
	static const char *names[] = {"�������", "�������", "��������", "�������", "�������", "�����", "������", "������", "�������",  "������",
		"�����", "�����", "�����", "������", "�����", 0};
	return names;
}

const char * const *ObjSyrup::getNames() const
{
	static const char *names[] = {"�����", "������", "������", "�������", "������", 0};
	return names;
}

const char * const *ObjBall::getNames() const
{
	static const char *names[] = {"�������������", "��������������", "��������������", "�������������", "�������������", "���", 
		"����", "�����", "����",  "���", "����", 0};
	return names;
}

const char * const *ObjWater::getNames() const
{
	static const char *names[] = {"�����", "������", "�����", "�����", "�����", "����", "����", "�����", "����", "����", "����", "����", "����", "����", "�����", 0};
	return names;
}

const char * const *ObjPeople::getNames() const
{
	static const char *names[] = {"����", "�����", "�����", "�����", "����", "�����", "�����", "�����", "������", 0};
	return names;
}

const char * const *ObjBrush::getNames() const
{
	static const char *names[] = {"�����", "�����", "�����", "�����", "������", "������", "�������", "�������", "������", "������", 
		"�����", "�����", "�����", "������", "�����", "�����", "�����", "�����", "������", "�����", "������", 
		"�������", "�������", "��������", "�������", "������", "������", "������", "�������", 0};
	return names;
}

const char * const *ObjWC::getNames() const
{
	static const char *names[] = {"������", "�������", "�������", "��������", "�������", 0};
	return names;
}

const char * const *ObjDoor::getNames() const
{
	static const char *names[] = {"�����", "�����", "�����", "�����", "������", "�����", "�����", "�����", "������", "�����", "������", "�������", "������", 0};
	return names;
}

const char * const *ObjCorridor::getNames() const
{
	static const char *names[] = {"���", "����", "����", "�����", "����", "�������", "��������", "���������", "��������", "��������", 0};
	return names;
}

const char * const *ObjTap::getNames() const
{
	static const char *names[] = {"����", "�����", "�����", "������", "�����", "�����", "������", "�������", "������", "������",
		"�������", "�������", "�������", "��������", "�������", "��������", "��������", "���������", "��������", 0};
	return names;
}

const char * const *ObjBed::getNames() const
{
	static const char *names[] = {"�������", "�������", "��������", "�������", "�������", "��������", 0};
	return names;
}

const char * const *ObjBasket::getNames() const
{
	static const char *names[] = {"������", "������", "������", "�������", "�������������", "��������������", "�������������", 
		"��������������", "�������������", "�������", "�������", "�������", "��������", "�������", 0};
	return names;
}





void HumanKsuha::talk() 
{
	switch (getStateFlag(FlagKsuha)) 
	{
	case FVKsuhaBefore:		
		std::cout << "(��) ������, ����! ��� �������?\n"
				"(�����) ������! �� ��� ����� ������.\n"
				"(��) ������, ����� �� ��� ����������� ����, �� ������ �������� �� ������?\n"
				"(�����) ��-�-��, �� ���. ���� ���� � ���� ���� ���� ����, ��, ��������, ���� �������\n"
				"(��) ������ ���� �� �������! ������, ��� � ��� �������� � �����, ��������, ������� ��������.."
				"�� ������ � ���� ���������� ��� �� ����� ���-������ ����������, ������ ��� �� ���� ���\n"
				"(�����) � ���� � ����� ��������� ����, ����� �� ����������. � ���� ������ ��������, "
				"�������� ���-������, ��� �� ����� ��������� �� ��������� ���.\n"
				"(��) �����! � ��� ����� ������ �������� ������ �����! ��� ���� �� �����!\n" 
				"(�����) ��, �� ��������... =)\n"
				"(��) �� � � ����-����. ������, � ��� ����� ����� �����?\n"
				"(�����) �� ����, � �������, ��������. � ���� �����?\n"
				"(��) �� ������ �������, ��� ������ ������� ����� �� ������ ������ ���...\n"
				"(�����) �������� ����. ��� ����� ������ � �������. ������ � ������� ��������� ����. "
				"��� ���� ���������, ��������. ��� ����� � ���� ������� ���������� - "
				"����� ��� �� �������� �� �����. ��, ������, � �������� ������ �� ������? � �� � ���� ������ �� �����, "
				"���� ���� �� ������, ��� ���������.\n"
				"(��) ������, � �� ���� ������� � ����������.\n"
				"(�����) ���.\n";
		setStateFlag(FlagKsuha, FVKsuhaTalk);
		break;
	case FVKsuhaTalk: 
	case FVKsuhaGet: 
		std::cout << "(�����) ������� ��� ������ � � ���� ����� ���������.\n";
		break;
	case FVKsuhaGive:
		std::cout << "(�����) �� ��������� ���� ��� ��������?\n"
					"(��) ���, ���� ������������\n"
					"(�����) �����, �����\n"
					"(��) �������\n";
		break;
	}
}

bool HumanKsuha::give(Object *obj)
{
	if (obj->getKind() == OKSonnik)	
	{
		std::cout << "(�����) �, ������ ��� ���! � ��� ��� ��� ����� ���� ���������� ��� ���� "
			"� �������� �������� ��� ��������� ����!\n"
			"(��) � ���, ���, ������, ���� ������\n"
			"(�����) ������� �������. � ��� ��������, ��� ������, ��������, ����� � ������������� ���������,"
			" ���� ��� ������ �����, �� ����� �������� ��� ��� ���-�������\n"
			"(��) �������� ����. ����� - ������. ����!\n"
			"(�����) �����, ����.\n\n"
			"�� ������ ������� '������' �����\n\n";

		player.takeObject(new ObjCosmetics);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		setStateFlag(FlagKsuha, FVKsuhaGive);
		return true;
	}
	else 
	{
		std::cout << "(" << getName() << ") ��� ��� �� �����!\n";
		return false;
	}
}

bool HumanTeacher::give(Object *obj)
{
	if ((obj->getKind() == OKBall) && (getStateFlag(FlagVita) == FVVitaTalkTeacher))
	{
		std::cout << "(��) ���, � ����� ���.\n"
					"(�������) ������� �����. ��� ���� ������ �� � ������ ������ � �������� ���-������.\n"
					"(��) �������! ������, �� �� ������, � ������ ����� ��� ������� ���?..\n"
					"(�������) � ���� ������ ������.\n";
		player.takeObject(new ObjRope);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		player.takeObject(new ObjSugar);
		setStateFlag(FlagVita, FVVitaGiveTeacher);
		return true;
	}
	else if ((obj->getKind() == OKFrog) && (getStateFlag(FlagGiveFrog) == 0))
	{
		std::cout << "(�������) ��-�-�-�! ����� ��� ������� �� ���� �������! �����-�����-�����! ���! �� ��������� � �� ���, �� ����!\n\n"
			"������� �������� ��� ������ � ����� �� ����� ����� � ���� ����� ����, ��� �� ������ ������� � � ����.\n";
		setStateFlag(FlagGiveFrog, 1);
		return false;
	}
	else if ((obj->getKind() == OKFrog) && (getStateFlag(FlagGiveFrog) != 0))
	{
		std::cout << "������ ���������� ��� �������!\n";
		return false;
	}
	else
	{
		std::cout << "(" << getName() << ") ��� ��� �� �����!\n";
		return false;
	}
}

static void taskDA()
{
	std::cout << "(�����) ������� �������������, �� ��� ��� �����! � ��� ��� ���-�� � ������������, ��������, ����������! "
					"��� ����, ���������, �����, �� ��, ��� ������ ������� �������������� � ���.\n"
					"(������� �������������) ���������� ��� �� ������. ��, ������, ������-�� ���!\n"
					"(��) ������-������, � ��� ������?\n"
					"(������� �������������) ������, � ��� ��� 25 ����. ��� �� 5 ���� �� � ���� � ���� "
					"���� �� ����������. � ��� ��� 18 ���� �������� ����� ������ ���� ��������, � ��� 20 ���� ���������� "
					"�� ������� �����. � �������� ��������� �����, ������� �������� ����� � ������, � ������ ����. "
					"�������� �� � �� � ��� ����, � ��� ���������, ������� ��� ������, ��� ����. ����� ������.\n";
		player.takeObject(new ObjPepper);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		setStateFlag(FlagDA, FVDATask) ;

}



void HumanCook::talk() 
{
	switch (getStateFlag(FlagCook))
	{
	case FVCookFirstTalk:
		if ((getStateFlag(FlagKsuha)) == FVKsuhaBefore)
		{
			std::cout << "(�����) �� ����� ���, � �� ����� �� ��������!\n";
		}
		else if ((getStateFlag(FlagKsuha)) == FVKsuhaTalk)
		{
			setStateFlag(FlagCook, FVCookWaitDA) ;
			std::cout << "(�����) �, ���������! �� �� ��� �� ������� ������� ��������������? "
					"� ��� ��� ������� ������, ����� ���� ���� �� ������ ������������\n"
					"(��) ������� ������, � ������ ����� �������� � � ��� �������� ��� ����� ���? ��� �� ��� ���������\n"
					"(�����) �� �� ����, ����� ���� � �� �����, � ��� ������� ���� ������ � ��� ����� �� ��������. "
					"����� ������� �������. �� ������� ���� ������� ��������������, � � ���� ����� �����.\n";
					"���, ������, ������ ��� ������ ������. ������ �����.\n";
			player.takeObject(new ObjSonnik);
			setStateFlag(FlagKsuha, FVKsuhaGet);
		}
		break;
	case FVCookWaitDA:
		if ((getStateFlag(FlagDA)) == FVDATalk)
		{		
			taskDA() ;
		}
		else if (getStateFlag(FlagDA) == FVDATask)
		{
			std::cout << "(�����) ���� ����� ������� ������������� �� ��� �������? ���� �����, �� ������ � ����.\n";
		}
		else
		{
			std::cout << "(�����) �� ��� �� ������� �������������? ������� ���� ��� ��������!\n";
		}
		break;
	case FVCookLastTalk:
		std::cout << "(�����) �� ����� ���, � �� ����� �� ��������!\n";
		break;
	}
}

void HumanTeacher::talk()
{
	if ((getStateFlag(FlagVita)) == FVVitaWait)
	{
		std::cout << "(��) ������������! � ��� ������ �� �������? ��� �� ���� �������\n"
					"(�������) ��, ������ ����� ����-���� �������, ��� ��� ���� �����.\n"
					"(��) ��� ���� ������������ ������� ����� � ���������������� ������, ������� ������ ��� ����� �����.\n"
					"(�������) ������, � ����� � ���� ������������, � �� ���� ������ �� ���������� ��������, ��� ����� "
					"��� ����� ���, ������ ���.\n\n";
		setStateFlag(FlagVita, FVVitaTalkTeacher);
		if (player.getObject(OKBall) == NULL)
		{	
			std::cout << "������� ���� �� ������.\n\n";
			locRoom->removeObject(this);
			delete this;
		}
		else std::cout << "������� ���� �� ������ � ��������� ����� 10 �����. �� ������ ��������� � � ���������.\n\n"; 
	}
	else if (player.getObject(OKBall) != NULL && (getStateFlag(FlagVita)) == FVVitaTalkTeacher)
	{
		std::cout << "(�������) ���� �� ������ ���, �� ����� ��� ���.\n";
	}
	else 
	{
		std::cout << "(�������) �� ���-�� �����?\n"
				"(��) ��������, ������.\n";
	}
}


void HumanDA::talk() 
{
	if ((getStateFlag(FlagDA)) == FVDATalk)
	{		
		taskDA() ;
	}
	else if ((getStateFlag(FlagDA)) == FVDATask)
	{
		std::cout << "(������� �������������) ������, � ��� ��� 25 ����. ��� �� 5 ���� �� � ���� � ���� "
					"���� �� ����������. � ��� ��� 18 ���� �������� ����� ������ ���� ��������, � ��� 20 ���� ���������� "
					"�� ������� �����. � �������� ��������� �����, ������� �������� ����� � ������, � ������ ����. "
					"�������� �� � �� � ��� ����, � ��� ��������� ������� ��� ������, ��� ����. ����� ������.\n";
	}
	else
	{
		if (getStateFlag(FlagCook))
		{
			std::cout << "(��) ������� �������������, ��� � �������� �����, � ��� ��� ���-�� ���������. "
				"�������� ������ �� ������, ���� ��������� ��� ������� �, ���� ���, ������.\n"
				"(������� �������������) �� ������� ������ � ����, ��� �� ������� �! ���� � ���� ������ - "
				"������ �� ������ ������ ��� ��������.\n";
				setStateFlag(FlagDA, FVDATalk) ;
			locLamp->removeObject(this);
			locKitchen->addObject(this);
			std::cout << "������� ������������� ���� � �������.\n";
		}
		else
		{
			std::cout << "(������� �������������) ��� ������, �������. �� �����.\n";
		}
	}

}


void HumanVita::talk() 
{
	if (((getStateFlag(FlagVita)) == FVVitaFirstTalk) && ((getStateFlag(FlagKsuha)) < FVKsuhaGive))
	{
		std::cout << "(���� ������������) ������ ������ �� ����� ������ ����. ��� � �����. ��� ������� - � �������.\n";
	}
	else if (((getStateFlag(FlagVita)) == FVVitaFirstTalk) && ((getStateFlag(FlagKsuha)) == FVKsuhaGive))
	{
		std::cout << "(��) ������������, ���� ������������! � ����� ��������� ������ � ���,"
			" ��� �� �� ��� ����� ������ ����� ���� �������\n"
			"(���� ������������) ����������. ������ ���� ����, �� ������ ����� �������, "
			"����� �� �������� �����������. ����� ��, ����� �������� �� ���, � �����.\n"
			"(��) ������, �������. � �������!\n"
			"(���� ������������) �� ������-�� �� ����, ����.. ��� ������. ��� �������.\n";
			setStateFlag(FlagVita, FVVitaWait);
	}
	else if ((getStateFlag(FlagVita)) == FVVitaWait)
	{
		std::cout << "(���� ������������) �� ��� ���� ������. ���� �������.\n";
	}
	else if ((getStateFlag(FlagVita)) == FVVitaTalkTeacher)
	{
		std::cout << "(���� ������������) � ������ ��� ������ ������ ����� �������, ��� � ����� �����. ��� �, ��������, ������.\n"
			"(��) �������, ����� ������� � �����. �������!\n";
	}
	else if ((getStateFlag(FlagVita)) == FVVitaGiveTeacher)
	{
		std::cout << "(���� ������������) ��� ������, �� ����� ����� �������� �� ������. ��� �������� � ������ �����.\n";
	}
		
}


void HumanSerega::talk() 
{
	if ((getStateFlag(FlagSerega)) == FVSeregaFirstTalk && (getStateFlag(FlagVita)) == FVVitaGiveTeacher)
	{
		std::cout << "(������) ������, ������. ��� ��� ���������� ������� �� �������������! ������.\n"
					"(��) �������, ���\n"
					"(������) ����! ������� ����� ������� �������� � ��������� � ����� RoboLab! "
					"������� ���� ���������� ������ �, ��� ���, ������, ����� ������\n"
					"(��) ��������! ��� ����� ����� ��������! ����� ��� ������� ����?\n"
					"(������) ��, ��������. ��� ���� ���� ��� ����� � ������������: "
					"������������������ ����� ������, ��������� ��� ������ �����,  ����� ������ "
					"� ����� ��� ����� �� ������� ��� ������. ��� ����� �� ����� 10 ������. �� ������ ������ "
					"�������� ���������� ����� ���� ������ � ��������. ��� ��� ������: ������� 1 �, ������ 1 � ������� 2 �, "
					"������ 2 � ������� 3 �, ������ 3 � ������� 4 �, ������ 4 � ������� 5 �, ������ 5 �. ��� ����� ����������"
					" ������ �� 1 �� 10 ��������������. ��� ������ ������ ��������� 3 �����. (� ������ �������� ���������� ������ ������,"
					" ������� ��� ����� ����� ��������, ��������: 112221).\n"
					"(��) ������! ����� ����� ��� ������ �������! �������� ������ ������� 5 � � ������ 3 �! "
					"��� ��� �������� ������ ����� �����, ��������� ���������� ���������� �������?\n"
					"(������) ��, �����... � ���-�� ��� ������� 3 �����, �� �� ����� ��� � ��� �����. ������� ���, ��� �� ������ =) \n";
		setStateFlag(FlagSerega, FVSeregaWait);
	}
	else if (((getStateFlag(FlagSerega)) == FVSeregaFirstTalk) && ((getStateFlag(FlagVita)) != FVVitaGiveTeacher))
	{
		std::cout << "(������) ������ �� ���� ����. �� �����, ����������, ������.\n";
	}
	else if ((getStateFlag(FlagSerega)) == FVSeregaWait)
	{
		std::cout << "(������) ��� ���� ���� ��� ����� � ������������: "
					"������������������ ����� ������, ��������� ��� ������ �����,  ����� ������ "
					"� ����� ��� ����� �� ������� ��� ������. ��� ����� �� ����� 10 ������. �� ������ ������ "
					"�������� ���������� ����� ���� ������ � ��������. ��� ��� ������: ������� 1 �, ������ 1 � ������� 2 �, "
					"������ 2 � ������� 3 �, ������ 3 � ������� 4 �, ������ 4 � ������� 5 �, ������ 5 �. ��� ����� ����������"
					" ������ �� 1 �� 10 ��������������. ��� ������ ������ ��������� 3 �����. (� ������ �������� ���������� ������ ������,"
					" ������� ��� ����� ����� ��������, ��������: 112221).\n"
					"(��) ������! ����� ����� ��� ������ �������! �������� ������ ������� 5 � � ������ 3 �! "
					"��� ��� �������� ������ ����� �����, ��������� ���������� ���������� �������?\n"
					"(������) ��, �����... � ���-�� ��� ������� 3 �����, �� �� ����� ��� � ��� �����. ������� ���, ��� �� ������ =) \n";
	}
	else if ((getStateFlag(FlagSerega)) == FVSeregaAccept)
	{
		std::cout << "(������) ������ ��� �����. \n";
	}
}


bool ObjectHuman::give(Object *obj)
{
	std::cout << "(" << getName() << ") ��� ��� �� �����!\n";
	return false;
}

void ObjectHuman::hear(const std::string &word)
{
	std::cout << "(" << getName() << ") � �� �������, � ��� ��.\n";
}

void HumanDA::hear(const std::string &word)
{
	if ((getStateFlag(FlagDA)) == FVDATask)
	{
		if (word == "18" || word == "������������")
		{
			std::cout << "(������� �������������) �������, � ����� ������.\n";
			locKitchen->addObject(new ObjPliers);
			locKitchen->removeObject(this);
			std::cout << "������� ������������� �� ������� � ���� �����, ��, �������, �� ���-�� �����.\n";
			setStateFlag(FlagCook, FVCookLastTalk);
			delete this;
		}
		else 
		{
			std::cout << "(������� �������������) ���-�� �� �������, ��������. �������� ��� ���.\n";
		}
	}
	else
	{
		ObjectHuman::hear(word);
	}
}

void HumanSerega::hear(const std::string &word)
{
	if ((getStateFlag(FlagSerega)) == FVSeregaWait)
	{
		if (word == "9996666" || word == "9696966" || word == "9696696" || word == "9966966" || word == "9969666" || word == "9966696")
		{
			std::cout << "(������) �������! ������� ����� ������ ��������. ������ �� ������, � �� ���-������ ������������."
				" ������, ��� � ������� �����������! ��� ��������..."
				"� ���������� �� �����: ����� ������� � ����. ���� �� ���� ����, ������ ��������. "
				"�������� ���� �� ����� � ����� ������� � ����... =) \n";
			player.takeObject(new ObjOil);
			setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
			getProgress();
			setStateFlag(FlagSerega, FVSeregaAccept);

		}
		else 
		{
			std::cout << "(������) �� ��������! �����. ���-�� � ���� �� ���. ������� ���� ��������.\n";
		}
	}
	else
	{
		ObjectHuman::hear(word);
	}
};

bool ObjectsContainer::isEmpty() const
{
	for (List::const_iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->canHandle() || (*i)->canTalk())
		{
			return false;
		}
		return true;
}

void getProgress()
{
	
	if (getStateFlag(FlagGetProgress) == 7)
	{
		if (getStateFlag(FlagNight) == FVNightNo) 
		{
			setStateFlag(FlagNight, FVNightYes);
			std::cout << "�� ���� ������ ������� ��� ����������� ���� ��� ����� �������, ��� "
				"��������� ����. ����� ����� �� ��������, ��� ������� ����-�� ���������� � ��-�����, "
				"���� �� �� ���������� �� ����� ������� ���� ������. ������ ���� � ����� "
				"����� ������! ���� �� ��� ���� ����������\n";
			Object *kuku = locRoom->getObject(OKTeacher);
			locRoom->removeObject(kuku);
			delete kuku;
			kuku = locAdministration->getObject(OKVita);
			locAdministration->removeObject(kuku);
			delete kuku;
			kuku = locKitchen->getObject(OKCook);
			locKitchen->removeObject(kuku);
			delete kuku;
			kuku = locSchool->getObject(OKSerega);
			locSchool->removeObject(kuku);
			delete kuku;
			kuku = locVerandah->getObject(OKKsuha);
			locVerandah->removeObject(kuku);
			delete kuku;
		}
		else return;
	}
	else if (getStateFlag(FlagGetProgress) == 0)
	{
		std::cout << "�� ��� �� ������� �� ����� ����, ������ ��� ��������.\n";
	}
	else if (getStateFlag(FlagNight) == FVNightNo)
	{
		std::cout << "\n�� ��� ������� " << getStateFlag(FlagGetProgress) << " �� 7 �����, ������ ��� ��������!\n";
	}
}


void useProgress()
{
	setStateFlag(FlagUseProgress, getStateFlag(FlagUseProgress)+1);
	if (getStateFlag(FlagUseProgress) == 7)
	{
		std::cout << "�� ���� ������ ��������� ��������� �������, ��� �������� �������� � �������� �������. "
				"�������, ���� ���������... �� ��������� � ���� ����� � �������� ���������� ������� �� ������, ��� �� ������ ��� �������. "
				"���������, ��������� ���� ������� ���������� �������, �� � ��� � ��� �����. ����� �� ���������� ��������� ���! "
				"�� ���� ��� ������ �������� �� ������ � ��, ������ �� �����, ������������ ������ �����, ����� ��������� �����. "
				"����������� ��� - �� ������� �������! �� ��������!!!";
		system("pause");
		exitGame();
	}
	else 
	{
		std::cout << "\n�� ��� ������� " << getStateFlag(FlagUseProgress) << " �� 7 ��������!\n\n";
	}
}

void exitGame()
{
	std::cout <<  "                                                                                "
				  "                                                                                "
				  "                             ������������ ���ܻ                                 "
				  "                                                                                "
				  "                                                                                "
				  "             ���������:                                                         "
				  "                         ������� ����                                           "
				  "                         �������� �����                                         "
				  "                         �������� ������                                        "
				  "                         ������ ���������                                       "
				  "                                                                                "
				  "                                                                                "
				  "             ��� ���������� ��� ���������� ��������.                           "
				  "                                                                                "
				  "                                                                                "
				  "             ������� ��� �� ��������!                                           "
				  "                                                                                "
				  "             �������� ���,  ����������� �������.                                "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "                                                       ������ 2011 ����         "
				  "                                                                                "
				  "                                                                                ";

	system("pause");
	exit(0);
}