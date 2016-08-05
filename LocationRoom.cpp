#include "Location.h"
#include <iostream>

class AllLocation12 : public Location
{
public:
	AllLocation12()
	{
		addObject(new HumanTeacher);
	}
	
	virtual std::string getDescription() const
	{

		return "�� ������ � ������� ��������. "
			"�� ����� ����� ������, ������, ��������, �������, "
			"�����, ���������, ���������� � ������ �������. "
			"������� ���������, �� �����  � ����� ��� �� ������ =)"
			"  �� ����� ������, �� �������, ��������� ����� �� �������.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast)
			return locHome; // ����� �� ���������
		return NULL;
	}
};

static AllLocation12 location;

Location *locRoom = &location;