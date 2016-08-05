// QuestBylina.cpp : Defines the entry point for the console application.
//
#define  _CRT_SECURE_NO_WARNINGS

#include <sstream>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <locale>

#include "Action.h"
#include "Player.h"
#include "Flags.h"
//#include "Infoportion.h"

#include "QuestBylina.h"

using namespace std ;

void getAction(string str) ; // Получение action + objects
void printGetAction(string action, string objectFirst, string objectSecond) ; // Вывод action + objects на экран


int main()
{
	srand((int)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout <<  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "                            Приветствуем Вас в игре                             "
				  "                                                                                "
				  "                                                                                "
				  "                              «КОРОЛЕВСКАЯ НОЧЬ»                                "
				  "                                                                                "
				  "                                                                                "
				  "                           от сумасшедшего квартета                             "
				  "                                                                                "
				  "                          «Инвалиды Умственного Труда».                         "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "            В этой игре Вы – озорной пионер в летнем лагере «Былина».           "
				  "          Устройте себе весёлую, а другим неожиданную, Королевскую ночь!        "
				  "                                                                                "
				  "                                                                                "
				  "                Управление игры осуществляется с помощью команд.                "
				  "                   Для вызова справки в игре введите «помощь».                  "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                ";

	system("pause");

	player.setLocation(locRoom) ;

	std::cout << "(Вожатая) Итак, я недовольна твоим поведением. За почти целую смену ты учудил столько,"
		" сколько я представить себе не могла. Если ты ещё что-то такое выкинешь, то придётся разбираться"
		" с директором лагеря. Ты понял?\n"
		"(Вы) Да, но… Но как же королевская ночь?.. Там же ну.. ночью.. ловушки всякие…\n"
		"(Вожатая) Что?! Ты ещё смеешь думать о королевской ночи? Никаких приколов! "
		"Помни, что я с тебя глаз больше не сведу. А сейчас - тихий час, я тебе запрещаю выходить "
		"из домика. Можешь сходить на веранду, поболтать с Ксюшей. Всё, свободен.\n";

	while ((getStateFlag(FlagEnd)) == FVEndNo)
	{
		string s ;
		std::cout << "\n> ";
		getline(cin,s) ;
		char buf[1024];
		strncpy(buf, s.c_str(), sizeof(buf));
		CharLowerA(buf);
		buf[sizeof(buf) - 1] = 0;
		getAction(buf) ;
	}
	char a ; // плюс считать символ пробел и перенос строки!!
	std::cin >> a ;
//	initInfoportion() ;
//	cout << getState(infStartGame) ;
 	return 0;
}

void getAction(string str) 
{
	const string prd[] = {" на ", " в ", " из ", " к ", " с "} ;
	const int prdCount = sizeof(prd) / sizeof(prd[0]) ;
	string action = "" ; // Действие
	string objectFirst = "" ; // Куда-то идём, кому-то отдаём и т.д. и т.п.
	string objectSecond = "" ; // Что-то отдаём

	// Найдём сперва предлоги

	for (int i=0; i<prdCount; i++)
	{
		size_t k = str.find(prd[i]) ;
		if ( k != str.npos )
		{
			str.erase(k, prd[i].size()-1) ;
			break;
		}
	}
	
	//printGetAction(action, objectFirst, objectSecond) ;
	istringstream ss(str);
	string s1, s2, s3;
	ss >> s1 >> s2 >> s3;
	const Action *curAction = findAction(s1) ;
	if (curAction == NULL) 
		cout << "Вы ввели неправильные данные! Повторите набор!\n" ;
	else 
		curAction -> doWith(s2, s3) ;
}

void printGetAction(string action, string objectFirst, string objectSecond)
{
	if (action == "") cout << "There is no action here!\n" ; else cout << "action = " << action << endl ;
	if (objectFirst == "") cout << "There is no objectFirst here!\n" ; else cout << "objectFirst = " << objectFirst << endl ;
	if (objectSecond == "") cout << "There is no objectSecond here!\n" ; else cout << "objectSecond = " << objectSecond << endl ;
}