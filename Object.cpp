#include "Object.h"
#include "Flags.h"
#include <iostream>
#include "Location.h"
#include "List"
#include "Player.h"
ObjectsContainer::~ObjectsContainer()
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
	{
		delete *i ;
	}
}

Object *ObjectsContainer::getObject(const std::string &name)
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
	{
		const char * const * names = (*i)->getNames();
		while (*names)
			if (*names++ == name)
				return *i;
	}
	
	return NULL;
}

Object *ObjectsContainer::getObject(ObjectKind kind)
{
	for (List::iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->getKind() == kind) return *i;
	return NULL;
}

void ObjectsContainer::addObject(Object *object)
{
	objects.push_back(object);
}
void ObjectsContainer::removeObject(Object *object)
{
	for (List::iterator i = objects.begin(); i != objects.end(); i++)
		if (*i == object)
		{
			objects.erase(i) ;
			return;
		}
}

void ObjectsContainer::printItems() const
{
	for (List::const_iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->canHandle() || (*i)->canTalk())
		{
			if (i == objects.begin()) 
				std::cout << (*i)->getName() ;
			else 
				std::cout << ", "  << (*i)->getName() ;
		}
	std::cout << "." << std::endl;
}

const char * const *ObjShishka::getNames() const
{
	static const char *names[] = {"шишка", "шишки", "шишке", "шишку", "шишкой", 0};
	return names;
}

const char * const *ObjSonnik::getNames() const
{
	static const char *names[] = {"сонник", "сонника", "соннику", "сонником", "соннике", 0};
	return names;
}

const char * const *HumanKsuha::getNames() const
{
	static const char *names[] = {"ксюша", "ксюши" , "ксюше", "ксюшу", "ксюшей", "ксения", "ксении", "ксенией", "ксю", 0};
	return names;
}

const char * const *HumanDA::getNames() const
{
	static const char *names[] = {"да", "дмитрий", "дмитрием", "дмитрию", "дмитрия", "дмитрии", "александрович", "александровичу", "александровича", "александровичем", "александровиче", 0};
	return names;
}

const char * const *HumanCook::getNames() const
{
	static const char *names[] = {"повар", "повара" , "повару", "поваром", "поваре", 0};
	return names;
}

const char * const *HumanVita::getNames() const
{
	static const char *names[] = {"вита", "вите" , "виты", "витой", "виту", "вв", 0};
	return names;
}

const char * const *HumanSerega::getNames() const
{
	static const char *names[] = {"сергей", "сергея" , "сергеем", "сергее", "сергею", "серёжа", 
		"серёжу", "серёже", "серёжей", "серёжи", "сережа", "сережу", "сереже", "сережей", "сережи", 0};
	return names;
}



const char * const *HumanTeacher::getNames() const
{
	static const char *names[] = {"вожатая", "вожатой" , "вожатую", 0};
	return names;
}

const char * const *ObjCosmetics::getNames() const
{
	static const char *names[] = {"косметика", "косметику", "косметике", "косметикой", "косметичка", "косметики", "косметичку", "косметичкой", "косметичке", "косметички", 0};
	return names;
}

const char * const *ObjPepper::getNames() const
{
	static const char *names[] = {"перец", "перца", "перцем", "перцу", "перце", 0};
	return names;
}

const char * const *ObjPliers::getNames() const
{
	static const char *names[] = {"плоскогубцы", "плоскогубцами", "плоскогубцев", "плоскогубцам", 0};
	return names;
}

const char * const *ObjFrog::getNames() const
{
	static const char *names[] = {"лягушка", "лягушки", "лягушку", "лягушкой", "лягушке", 0};
	return names;
}

const char * const *ObjRope::getNames() const
{
	static const char *names[] = {"верёвка", "веревка", "верёвку", "веревку", "верёвкой", "веревкой", "верёвке", "веревке", 0};
	return names;
}

const char * const *ObjOil::getNames() const
{
	static const char *names[] = {"масло", "масла", "маслом", 0};
	return names;
}

const char * const *ObjSugar::getNames() const
{
	static const char *names[] = {"баночка", "баночку", "баночкой", "баночке", "баночки", "сахар", "сахара", "сахаре", "сахаром",  "сахару",
		"банка", "банку", "банке", "банкой", "банки", 0};
	return names;
}

const char * const *ObjSyrup::getNames() const
{
	static const char *names[] = {"сироп", "сиропа", "сиропу", "сиропом", "сиропе", 0};
	return names;
}

const char * const *ObjBall::getNames() const
{
	static const char *names[] = {"баскетбольный", "баскетбольного", "баскетбольному", "баскетбольным", "баскетбольном", "мяч", 
		"мяча", "мячом", "мячу",  "мяч", "мяче", 0};
	return names;
}

const char * const *ObjWater::getNames() const
{
	static const char *names[] = {"речка", "речкой", "речки", "речке", "речку", "вода", "воде", "водой", "воды", "воду", "река", "реки", "реке", "реку", "рекой", 0};
	return names;
}

const char * const *ObjPeople::getNames() const
{
	static const char *names[] = {"дети", "детей", "детям", "детях", "люди", "людей", "людях", "людям", "людьми", 0};
	return names;
}

const char * const *ObjBrush::getNames() const
{
	static const char *names[] = {"щетки", "щётки", "щеток", "щёток", "щеткам", "щёткам", "щетками", "щётками", "щетках", "щётках", 
		"щетка", "щетке", "щетку", "щеткой", "щетки", "щётка", "щётке", "щётку", "щёткой", "щётки", "стакан", 
		"стакана", "стакану", "стаканом", "стакане", "зубные", "зубных", "зубным", "зубными", 0};
	return names;
}

const char * const *ObjWC::getNames() const
{
	static const char *names[] = {"туалет", "туалета", "туалету", "туалетом", "туалете", 0};
	return names;
}

const char * const *ObjDoor::getNames() const
{
	static const char *names[] = {"ручка", "ручки", "ручку", "ручке", "ручкой", "ручке", "дверь", "двери", "дверью", "ручек", "ручках", "ручками", "ручкам", 0};
	return names;
}

const char * const *ObjCorridor::getNames() const
{
	static const char *names[] = {"пол", "полу", "пола", "полом", "поле", "коридор", "коридора", "коридором", "коридоре", "коридору", 0};
	return names;
}

const char * const *ObjTap::getNames() const
{
	static const char *names[] = {"кран", "крана", "крану", "краном", "кране", "краны", "кранах", "кранами", "кранов", "кранам",
		"вентиль", "вентиля", "вентилю", "вентилем", "вентиле", "вентилях", "вентилей", "вентилями", "вентилям", 0};
	return names;
}

const char * const *ObjBed::getNames() const
{
	static const char *names[] = {"кровать", "кровати", "кроватью", "постель", "постели", "постелью", 0};
	return names;
}

const char * const *ObjBasket::getNames() const
{
	static const char *names[] = {"кольцо", "кольца", "кольце", "кольцом", "баскетбольное", "баскетбольному", "баскетбольным", 
		"баскетбольного", "баскетбольном", "корзина", "корзины", "корзину", "корзиной", "корзине", 0};
	return names;
}





void HumanKsuha::talk() 
{
	switch (getStateFlag(FlagKsuha)) 
	{
	case FVKsuhaBefore:		
		std::cout << "(Вы) Привет, Ксюш! Что делаешь?\n"
				"(Ксюша) Привет! Да вот фильм смотрю.\n"
				"(Вы) Слушай, скоро же тут королевская ночь, ты ничего готовить не будешь?\n"
				"(Ксюша) Не-е-ет, ты что. Хотя если у тебя есть пара идей, то, наверное, могу помочь…\n"
				"(Вы) Вместе было бы веселее! Смотри, что я тут придумал – можно, например, сделать подножки.."
				"Ну верёвку у пола привязать… Или на лицах что-нибудь нарисовать, только вот не знаю чем…\n"
				"(Ксюша) У меня с собой косметика есть, можно ей раскрасить. Я могу сейчас порыться, "
				"поискать что-нибудь, что не жалко потратить на раскраску лиц.\n"
				"(Вы) Круто! И ещё можно перцем посыпать зубные щётки! Вот ужас то будет!\n" 
				"(Ксюша) Ох, ты жестокий... =)\n"
				"(Вы) Да я ж чуть-чуть. Слушай, а где сахар можно взять?\n"
				"(Ксюша) Не знаю, у вожатой, наверное. А тебе зачем?\n"
				"(Вы) Да просто подумал, что липкие дверные ручки не лучшее начало дня...\n"
				"(Ксюша) Неплохая идея. Про сахар спроси у вожатой. Правда её сначала задобрить надо. "
				"Она тебя ненавидит, наверное. Ещё сахар в воде придётся растворить - "
				"иначе его не намазать на ручки. Ты, кстати, в столовую сейчас не пойдёшь? А то я свой сонник не взяла, "
				"если тебе не трудно, мой захватишь.\n"
				"(Вы) Хорошо, а ты пока поройся в косметичке.\n"
				"(Ксюша) Угу.\n";
		setStateFlag(FlagKsuha, FVKsuhaTalk);
		break;
	case FVKsuhaTalk: 
	case FVKsuhaGet: 
		std::cout << "(Ксюша) Принеси мне сонник и я тебе отдам косметику.\n";
		break;
	case FVKsuhaGive:
		std::cout << "(Ксюша) Всё собираешь вещи для приколов?\n"
					"(Вы) Угу, дела продвигаются\n"
					"(Ксюша) Давай, удачи\n"
					"(Вы) Спасибо\n";
		break;
	}
}

bool HumanKsuha::give(Object *obj)
{
	if (obj->getKind() == OKSonnik)	
	{
		std::cout << "(Ксюша) О, привет ещё раз! Я тут как раз нашла пару карандашей для глаз "
			"– идеально подойдут для раскраски лица!\n"
			"(Вы) Я рад, вот, кстати, твой сонник\n"
			"(Ксюша) Спасибо большое. Я тут подумала, что верёвку, наверное, можно в администрации попросить,"
			" типа для мирных целей, ну бельё повесить или ещё что-нибудь…\n"
			"(Вы) Отличная идея. Пойду - спрошу. Пока!\n"
			"(Ксюша) Давай, пока.\n\n"
			"Вы отдали предмет 'Сонник' Ксюше\n\n";

		player.takeObject(new ObjCosmetics);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		setStateFlag(FlagKsuha, FVKsuhaGive);
		return true;
	}
	else 
	{
		std::cout << "(" << getName() << ") Мне это не нужно!\n";
		return false;
	}
}

bool HumanTeacher::give(Object *obj)
{
	if ((obj->getKind() == OKBall) && (getStateFlag(FlagVita) == FVVitaTalkTeacher))
	{
		std::cout << "(Вы) Вот, я принёс мяч.\n"
					"(Вожатая) Молодец какой. Вот тебе сахар… Да и верёвку возьми – повесишь где-нибудь.\n"
					"(Вы) Спасибо! Кстати, Вы не знаете, у Сергея масла для роботов нет?..\n"
					"(Вожатая) У него самого спроси.\n";
		player.takeObject(new ObjRope);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		player.takeObject(new ObjSugar);
		setStateFlag(FlagVita, FVVitaGiveTeacher);
		return true;
	}
	else if ((obj->getKind() == OKFrog) && (getStateFlag(FlagGiveFrog) == 0))
	{
		std::cout << "(Вожатая) Фу-у-у-у! Убери эту гадость из моей комнаты! Убери-убери-убери! Нет! Не приближай её ко мне, не смей!\n\n"
			"Вожатая забилась под одеяло и долго не могла приди в себя после того, как Вы убрали лягушку с её глаз.\n";
		setStateFlag(FlagGiveFrog, 1);
		return false;
	}
	else if ((obj->getKind() == OKFrog) && (getStateFlag(FlagGiveFrog) != 0))
	{
		std::cout << "Хватит издеваться над вожатой!\n";
		return false;
	}
	else
	{
		std::cout << "(" << getName() << ") Мне это не нужно!\n";
		return false;
	}
}

