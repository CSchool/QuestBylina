enum FlagsList
{
	FlagStartGame, // Начало игры
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
	FlagEndGame, // Конец игры 
	FlagEndList // ! Должно стоять на последнем месте (Mixser)
};

enum FlagSystem
{
	EndFlag = FlagEndList // Не менять! (Mixser)
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

int getStateFlag(FlagsList flag) ; // Получение состояние текущего флага (есть ли он или нет)
void setStateFlag(FlagsList flag, int state) ; // Установка текущего флага (включить/выключить)
void enableFlag(FlagsList flag) ; // Выдача флага
void disableFlag(FlagsList flag) ; // Забирание флага
