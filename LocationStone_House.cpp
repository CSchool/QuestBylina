#include "Location.h"
#include "Flags.h"


class AllLocation14 : public Location
{
public:
	AllLocation14()
	{
		addObject(new ObjPeople);
		addObject(new ObjBrush);
		addObject(new ObjWC);
		addObject(new ObjDoor);
		addObject(new ObjCorridor);
		addObject(new ObjTap);
		addObject(new ObjBed);
	}
	virtual std::string getDescription() const
	{

		if (getStateFlag(FlagNight) == FVNightNo)
			return "�� ���������� � ��������� ������ ����� ������������� �����. "
					"����������� � ����� ����� ����, ��� ����� ������� ������� ���� ������ "
					"������� ��� ���� � ������ ���� ������ � ���� ��� ����� ������ ������. ����� �� ������ � ��� �� ���";

		else return "�� ���������� � ��������� ������ ����� ������������� �����. ����������� � ����� ����� ����, ��� "
					"����� ������� ������� �������-�� �� ����� ����������. ����� �� ������: ������ �����, "
					"������ � ������� �������, ������, ��� � �������, ����� �����, ����� ������� � �������� ����,  ����� ��������.\n";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locCrossroad_3; // ������ � �������� 3
		return NULL;
	}
};

static AllLocation14 location;

Location *locStone_House = &location;