#include <string>
class Action
{
public:
	virtual void doWith(const std::string &parameter1 = "", const std::string &parameter2 = "") const = 0;
	virtual const char * const * getNames() const = 0;
};

// Ищет объект-обработчик заданной команды
const Action *findAction(const std::string &name);
extern const Action *actionGo; // Идти куда-то
extern const Action *actionTake; // Взять что-то
extern const Action *actionInventory; // Посмотреть инвентарь
extern const Action *actionSmoke; // Курить шишку =)
extern const Action *actionTalk; // Поговорить с неписем
extern const Action *actionGive; // Дать неписю предмет
extern const Action *actionSay; // Сказать неписю ответ на поставленный вопрос
extern const Action *actionUse; // Использовать что-то
extern const Action *actionMap; // Смотреть карту
extern const Action *actionHelp; // Смотреть справку
extern const Action *actionLook; // Получить описание локации
