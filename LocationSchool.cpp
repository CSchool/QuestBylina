#include "Location.h"
#include "Flags.h"

class AllLocation13 : public Location
{
public:
	AllLocation13()
	{
		addObject(new HumanSerega);
	}
	virtual std::string getDescription() const
	{
		if (getStateFlag(FlagNight) == FVNightNo)
		{
			if (getStateFlag(FlagSerega) == FVSeregaAccept)
				return "�� ����� � �������,  �� ������ ����� ��������,  "
						"������ � �������� ���� ������ ��������.  ����� ��� � ������� ��� �����������."
						"�� ������ ����� �� �������� � �������� �������. ";

			else return "�� ����� � �������,  �� ������ ����� ��������, "
					"������ � �������� ���� ������ ��������. �� ������� ����� ����, "
					"������, ������� �� ������������� ���� ������ �����. � ��� � ������, ����� ������������ "
					"��� ���������������� � ������ �������.  �� ������ ����� �� �������� � �������� �������.";
		}
					
		else return "��� ������ � ������� ������ ������ ������. ���� ��� ����� ���� � �� ���, �� ����� ��� �� ����������";
	}
	virtual Location *getDirection(Direction dir) const
	{
		if (dir==DirWest) 
			return locCrossroad_3; // ������ �� ���������� 3.
		return NULL;
	}
};

static AllLocation13 location;

Location *locSchool = &location;