#ifndef OBJECT_H
#define OBJECT_H
#include <list>
#include <string>

enum ObjectKind
{
	OKShishka,
	OKKsuha,
	OKCook,
	OKTeacher,
	OKVita,
	OKSerega,
	OKSonnik,
	OKDA,
	OKCosmetics,
	OKPepper,
	OKPliers,
	OKFrog,
	OKRope,
	OKOil,
	OKSugar,
	OKSyrup,
	OKBall,
	OKWater,
	OKPeople,
	OKBrush,
	OKWC,
	OKDoor,
	OKCorridor,
	OKTap,
	OKBed,
	OKBasket

};
void exitGame();
void getProgress();
void useProgress();

class Object
{
public:
	virtual ~Object() = 0 {}
	virtual bool canHandle() const = 0;
	virtual bool canTalk() const = 0;
	virtual void hear(const std::string &word) {} 

	virtual void talk() {}
	virtual bool give(Object *obj) { return false; }
	virtual const char * const *getNames() const = 0; // Получить имена объекта (синонимы)
	virtual const char * getName() const = 0 ; // Получение системного имени
	virtual ObjectKind getKind() const = 0; // Получить вид объекта

private:

};

class ObjectsContainer
{
public:
	~ObjectsContainer() ;
	Object *getObject(const std::string &name); // Получение объекта по имени (string)
	Object *getObject(ObjectKind kind); // Получение объекта по виду объекта
	void addObject(Object *object); // Добавление объекта в список
	void removeObject(Object *object); // Удаление объекта из списка
	bool isEmpty() const; // Пустой ли лист с объектами? 
	void printItems() const ;

protected:
	typedef std::list<Object*> List; 
	List objects; // Список объекта
};


class ObjectInvisible : public Object
{
public:
	virtual bool canHandle() const {return false;}
	virtual bool canTalk() const {return false;}
};


class ObjectHandle : public Object
{
public:
	virtual bool canHandle() const {return true;}
	virtual bool canTalk() const {return false;}
};



class ObjectHuman : public Object
{
public:
	virtual void hear(const std::string &word);
	virtual bool canTalk() const {return true;}
	virtual bool canHandle() const {return false;}
	virtual bool give(Object *obj);
};


class HumanKsuha : public ObjectHuman
{
public:
	virtual void talk();
	virtual bool give(Object *obj);
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Ксюша";} ;
	virtual ObjectKind getKind() const {return OKKsuha;}

};

class HumanVita : public ObjectHuman
{
public:
	virtual void talk();
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Вита Владимировна";} ;
	virtual ObjectKind getKind() const {return OKVita;}

};

class HumanSerega : public ObjectHuman
{
public:
	virtual void talk();
	virtual void hear(const std::string &word);
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Сергей";} ;
	virtual ObjectKind getKind() const {return OKSerega;}

};

class HumanCook: public ObjectHuman
{
public:
	virtual void talk();
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Повар";} ;
	virtual ObjectKind getKind() const {return OKCook;}

};


class HumanDA: public ObjectHuman
{
public:
	virtual void hear(const std::string &word);
	virtual void talk();
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Дмитрий Александрович";} ;
	virtual ObjectKind getKind() const {return OKDA;}

};

class HumanTeacher: public ObjectHuman
{
public:
	virtual void talk();
	virtual bool give(Object *obj);
	virtual const char * const *getNames() const ;
	virtual const char * getName() const {return "Вожатая";} ;
	virtual ObjectKind getKind() const {return OKTeacher;}

};

class ObjShishka : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Шишка";} ;
	virtual ObjectKind getKind() const {return OKShishka;} 
};

class ObjSonnik : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Сонник";} ;
	virtual ObjectKind getKind() const {return OKSonnik;} 
};

class ObjCosmetics : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Косметика";} ;
	virtual ObjectKind getKind() const {return OKCosmetics;} 
};

class ObjPepper : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Перец";} ;
	virtual ObjectKind getKind() const {return OKPepper;} 
};

class ObjPliers : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Плоскогубцы";} ;
	virtual ObjectKind getKind() const {return OKPliers;} 
};

class ObjFrog : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Лягушка";} ;
	virtual ObjectKind getKind() const {return OKFrog;} 
};

class ObjRope : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Верёвка";} ;
	virtual ObjectKind getKind() const {return OKRope;} 
};

class ObjOil : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Масло";} ;
	virtual ObjectKind getKind() const {return OKOil;} 
};

class ObjSugar : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Баночка с сахаром";} ;
	virtual ObjectKind getKind() const {return OKSugar;} 
};

class ObjSyrup : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Сироп";} ;
	virtual ObjectKind getKind() const {return OKSyrup;} 
};


class ObjBall : public ObjectHandle
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Баскетбольный мяч";} ;
	virtual ObjectKind getKind() const {return OKBall;} 
};


class ObjWater : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Речка";} ;
	virtual ObjectKind getKind() const {return OKWater;} 
};

class ObjPeople : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Дети";} ;
	virtual ObjectKind getKind() const {return OKPeople;} 
};

class ObjBrush : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Стакан с зубными щётками";} ;
	virtual ObjectKind getKind() const {return OKBrush;} 
};

class ObjWC : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Туалет";} ;
	virtual ObjectKind getKind() const {return OKWC;} 
};

class ObjDoor : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Дверные ручки";} ;
	virtual ObjectKind getKind() const {return OKDoor;} 
};

class ObjCorridor : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Пол в коридоре";} ;
	virtual ObjectKind getKind() const {return OKCorridor;} 
};

class ObjTap : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Вентиль";} ;
	virtual ObjectKind getKind() const {return OKTap;} 
};

class ObjBed : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Кровати";} ;
	virtual ObjectKind getKind() const {return OKBed;} 
};

class ObjBasket : public ObjectInvisible
{
public:
	virtual const char * const *getNames() const ; 
	virtual const char * getName() const {return "Баскетбольное кольцо";} ;
	virtual ObjectKind getKind() const {return OKBasket;} 
};


#endif
