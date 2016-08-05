#include "Location.h"
#include "Flags.h"


class AllLocation2 : public Location
{
public:
	AllLocation2()
	{
		addObject(new HumanVita);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
			return "�� ����� � ���������������� ������ ������. "
					"�� ������ ����� ���� ������������, ��������� �����-�� ��������� "
					"�, ��������, ������������ �����������. ����� �� ������� � ������� �� ���.";

		else return "��� ������ � ���������������� ������ ������ ������. ���� ��� ����� ���� � �� ���, �� ����� ��� �� ����������";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirEast) 
			return locCrossroad_1; // ������ � ��������
		return NULL;
	}
};

static AllLocation2 location;

Location *locAdministration = &location;