#include "Location.h"
#include "Flags.h"


class AllLocation11 : public Location
{
public:
	AllLocation11()
	{
		addObject(new ObjWater);
	}
	virtual std::string getDescription() const
	{

		return "����� ���� ����� � �����. ��� ����� ����� ������� ����, "
			" ���� ���, �������, ��� ������ ���������� �������� ��������� �� ������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirNorth) 
			return locCourt; // ������ �� ���������� ��������
		return NULL;
	}
};

static AllLocation11 location;

Location *locRiver = &location;