#include "Action.h"
#include "Player.h"
#include <iostream>
#include "Flags.h"
#include "Object.h"



static void useWaterSugar(Object *water, Object *sugar)
{
	std::cout << "Вы набрали в баночку с сахаром воды и потрясли её - получился сладкий и липкий сироп!\n";
	player.removeObject(sugar);
	delete sugar;
	player.takeObject(new ObjSyrup);
	setStateFlag(FlagGetProgress,getStateFlag(FlagGetProgress)+1);
	getProgress();
}

static void useCosmeticsPeople(Object *cosmetics, Object *people)
{
	std::cout << "Вы тихо подошли к спящим и стали рисовать на их лицах усы, бороды, веснушки и писать всякие послания на утро."
		"Говорят, что некоторые пугаются своего отражения с утра - эти люди точно испугаются! =) \n";
	player.removeObject(cosmetics);
	delete cosmetics;
	useProgress();
}

static void useSyrupDoor (Object *syrup, Object *door)
{
	std::cout << "Вы решили, что липкие ручки у двери - не самое лучшее начало утра ваших жертв, ну.. для них, "
		"по крайней мере... Вы намазали сиропом дверные ручки , пакость сделана! \n";
	player.removeObject(syrup);
	delete syrup;
	useProgress();
}

static void useFrogWC (Object *frog, Object *wc)
{
	std::cout << "Вы вспомнили, что говорил когда-то Сергей: «Печально было бы такую в ванне увидеть с утра...», взяли"
		 " лягушку и посадили её на пол в туалете. Ещё один сюрприз на утро готов!\n";
	player.removeObject(frog);
	delete frog;
	useProgress();
}

static void useOilCorridor (Object *oil, Object *corridor)
{
	std::cout << "На полу в коридоре Вы разлили масло, причем оно тонким слоем покрыло почти всю поверхность пола. "
		"Стало скользко...\n";
	player.removeObject(oil);
	delete oil;
	useProgress();
}

static void usePepperBrush (Object *pepper, Object *brush)
{
	std::cout << "Вы решили, что зубная паста со вкусом мяты устарела, но так как Вы не нашли "
		"пасту, пришлось посыпать перцем зубные щётки. Теперь у ваших жертв будет освежающее адское дыхание =)\n";
	player.removeObject(pepper);
	delete pepper;
	useProgress();
}

static void useRopeBed (Object *rope, Object *bed)
{
	std::cout << "Посмотрев на ножки кроватей, Вы решили, что между ними надо натянуть верёвку. "
		"С утра никто быстро не ходит - так что падение не должно быть резким, но оно явно должно быть!\n";
	player.removeObject(rope);
	delete rope;
	useProgress();
}

static void usePliersTap (Object *pliers, Object *tap)
{
	std::cout << "Вы поменяли местами вентиля горячей и холодной воды. Пусть помучаются настраивать температуру воды с утра!\n";
	player.removeObject(pliers);
	delete pliers;
	useProgress();
}

static void useBasketBall ()
{
	if ((rand() % 2) == 0)
	{
		std::cout << "Вы попытались закинуть мяч в корзину, но сильно промахнулись, и мяч улетел в овраг. Пришлось идти за ним. "
			"Вы можете попробовать кинуть его ещё раз - вдруг попадёте.\n";
	}
	else std::cout << "Вы попытались закинуть мяч в корзину,  и Вам это удалось!  Если бы это было на соревнованиях, то этот гол принёс "
		"бы Вам победные три очка! =) \n";
}

static void useWaterBall ()
{
	 std::cout << "«Наша Маша громко плачет,\nУронила в речку мячик!\nТихо, Машенька, не плачь,\nНе утонет в речке мяч!»\n\n"
		 "Вспоминая это трагическое произведение,  Вы  залезли по колено в воду и достали мяч. Потом ещё некоторое время"
		 " грелись на солнышке.\n";
}

static void useDARope ()
{
	 if (getStateFlag(FlagDARope) == 0)
	 {
		 std::cout << "Вы  не очень долго бегали за Дмитрием Александровичем, чтобы связать его. Он сам остановился и "
			 "Вы в него врезались. Верёвка выпала из Ваших рук и Дмитрий Александрович сам порывался Вас связать, "
			 "а потом ещё и к столбу привязать.  Но после некоторых препираний, он отстал от Вас и отдал верёвку. "
			 "Лучше больше так не делать, а то и правда к столбу привяжет.\n";
		 setStateFlag(FlagDARope, 1);
	 }
	 else
	 {
		std::cout << "Вы  не очень долго бегали за Дмитрием Александровичем, чтобы связать его. Он сам остановился и "
			"Вы в него врезались. Верёвка выпала из Ваших рук и Дмитрий Александрович поймал Вас.  Сам-то он благополучно "
			"ушёл, а Вы теперь привязаны к фонарю и никуда от него не денетесь. Ваш нашли поздно вечером. К сожалению, вы не смогли "
			"расставить ловушки в королевскую ночь, так как всё время простояли у столба. Вы проиграли!\n";
		system("pause");
		exitGame();
	 }
}

