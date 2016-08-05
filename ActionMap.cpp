#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionMap : public Action
{
	
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		std::cout <<"\n\n"
					"                              ********                                          "
					"                             *  Лес   *               ********                  "
					"                  ********    ***||***               *Домик из*                 "
					"                 *Столовая*      ||                  * камней *                 "
					"                  ***||***       ||                   ***||***                  "
					"                     ||          ||                      ||                     "
					"      ********    ***||***    ***||***    ********    ***||***    ********      "
					"     * Админи ====Развилка==== Фонарь ====Развилка====Развилка====Уч.домик*     "
					"     * страция*   ********    ********    ***||***    ***||***    ********      "
					"      ********                               ||          ||                     "
					"                               ********   ***||***    ***||***                  "
					"                              *Вожатская== Ваш дом*  *Спортив.*                 "
					"                               ********   ***||***   *площадка*                 "
					"          Север *                            ||       ***||***                  "
					"                |                         ***||***       ||                     "
					"      Запад *---+---* Восток             * Веранда*      ||                     "
					"                |                         ********       ||                     "
					"                * Юг                                  ***||***                  "
					"                                                     *  Речка *                 "
					"                                                      ********                  \n";
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"карта", "месторасположение", "где", 0};
		return names;
	}
	
};

static ActionMap action;

const Action *actionMap = &action;
