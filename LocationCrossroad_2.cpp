#include "Location.h"

class AllLocation5 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "�� ������ � ������ ������ ������. � ��� �� ���, ����������, �����. ���� ������ �������� ��������, ������� � �������� �� ������ ��� � ��������� ������� �� �������";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locCrossroad_3; // ������� �� �������� ���, � ��������� �������.
		if (dir==DirWest)
			return locLamp; // ������ � ������ �� ����������
		if (dir==DirSouth)
			return locHome; // ��� �� �������
		return NULL;
	}
};

static AllLocation5 location;

Location *locCrossroad_2 = &location;