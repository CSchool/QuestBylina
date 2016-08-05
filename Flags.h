enum FlagsList
{
	FlagStartGame, // ������ ����
	FlagCook,
	FlagDA,
	FlagDARope,
	FlagVita,
	FlagKsuha,
	FlagSerega,
	FlagShishka,
	FlagEnd,
	FlagGetProgress,
	FlagUseProgress,
	FlagGiveFrog,
	FlagNight,
	FlagEndGame, // ����� ���� 
	FlagEndList // ! ������ ������ �� ��������� ����� (Mixser)
};

enum FlagSystem
{
	EndFlag = FlagEndList // �� ������! (Mixser)
};

enum FlagsValues 
{
	FVKsuhaBefore = 0,
	FVKsuhaTalk,
	FVKsuhaGet,
	FVKsuhaGive,

	FVDABefore = 0,
	FVDATalk,
	FVDATask,

	FVCookFirstTalk = 0, 
	FVCookWaitDA, 
	FVCookLastTalk,

	FVVitaFirstTalk = 0,
	FVVitaWait,
	FVVitaTalkTeacher,
	FVVitaGiveTeacher,

	FVSeregaFirstTalk = 0,
	FVSeregaWait,
	FVSeregaAccept,

	FVShishkaNo = 0,
	FVShishkaYes,

	FVEndNo = 0,
	FVEndYes,

	FVNightNo = 0,
	FVNightYes

};

int getStateFlag(FlagsList flag) ; // ��������� ��������� �������� ����� (���� �� �� ��� ���)
void setStateFlag(FlagsList flag, int state) ; // ��������� �������� ����� (��������/���������)
void enableFlag(FlagsList flag) ; // ������ �����
void disableFlag(FlagsList flag) ; // ��������� �����
