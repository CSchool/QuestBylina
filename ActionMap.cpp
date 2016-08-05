#include "Action.h"
#include "Player.h"
#include <iostream>

class ActionMap : public Action
{
	
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		std::cout <<"\n\n"
					"                              ********                                          "
					"                             *  ���   *               ********                  "
					"                  ********    ***||***               *����� ��*                 "
					"                 *��������*      ||                  * ������ *                 "
					"                  ***||***       ||                   ***||***                  "
					"                     ||          ||                      ||                     "
					"      ********    ***||***    ***||***    ********    ***||***    ********      "
					"     * ������ ====��������==== ������ ====��������====��������====��.�����*     "
					"     * �������*   ********    ********    ***||***    ***||***    ********      "
					"      ********                               ||          ||                     "
					"                               ********   ***||***    ***||***                  "
					"                              *���������== ��� ���*  *�������.*                 "
					"                               ********   ***||***   *��������*                 "
					"          ����� *                            ||       ***||***                  "
					"                |                         ***||***       ||                     "
					"      ����� *---+---* ������             * �������*      ||                     "
					"                |                         ********       ||                     "
					"                * ��                                  ***||***                  "
					"                                                     *  ����� *                 "
					"                                                      ********                  \n";
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"�����", "�����������������", "���", 0};
		return names;
	}
	
};

static ActionMap action;

const Action *actionMap = &action;
