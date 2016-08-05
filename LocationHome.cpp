#include "Location.h"
#include "Flags.h"
#include <iostream>

class AllLocation8 : public Location
{
public:
	virtual std::string getDescription() const
	{
		if ((getStateFlag(FlagUseProgress)) == 7) 
		{
			return "�� ��������� � ���� ����� � �������� ���������� ������� �� ������, ��� �� ������ ��� �������. "
				"���������, ��������� ���� ������� ���������� �������, �� � ��� � ��� �����. ����� �� ���������� ��������� ���! "
				"�� ���� ��� ������ �������� �� ������ � ��, ������ �� �����, ������������ ������ �����, ����� ��������� �����. "
				"����������� ��� - �� ������� �������! �� ��������!!!";
			system("pause");
			exitGame();
		}
		return "�� ������ � �������� ������ ������, ����� "
			"���� �������� �������� ������, ����� ������� "
			"��������� � ���������. �� ������ �� ������ ����� � ���������, �� ��� � ����� �� �������, �� ������ - ����� �� �����";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locCrossroad_2; // ������� �� �������� ���, � ������ ��.
		if (dir==DirWest)
			return locRoom; // ��� � ���������
		if (dir==DirSouth)
			return locVerandah; // ��� �� �������
		return NULL;
	}
};

static AllLocation8 location;

Location *locHome = &location;