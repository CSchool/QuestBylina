#include "Location.h"

class AllLocation3 : public Location
{
public:
	AllLocation3()
	{
		addObject(new ObjBall);
		addObject(new ObjBasket);
	}
	virtual std::string getDescription() const
	{

		return "�� ����� �� ���������� ��������. ����� ���� ������������� ������, "
			"��������� ����. �� �� ���� �������� � �����, �� ����� � ������� � �������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth)
			return locRiver; // ������ � ������ �����
		if (dir==DirNorth)
			return locCrossroad_3; // ������ � ���������� 3, � ��������� �������
		return NULL;
	}
};

static AllLocation3 location;

Location *locCourt = &location;