#include "Location.h"

class AllLocation4 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "�� ������ �� ������� ��������. "
			"�� ������ �� ������ ���������������� ������, "
			"�� ������ � ��������. �� ������ ������  �������� � ������ ������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locLamp; // ������ � ������
		if (dir==DirWest)
			return locAdministration; // ������ � ������������
		if (dir==DirNorth)
			return locKitchen; // ������ �� �����
		return NULL;
	}
};

static AllLocation4 location;

Location *locCrossroad_1 = &location;