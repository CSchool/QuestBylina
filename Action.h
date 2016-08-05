#include <string>
class Action
{
public:
	virtual void doWith(const std::string &parameter1 = "", const std::string &parameter2 = "") const = 0;
	virtual const char * const * getNames() const = 0;
};

// ���� ������-���������� �������� �������
const Action *findAction(const std::string &name);
extern const Action *actionGo; // ���� ����-��
extern const Action *actionTake; // ����� ���-��
extern const Action *actionInventory; // ���������� ���������
extern const Action *actionSmoke; // ������ ����� =)
extern const Action *actionTalk; // ���������� � �������
extern const Action *actionGive; // ���� ������ �������
extern const Action *actionSay; // ������� ������ ����� �� ������������ ������
extern const Action *actionUse; // ������������ ���-��
extern const Action *actionMap; // �������� �����
extern const Action *actionHelp; // �������� �������
extern const Action *actionLook; // �������� �������� �������
