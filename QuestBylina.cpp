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

void getAction(string str) ; // ��������� action + objects
void printGetAction(string action, string objectFirst, string objectSecond) ; // ����� action + objects �� �����


int main()
{
	srand((int)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout <<  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "                            ������������ ��� � ����                             "
				  "                                                                                "
				  "                                                                                "
				  "                              ������������ ���ܻ                                "
				  "                                                                                "
				  "                                                                                "
				  "                           �� ������������ ��������                             "
				  "                                                                                "
				  "                          ��������� ����������� �����.                         "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "            � ���� ���� �� � ������� ������ � ������ ������ �������.           "
				  "          �������� ���� ������, � ������ �����������, ����������� ����!        "
				  "                                                                                "
				  "                                                                                "
				  "                ���������� ���� �������������� � ������� ������.                "
				  "                   ��� ������ ������� � ���� ������� ��������.                  "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                ";

	system("pause");

	player.setLocation(locRoom) ;

	std::cout << "(�������) ����, � ���������� ����� ����������. �� ����� ����� ����� �� ������ �������,"
		" ������� � ����������� ���� �� �����. ���� �� ��� ���-�� ����� ��������, �� ������� �����������"
		" � ���������� ������. �� �����?\n"
		"(��) ��, �� �� ��� �� ����������� ����?.. ��� �� ��.. �����.. ������� ������\n"
		"(�������) ���?! �� ��� ������ ������ � ����������� ����? ������� ��������! "
		"�����, ��� � � ���� ���� ������ �� �����. � ������ - ����� ���, � ���� �������� �������� "
		"�� ������. ������ ������� �� �������, ��������� � ������. ��, ��������.\n";

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
	char a ; // ���� ������� ������ ������ � ������� ������!!
	std::cin >> a ;
//	initInfoportion() ;
//	cout << getState(infStartGame) ;
 	return 0;
}

void getAction(string str) 
{
	const string prd[] = {" �� ", " � ", " �� ", " � ", " � "} ;
	const int prdCount = sizeof(prd) / sizeof(prd[0]) ;
	string action = "" ; // ��������
	string objectFirst = "" ; // ����-�� ���, ����-�� ����� � �.�. � �.�.
	string objectSecond = "" ; // ���-�� �����

	// ����� ������ ��������

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
		cout << "�� ����� ������������ ������! ��������� �����!\n" ;
	else 
		curAction -> doWith(s2, s3) ;
}

void printGetAction(string action, string objectFirst, string objectSecond)
{
	if (action == "") cout << "There is no action here!\n" ; else cout << "action = " << action << endl ;
	if (objectFirst == "") cout << "There is no objectFirst here!\n" ; else cout << "objectFirst = " << objectFirst << endl ;
	if (objectSecond == "") cout << "There is no objectSecond here!\n" ; else cout << "objectSecond = " << objectSecond << endl ;
}