static void taskDA()
{
	std::cout << "(Повар) Дмитрий Александрович, мы Вас так ждали! У нас тут что-то с водопроводом, помогите, пожалуйста! "
					"Вот тебе, пионерчик, перец, за то, что позвал Дмитрия Александровича к нам.\n"
					"(Дмитрий Александрович) Водопровод… Это не просто. Эй, пионер, помоги-ка мне!\n"
					"(Вы) Хорошо-хорошо, а что делать?\n"
					"(Дмитрий Александрович) Смотри, у нас тут 25 труб. Вот те 5 труб ни к чему в этом "
					"доме не подключены. А вот эти 18 труб снабжают водой первый этаж столовой, а эти 20 труб подключены "
					"ко второму этажу. В столовой сломались трубы, которые снабжали водой и первый, и второй этаж. "
					"Починить то я их и сам могу, а вот посчитать, сколько их… Короче, мне лень. Давай считай.\n";
		player.takeObject(new ObjPepper);
		setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
		getProgress();
		setStateFlag(FlagDA, FVDATask) ;

}



void HumanCook::talk() 
{
	switch (getStateFlag(FlagCook))
	{
	case FVCookFirstTalk:
		if ((getStateFlag(FlagKsuha)) == FVKsuhaBefore)
		{
			std::cout << "(Повар) Не мешай нам, а то ужина не получишь!\n";
		}
		else if ((getStateFlag(FlagKsuha)) == FVKsuhaTalk)
		{
			setStateFlag(FlagCook, FVCookWaitDA) ;
			std::cout << "(Повар) О, пионерчик! Ты не мог бы позвать Дмитрия Александровича? "
					"У нас тут поломки жуткие, может ужин даже не успеем приготовить…\n"
					"(Вы) Конечно позову, я только хотел спросить – у Вас чесночка или перца нет? Мне бы для доширака…\n"
					"(Повар) Ну вы даёте, когда дают – не едите, а как вредную пищу кушать – так сразу всё съедаете. "
					"Вроде остался пакетик. Ты приведи сюда Дмитрия Александровича, а я тебе перец отдам.\n";
					"Вот, кстати, сонник для твоего отряда. Отнеси своим.\n";
			player.takeObject(new ObjSonnik);
			setStateFlag(FlagKsuha, FVKsuhaGet);
		}
		break;
	case FVCookWaitDA:
		if ((getStateFlag(FlagDA)) == FVDATalk)
		{		
			taskDA() ;
		}
		else if (getStateFlag(FlagDA) == FVDATask)
		{
			std::cout << "(Повар) Тебе разве Дмитрий Александрович не дал задание? Если забыл, то спроси у него.\n";
		}
		else
		{
			std::cout << "(Повар) Ну где же Дмитрий Александрович? Приведи сюда его поскорее!\n";
		}
		break;
	case FVCookLastTalk:
		std::cout << "(Повар) Не мешай нам, а то ужина не получишь!\n";
		break;
	}
}

void HumanTeacher::talk()
{
	if ((getStateFlag(FlagVita)) == FVVitaWait)
	{
		std::cout << "(Вы) Здравствуйте! У Вас сахара не найдётся? Мне бы пару ложечек…\n"
					"(Вожатая) Да, только зайди чуть-чуть попозже, его ещё надо найти.\n"
					"(Вы) Вас Вита Владимировна просила зайти в административный корпус, забрать верёвку для сушки белья.\n"
					"(Вожатая) Хорошо, я схожу к Вите Владимировне, а ты пока сбегай на спортивную площадку, наш отряд "
					"там забыл мяч, забери его.\n\n";
		setStateFlag(FlagVita, FVVitaTalkTeacher);
		if (player.getObject(OKBall) == NULL)
		{	
			std::cout << "Вожатая ушла из домика.\n\n";
			locRoom->removeObject(this);
			delete this;
		}
		else std::cout << "Вожатая ушла из домика и вернулась через 10 минут. Вы просто подождали её в вожатской.\n\n"; 
	}
	else if (player.getObject(OKBall) != NULL && (getStateFlag(FlagVita)) == FVVitaTalkTeacher)
	{
		std::cout << "(Вожатая) Если ты забрал мяч, то отдай его мне.\n";
	}
	else 
	{
		std::cout << "(Вожатая) Ты что-то хотел?\n"
				"(Вы) Извините, ничего.\n";
	}
}


