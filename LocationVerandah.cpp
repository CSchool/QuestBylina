#include "Location.h"
#include "Flags.h"

class AllLocation1 : public Location
{
public:
	AllLocation1()
	{
		addObject(new HumanKsuha) ;
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo) 
			return "�� ���������� �� �������.  �� ����� ����� �����, "
				"�� ������� �������� ����� ��������, ������� � ���� "
				"�������� ����. �� ������ ����� ��������, �� ����� �� "
				"��� ����� ������� �� ������ ������ � �����. �� ����� "
				"������, �� ������, ��������� �����, �� ������� �� ������.";

		else return "�� ���������� �� �������.  �� ����� ����� �����, "
				"�� ������� �������� ����� ��������, ������� � ���� "
				"�������� ����. �� ����� "
				"������, �� ������, ��������� �����, �� ������� �� ������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locHome; //���� � ������� ����, �� ����(������� � � - Mixser) � �����))) ����, (�������! Mixser) �� �� ��.
		return NULL;
	}
};

static AllLocation1 location;

Location *locVerandah = &location;