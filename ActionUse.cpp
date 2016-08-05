#include "Action.h"
#include "Player.h"
#include <iostream>
#include "Flags.h"
#include "Object.h"



static void useWaterSugar(Object *water, Object *sugar)
{
	std::cout << "�� ������� � ������� � ������� ���� � �������� � - ��������� ������� � ������ �����!\n";
	player.removeObject(sugar);
	delete sugar;
	player.takeObject(new ObjSyrup);
	setStateFlag(FlagGetProgress,getStateFlag(FlagGetProgress)+1);
	getProgress();
}

static void useCosmeticsPeople(Object *cosmetics, Object *people)
{
	std::cout << "�� ���� ������� � ������ � ����� �������� �� �� ����� ���, ������, �������� � ������ ������ �������� �� ����."
		"�������, ��� ��������� �������� ������ ��������� � ���� - ��� ���� ����� ����������! =) \n";
	player.removeObject(cosmetics);
	delete cosmetics;
	useProgress();
}

static void useSyrupDoor (Object *syrup, Object *door)
{
	std::cout << "�� ������, ��� ������ ����� � ����� - �� ����� ������ ������ ���� ����� �����, ��.. ��� ���, "
		"�� ������� ����... �� �������� ������� ������� ����� , ������� �������! \n";
	player.removeObject(syrup);
	delete syrup;
	useProgress();
}

static void useFrogWC (Object *frog, Object *wc)
{
	std::cout << "�� ���������, ��� ������� �����-�� ������: ��������� ���� �� ����� � ����� ������� � ����...�, �����"
		 " ������� � �������� � �� ��� � �������. ��� ���� ������� �� ���� �����!\n";
	player.removeObject(frog);
	delete frog;
	useProgress();
}

static void useOilCorridor (Object *oil, Object *corridor)
{
	std::cout << "�� ���� � �������� �� ������� �����, ������ ��� ������ ����� ������� ����� ��� ����������� ����. "
		"����� ��������...\n";
	player.removeObject(oil);
	delete oil;
	useProgress();
}

static void usePepperBrush (Object *pepper, Object *brush)
{
	std::cout << "�� ������, ��� ������ ����� �� ������ ���� ��������, �� ��� ��� �� �� ����� "
		"�����, �������� �������� ������ ������ �����. ������ � ����� ����� ����� ���������� ������ ������� =)\n";
	player.removeObject(pepper);
	delete pepper;
	useProgress();
}

static void useRopeBed (Object *rope, Object *bed)
{
	std::cout << "��������� �� ����� ��������, �� ������, ��� ����� ���� ���� �������� ������. "
		"� ���� ����� ������ �� ����� - ��� ��� ������� �� ������ ���� ������, �� ��� ���� ������ ����!\n";
	player.removeObject(rope);
	delete rope;
	useProgress();
}

static void usePliersTap (Object *pliers, Object *tap)
{
	std::cout << "�� �������� ������� ������� ������� � �������� ����. ����� ���������� ����������� ����������� ���� � ����!\n";
	player.removeObject(pliers);
	delete pliers;
	useProgress();
}

static void useBasketBall ()
{
	if ((rand() % 2) == 0)
	{
		std::cout << "�� ���������� �������� ��� � �������, �� ������ ������������, � ��� ������ � �����. �������� ���� �� ���. "
			"�� ������ ����������� ������ ��� ��� ��� - ����� �������.\n";
	}
	else std::cout << "�� ���������� �������� ��� � �������,  � ��� ��� �������!  ���� �� ��� ���� �� �������������, �� ���� ��� ����� "
		"�� ��� �������� ��� ����! =) \n";
}

static void useWaterBall ()
{
	 std::cout << "����� ���� ������ ������,\n������� � ����� �����!\n����, ��������, �� �����,\n�� ������ � ����� ���!�\n\n"
		 "��������� ��� ����������� ������������,  ��  ������� �� ������ � ���� � ������� ���. ����� ��� ��������� �����"
		 " ������� �� ��������.\n";
}

static void useDARope ()
{
	 if (getStateFlag(FlagDARope) == 0)
	 {
		 std::cout << "��  �� ����� ����� ������ �� �������� ���������������, ����� ������� ���. �� ��� ����������� � "
			 "�� � ���� ���������. ������ ������ �� ����� ��� � ������� ������������� ��� ��������� ��� �������, "
			 "� ����� ��� � � ������ ���������.  �� ����� ��������� ����������, �� ������ �� ��� � ����� ������. "
			 "����� ������ ��� �� ������, � �� � ������ � ������ ��������.\n";
		 setStateFlag(FlagDARope, 1);
	 }
	 else
	 {
		std::cout << "��  �� ����� ����� ������ �� �������� ���������������, ����� ������� ���. �� ��� ����������� � "
			"�� � ���� ���������. ������ ������ �� ����� ��� � ������� ������������� ������ ���.  ���-�� �� ������������ "
			"����, � �� ������ ��������� � ������ � ������ �� ���� �� ��������. ��� ����� ������ �������. � ���������, �� �� ������ "
			"���������� ������� � ����������� ����, ��� ��� �� ����� ��������� � ������. �� ���������!\n";
		system("pause");
		exitGame();
	 }
}

static void useCosmeticsKsuha ()
{
	 std::cout << "(�����) ��� �� ���� ������ ��� �������? ��� � �� ��������?\n"
		 "(��) �? ��-�-��, �������. � ���... �� ������ ������\n"
		 "(�����) ��? �� ������ � ����.\n";
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
			std::cout << "��� ����� ���������!\n";
			return;
		}
		else 
		{
			if (playerObject1 == NULL && locationObject1 == NULL) 
			{
				std::cout << "������� �������� �� ����������!\n";
				return;
			}
			if (playerObject2 == NULL && locationObject2 == NULL) 
			{
				std::cout << "������� �������� �� ����������!\n";
				return;
			}
			if (playerObject1 != NULL) object1 = playerObject1; else object1 = locationObject1;
			if (playerObject2 != NULL) object2 = playerObject2; else object2 = locationObject2;
			if (object1 == object2)
			{
				std::cout << "������ ������������ ������� �� ����� ����!\n";
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
				std::cout << "������ ��������, �� ������� �����.\n";
				return;
			}
			


		}
	}
	virtual const char * const * getNames() const 
	{
		static const char *names[] = {"������������", "�������", "�����", "������������", "������", "���������", 0};
		return names;
	}
};

static ActionUse action;

const Action *actionUse = &action;