void HumanDA::talk() 
{
	if ((getStateFlag(FlagDA)) == FVDATalk)
	{		
		taskDA() ;
	}
	else if ((getStateFlag(FlagDA)) == FVDATask)
	{
		std::cout << "(Дмитрий Александрович) Смотри, у нас тут 25 труб. Вот те 5 труб ни к чему в этом "
					"доме не подключены. А вот эти 18 труб снабжают водой первый этаж столовой, а эти 20 труб подключены "
					"ко второму этажу. В столовой сломались трубы, которые снабжали водой и первый, и второй этаж. "
					"Починить то я их и сам могу, а вот посчитать сколько их… Короче, мне лень. Давай считай.\n";
	}
	else
	{
		if (getStateFlag(FlagCook))
		{
			std::cout << "(Вы) Дмитрий Александрович, Вас в столовую звали, у них так что-то сломалось. "
				"Починить только Вы можете, меня попросили Вас позвать и, если что, помочь.\n"
				"(Дмитрий Александрович) Ну конечно только я могу, это же великий Я! Хотя и тебя возьму - "
				"нечего по лагерю просто так шататься.\n";
				setStateFlag(FlagDA, FVDATalk) ;
			locLamp->removeObject(this);
			locKitchen->addObject(this);
			std::cout << "Дмитрий Александрович ушёл к поварам.\n";
		}
		else
		{
			std::cout << "(Дмитрий Александрович) Иди отсюда, мальчик. Не мешай.\n";
		}
	}

}


void HumanVita::talk() 
{
	if (((getStateFlag(FlagVita)) == FVVitaFirstTalk) && ((getStateFlag(FlagKsuha)) < FVKsuhaGive))
	{
		std::cout << "(Вита Владимировна) Нельзя гулять во время тихого часа. Иди в домик. Все вопросы - к вожатой.\n";
	}
	else if (((getStateFlag(FlagVita)) == FVVitaFirstTalk) && ((getStateFlag(FlagKsuha)) == FVKsuhaGive))
	{
		std::cout << "(Вы) Здравствуйте, Вита Владимировна! Я хотел попросить верёвку у Вас,"
			" нам не на что бельё мокрое после душа вешать…\n"
			"(Вита Владимировна) Здравствуй. Верёвку могу дать, но только вашей вожатой, "
			"чтобы не нарушать отчетностей. Скажи ей, пусть приходит ко мне, я отдам.\n"
			"(Вы) Хорошо, спасибо. Я побежал!\n"
			"(Вита Владимировна) Да бежать-то не надо, хотя.. как хочешь. Жду вожатую.\n";
			setStateFlag(FlagVita, FVVitaWait);
	}
	else if ((getStateFlag(FlagVita)) == FVVitaWait)
	{
		std::cout << "(Вита Владимировна) Не дам тебе верёвку. Зови вожатую.\n";
	}
	else if ((getStateFlag(FlagVita)) == FVVitaTalkTeacher)
	{
		std::cout << "(Вита Владимировна) Я только что отдала верёвку твоей вожатой, она в домик пошла. Там её, наверное, найдёшь.\n"
			"(Вы) Понятно, пойду обратно в домик. Спасибо!\n";
	}
	else if ((getStateFlag(FlagVita)) == FVVitaGiveTeacher)
	{
		std::cout << "(Вита Владимировна) Уже поздно, не время детям шататься по лагерю. Иди умывайся и ложись спать.\n";
	}
		
}


