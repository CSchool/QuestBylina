#include "Location.h"
#include "Object.h"
#include "Flags.h"


class AllLocation9 : public Location
{
public:
	AllLocation9()
	{
		addObject(new HumanCook);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
			return "�� ������ � ��������. �� ����� ��������� ������, "
					"��������� ����. �����, ��������, ���� ������� �����. ������ ����������� �� ����� ������, �� ���, ��������� �����";

		else return "��� ������ � �������� ������ �������. ���� ��� ����� ���� � �� ���, �� ����� ��� �� ����������";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirSouth) 
			return locCrossroad_1; // ������ � ��������
		return NULL;
	}
};

static AllLocation9 location;

Location *locKitchen = &location;