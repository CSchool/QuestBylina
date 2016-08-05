#include "Location.h"
#include "Flags.h"
#include <iostream>

class AllLocation10 : public Location
{
public:
	AllLocation10()
	{
		addObject(new HumanDA) ;
	}
	virtual std::string getDescription() const
	{

		return "�� ������������ � �������� ��� ������ ������, ����� � ���������.  "
			"�� ����� ����  �������� � ���, �� ����� � � ��������"
			" � ����������������� �������, �� ������ � � ������ ������ ������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth)
			if (getStateFlag(FlagDA) == FVDABefore)
			{
				std::cout << "(������� �������������) ��� ���, �� ����-����! ��-�� ����� ��������!\n" ;
				return NULL;
			} 
			else return locForest; // ������ � ���, ���� �������� ������� ��������� ��������
		if (dir==DirWest)
			return locCrossroad_1; // ������ � �������� �� �������� 1.
		if (dir==DirEast)
			return locCrossroad_2; // ��� �� �������� 2.
		return NULL;
	}
};

static AllLocation10 location;

Location *locLamp = &location;