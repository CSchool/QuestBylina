#include "Location.h"

class AllLocation6 : public Location
{
public:
	virtual std::string getDescription() const
	{

		return "�� ������ � ��������� �������. "
			"�� ��� ������������ ���������� ��������, "
			"�� ������� ��������� ������� ������, �� ������ ����� ��� ������, "
			"�� ����� �� ��� ������ �������� � �������� � ������ ������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locSchool; // ������ � ������� ������
		if (dir==DirWest)
			return locCrossroad_2; // ������ � �������� 2, ������� � ������ ��
		if (dir==DirNorth)
			return locStone_House;  // ������ � ����� "�� ������"
		if (dir==DirSouth)
			return locCourt; // ���� �� ���������� ��������
		return NULL;
	}
};

static AllLocation6 location;

Location *locCrossroad_3 = &location;