void HumanSerega::talk() 
{
	if ((getStateFlag(FlagSerega)) == FVSeregaFirstTalk && (getStateFlag(FlagVita)) == FVVitaGiveTeacher)
	{
		std::cout << "(Сергей) Привет, ученик. Как раз начинаются занятия по робототехнике! Садись.\n"
					"(Вы) Здрасте, угу…\n"
					"(Сергей) Итак! Сегодня будем учиться работать с датчиками в среде RoboLab! "
					"Сначала надо подключить датчик к, как его, роботу, берем датчик…\n"
					"(Вы) Извините! Мой робот плохо работает! Может его смазать надо?\n"
					"(Сергей) Да, возможно. Вот тебе один мой робот и документация: "
					"Автоматизированный робот «Ванна», собранный для подачи масла,  может налить "
					"и слить это масло из нужного нам сосуда. Для этого он имеет 10 кнопок. На каждой кнопке "
					"написаны порядковый номер этой кнопки и действие. Вот эти кнопки: «долить 1 л», «слить 1 л» «долить 2 л», "
					"«слить 2 л» «долить 3 л», «слить 3 л» «долить 4 л», «слить 4 л» «долить 5 л», «слить 5 л». Они имеют порядковые"
					" номера от 1 до 10 соответственно. Для смазки робота требуется 3 литра. (В ответе напишите порядковые номера кнопок,"
					" которые для этого нужно нажимать, например: 112221).\n"
					"(Вы) Стойте! Здесь почти все кнопки сломаны! Остались только «долить 5 л» и «слить 3 л»! "
					"Как мне отмерить нужный объём масла, используя наименьшее количество нажатий?\n"
					"(Сергей) Ой, забыл... Я как-то уже отмерял 3 литра, но не помню как я это делал. Подумай сам, это не сложно =) \n";
		setStateFlag(FlagSerega, FVSeregaWait);
	}
	else if (((getStateFlag(FlagSerega)) == FVSeregaFirstTalk) && ((getStateFlag(FlagVita)) != FVVitaGiveTeacher))
	{
		std::cout << "(Сергей) Сейчас не твой урок. Не мешай, пожалуйста, другим.\n";
	}
	else if ((getStateFlag(FlagSerega)) == FVSeregaWait)
	{
		std::cout << "(Сергей) Вот тебе один мой робот и документация: "
					"Автоматизированный робот «Ванна», собранный для подачи масла,  может налить "
					"и слить это масло из нужного нам сосуда. Для этого он имеет 10 кнопок. На каждой кнопке "
					"написаны порядковый номер этой кнопки и действие. Вот эти кнопки: «долить 1 л», «слить 1 л» «долить 2 л», "
					"«слить 2 л» «долить 3 л», «слить 3 л» «долить 4 л», «слить 4 л» «долить 5 л», «слить 5 л». Они имеют порядковые"
					" номера от 1 до 10 соответственно. Для смазки робота требуется 3 литра. (В ответе напишите порядковые номера кнопок,"
					" которые для этого нужно нажимать, например: 112221).\n"
					"(Вы) Стойте! Здесь почти все кнопки сломаны! Остались только «долить 5 л» и «слить 3 л»! "
					"Как мне отмерить нужный объём масла, используя наименьшее количество нажатий?\n"
					"(Сергей) Ой, забыл... Я как-то уже отмерял 3 литра, но не помню как я это делал. Подумай сам, это не сложно =) \n";
	}
	else if ((getStateFlag(FlagSerega)) == FVSeregaAccept)
	{
		std::cout << "(Сергей) Сейчас нет урока. \n";
	}
}


bool ObjectHuman::give(Object *obj)
{
	std::cout << "(" << getName() << ") Мне это не нужно!\n";
	return false;
}

void ObjectHuman::hear(const std::string &word)
{
	std::cout << "(" << getName() << ") Я не понимаю, о чём ты.\n";
}

void HumanDA::hear(const std::string &word)
{
	if ((getStateFlag(FlagDA)) == FVDATask)
	{
		if (word == "18" || word == "восемнадцать")
		{
			std::cout << "(Дмитрий Александрович) Молодец, я пошёл чинить.\n";
			locKitchen->addObject(new ObjPliers);
			locKitchen->removeObject(this);
			std::cout << "Дмитрий Александрович всё починил и ушёл домой, но, кажется, он что-то забыл.\n";
			setStateFlag(FlagCook, FVCookLastTalk);
			delete this;
		}
		else 
		{
			std::cout << "(Дмитрий Александрович) Что-то ты напутал, наверное. Посчитай ещё раз.\n";
		}
	}
	else
	{
		ObjectHuman::hear(word);
	}
}

void HumanSerega::hear(const std::string &word)
{
	if ((getStateFlag(FlagSerega)) == FVSeregaWait)
	{
		if (word == "9996666" || word == "9696966" || word == "9696696" || word == "9966966" || word == "9969666" || word == "9966696")
		{
			std::cout << "(Сергей) Молодец! Остатки масла можешь выкинуть. Только не разлей, а то кто-нибудь поскользнётся."
				" Кстати, вот и занятие закончилось! Все свободны..."
				"И осторожнее на улице: много лягушек и змей. Прям из леса прут, причём огромные. "
				"Печально было бы такую в ванне увидеть с утра... =) \n";
			player.takeObject(new ObjOil);
			setStateFlag(FlagGetProgress, getStateFlag(FlagGetProgress)+1);
			getProgress();
			setStateFlag(FlagSerega, FVSeregaAccept);

		}
		else 
		{
			std::cout << "(Сергей) До свидания! Шутка. Что-то у тебя не так. Проверь свой алгоритм.\n";
		}
	}
	else
	{
		ObjectHuman::hear(word);
	}
};

