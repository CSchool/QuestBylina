#include "Location.h"
#include <iostream>

void Location::printDescription() const
{
	std::cout << getDescription() << "\n";
	if (!isEmpty())
	{
		std::cout << "Здесь находятся: ";
		printItems();
	}
}