#include "Location.h"

class AllLocation7 : public Location
{
public:
	AllLocation7()
	{
		addObject(new ObjShishka);
		addObject(new ObjFrog);	
	}
	virtual std::string getDescription() const
	{

		return "��, �� ��������� � ����� ���� ����. ������ ��� �������, "
			"�������, ����� � ���� �����.  �� �������, ��� �������� � "
			"������ ���-�� ������ ���, �� ���� �� ���.";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locLamp; // ������ �� ���� � ������
		return NULL;
	}
};

static AllLocation7 location;

Location *locForest = &location;