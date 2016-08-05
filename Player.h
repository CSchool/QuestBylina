#include "Object.h"
#include "Location.h"

class Player : public ObjectsContainer
{
public:
	void takeObject(Object *obj);

	Location *getLocation(); // �������� ������� �������
	void setLocation(Location *loc); // ���������� ������� �������
private:
	Location *currentLocation ; // ������� �������
};

extern Player player;