bool ObjectsContainer::isEmpty() const
{
	for (List::const_iterator i = objects.begin() ; i != objects.end() ; i++)
		if ((*i)->canHandle() || (*i)->canTalk())
		{
			return false;
		}
		return true;
}

void getProgress()
{
	
	if (getStateFlag(FlagGetProgress) == 7)
	{
		if (getStateFlag(FlagNight) == FVNightNo) 
		{
			setStateFlag(FlagNight, FVNightYes);
			std::cout << "Вы едва успели собрать все необходимые вещи для вашей вылазки, как "
				"наступила ночь. Краем глаза Вы заметили, что вожатая куда-то намылилась с ди-джеем, "
				"судя по их разговорам их вечер обещает быть долгим. Значит путь в чужой "
				"домик открыт! Пора бы уже туда заявиться…\n";
			Object *kuku = locRoom->getObject(OKTeacher);
			locRoom->removeObject(kuku);
			delete kuku;
			kuku = locAdministration->getObject(OKVita);
			locAdministration->removeObject(kuku);
			delete kuku;
			kuku = locKitchen->getObject(OKCook);
			locKitchen->removeObject(kuku);
			delete kuku;
			kuku = locSchool->getObject(OKSerega);
			locSchool->removeObject(kuku);
			delete kuku;
			kuku = locVerandah->getObject(OKKsuha);
			locVerandah->removeObject(kuku);
			delete kuku;
		}
		else return;
	}
	else if (getStateFlag(FlagGetProgress) == 0)
	{
		std::cout << "Вы ещё не собрали ни одной вещи, нужной для шалостей.\n";
	}
	else if (getStateFlag(FlagNight) == FVNightNo)
	{
		std::cout << "\nВы уже собрали " << getStateFlag(FlagGetProgress) << " из 7 вещей, нужных для шалостей!\n";
	}
}


void useProgress()
{
	setStateFlag(FlagUseProgress, getStateFlag(FlagUseProgress)+1);
	if (getStateFlag(FlagUseProgress) == 7)
	{
		std::cout << "Вы едва успели закончить последнюю шалость, как услышали шуршание в соседней комнате. "
				"Кажется, пора смываться... Вы прибежали в свой домик и радостно рассказали друзьям из отряда, что Вы только что сделали. "
				"Оказалось, атаковано было большое количество домиков, да и Ваш в том числе. Никто не заподозрит конкретно Вас! "
				"На утро был отъезд пионеров из лагеря и Вы, вместе со всеми, благополучно уехали домой, очень довольные собой. "
				"Поздравляем Вас - всё шалости сделаны! Вы выиграли!!!";
		system("pause");
		exitGame();
	}
	else 
	{
		std::cout << "\nВы уже сделали " << getStateFlag(FlagUseProgress) << " из 7 пакостей!\n\n";
	}
}

void exitGame()
{
	std::cout <<  "                                                                                "
				  "                                                                                "
				  "                             «КОРОЛЕВСКАЯ НОЧЬ»                                 "
				  "                                                                                "
				  "                                                                                "
				  "             Создатели:                                                         "
				  "                         Агарков Юрий                                           "
				  "                         Довгалюк Павел                                         "
				  "                         Михайлов Сергей                                        "
				  "                         Рогина Елизавета                                       "
				  "                                                                                "
				  "                                                                                "
				  "             Все совпадения имён персонажей случайны.                           "
				  "                                                                                "
				  "                                                                                "
				  "             Спасибо Вам за внимание!                                           "
				  "                                                                                "
				  "             Искренне Ваш,  сумасшедший квартет.                                "
				  "                                                                                "
				  "                                                                                "
				  "                                                                                "
				  "                                                       Август 2011 года         "
				  "                                                                                "
				  "                                                                                ";

	system("pause");
	exit(0);
}