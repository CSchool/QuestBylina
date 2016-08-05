#include "Object.h"
#include "Location.h"

class Player : public ObjectsContainer
{
public:
	void takeObject(Object *obj);

	Location *getLocation(); // Получить текущую локацию
	void setLocation(Location *loc); // Установить текущую локацию
private:
	Location *currentLocation ; // Текущая локация
};

extern Player player;