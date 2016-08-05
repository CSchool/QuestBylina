#include "Action.h"
#include "Player.h"
#include "Flags.h"
#include <iostream>

class ActionTalk : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const 
	{
		Location *curLocation = player.getLocation() ;
		Object *curObject = curLocation->getObject(parameter1) ;
		if (curObject != NULL)
		{
			if (curObject->canTalk()) 
			{
				if ((getStateFlag(FlagShishka)) == FVShishkaYes)
				{
					std::cout << "(" << curObject->getName() << ") Какой-то ты странный сегодня... Эй, ты чего смеёшься?\n"
						"(Вы) У-ха-ха-ха!! А-ха-ха-хах!! Это так смешно звучит, ой я не могу.. Аааа, мой мозг! А-ха-ха-хах!\n"
						"(" << curObject->getName() << ") Э-э-э-й! Ты тут вообще?..\n"
						"(Вы) Да... Да? Да! Тута я! Ля-ля-ля! Блин, как жрать хочу... Ку-ку!!!\n"
						"(" << curObject->getName() << ") О ужас! Ты выкурил шишку!!\n" 
						"(Вы) Ку-кууу?...\n\n"
						"Через пару часов Вы успокоились и перестали нести чушь. Вас исключили из лагеря и вскоре Вас "
						"забрали домой родители. А вот нечего курить всякую гадость в лесу! "
						"Вы не смогли осуществить своих гениальных замыслов, игра закончена. До свидания!\n";
					system("pause");
					exitGame();

				}
				curObject->talk();
				
			}
			else std::cout << "Предметы не разговаривают!\n";
		} 
		else 
		{
			std::cout << "Такого человека здесь нет!\n";
		}
	}

	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"говорить", "разговаривать", "поговорить", "общаться", "пообщаться", "болтать", "поболтать", 0};
		return names;
	}
};

static ActionTalk action;

const Action *actionTalk = &action;