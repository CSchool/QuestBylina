#include <iostream>
#include <string>
#include <windows.h>

namespace QuestBylina
{
	class CommandManager
	{
	public:
		int Execute() ;//string Command); // Сканирование и выполнение комманд

	private:


	};


	class Game
	{
	public:
		void Loop(); // основной игровой цикл : реакция на изменение переменных в БД (игровые события)
	};


	class Database
	{
	public:
		int Search() ;//string Command) ;// валидация комманд в БД
		
	};

};