static void useCosmeticsKsuha ()
{
	 std::cout << "(Ксюша) Что ты этим хочешь мне сказать? Что я не красивая?\n"
		 "(Вы) Я? Не-е-ет, конечно. Я так... На всякий случай\n"
		 "(Ксюша) Да? Ну смотри у меня.\n";
}




class ActionUse : public Action
{
	virtual void doWith(const std::string &parameter1, const std::string &parameter2) const
	{
		Object *playerObject1 = player.getObject(parameter1);
		Object *playerObject2 = player.getObject(parameter2);
		Location *curLocation = player.getLocation();
		Object *locationObject1 = curLocation->getObject(parameter1);
		Object *locationObject2 = curLocation->getObject(parameter2);
		Object *object1 ;
		Object *object2 ;


		if (playerObject1 == NULL && locationObject1 == NULL && playerObject2 == NULL && locationObject2 == NULL)
		{
			std::cout << "Нет таких предметов!\n";
			return;
		}
		else 
		{
			if (playerObject1 == NULL && locationObject1 == NULL) 
			{
				std::cout << "Первого предмета не существует!\n";
				return;
			}
			if (playerObject2 == NULL && locationObject2 == NULL) 
			{
				std::cout << "Второго предмета не существует!\n";
				return;
			}
			if (playerObject1 != NULL) object1 = playerObject1; else object1 = locationObject1;
			if (playerObject2 != NULL) object2 = playerObject2; else object2 = locationObject2;
			if (object1 == object2)
			{
				std::cout << "Нельзя использовать предмет на самом себе!\n";
				return;
			}

			if (object1->getKind() == OKWater && object2->getKind() == OKSugar) 
				useWaterSugar(object1, object2);
			else if (object1->getKind() == OKSugar && object2->getKind() == OKWater) 
				useWaterSugar(object2, object1); 


			
			if ((object1->getKind() == OKBasket && object2->getKind() == OKBall) || 
				(object1->getKind() == OKBall && object2->getKind() == OKBasket))
			{
				useBasketBall();
				return;
			}
	
			if ((object1->getKind() == OKWater && object2->getKind() == OKBall) ||
				(object1->getKind() == OKBall && object2->getKind() == OKWater))
			{
				useWaterBall();
				return;
			}

			if ((object1->getKind() == OKDA && object2->getKind() == OKRope) ||
				(object1->getKind() == OKRope && object2->getKind() == OKDA))
			{
				useDARope();
				return;
			}

			if ((object1->getKind() == OKCosmetics && object2->getKind() == OKKsuha) ||
				(object1->getKind() == OKKsuha && object2->getKind() == OKCosmetics))
			{
				useCosmeticsKsuha();
				return;
			}




			if (getStateFlag(FlagNight) == FVNightYes)
			{
				if (object1->getKind() == OKCosmetics && object2->getKind() == OKPeople) 
					useCosmeticsPeople(object1, object2); 		
				else if (object1->getKind() == OKPeople && object2->getKind() == OKCosmetics) 
					useCosmeticsPeople(object2, object1);
					
				else if (object1->getKind() == OKSyrup && object2->getKind() == OKDoor) 
					useSyrupDoor(object1, object2); 		
				else if (object1->getKind() == OKDoor && object2->getKind() == OKSyrup)
					useSyrupDoor(object2, object1);

				else if (object1->getKind() == OKFrog && object2->getKind() == OKWC) 
					useFrogWC(object1, object2); 		
				else if (object1->getKind() == OKWC && object2->getKind() == OKFrog)
					useFrogWC(object2, object1);

				else if (object1->getKind() == OKOil && object2->getKind() == OKCorridor) 
					useOilCorridor(object1, object2); 		
				else if (object1->getKind() == OKCorridor && object2->getKind() == OKOil)
					useOilCorridor(object2, object1);

				else if (object1->getKind() == OKPepper && object2->getKind() == OKBrush) 
					usePepperBrush(object1, object2); 		
				else if (object1->getKind() == OKBrush && object2->getKind() == OKPepper)
					usePepperBrush(object2, object1);

				else if (object1->getKind() == OKRope && object2->getKind() == OKBed) 
					useRopeBed(object1, object2); 		
				else if (object1->getKind() == OKBed && object2->getKind() == OKRope)
					useRopeBed(object2, object1);

				else if (object1->getKind() == OKPliers && object2->getKind() == OKTap) 
					usePliersTap(object1, object2); 		
				else if (object1->getKind() == OKTap && object2->getKind() == OKPliers)
					usePliersTap(object2, object1);
			}

			else 
			{
				std::cout << "Глупое действие, не делайте этого.\n";
				return;
			}
			


		}
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"использовать", "набрать", "юзать", "приспособить", "кинуть", "забросить", 0};
		return names;
	}
};

static ActionUse action;

const Action *actionUse = &action;