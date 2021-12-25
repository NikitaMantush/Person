#include "pers.h"
#include<iostream>
using namespace std;
int pers::_nextID = 0;
const int pers::getID()
{
	return _ID;
}
const char* pers::getName()
{
	return aname;
}
const char* pers::getMother()
{
	return aMother->getName();
}
const char* pers::getFather()
{
	return aFather->getName();
}
const char* pers::getGender()
{
	return this->aGender == gender::male ? "мужчина" : "жещина";
}
void pers::print(ostream& oc)
{
	oc << "имя человека :" <<getName() << endl;
	oc << "ID человека :" << getID() << endl;
	oc << "Пол человека :" << getGender() << endl;
	if (_ID > 2)
	{
		oc << "мать :" << getMother() << endl;

		if (aFather != nullptr)
		{
			oc << "отец :" << getFather() << endl;
		}
		else
		{
			oc << "отец неизвестен!" << endl;
		}
	}


}
pers::pers(const char* name, gender gender, pers * mother, pers * father):_ID(++_nextID)
{
		try
		{
			if (name == nullptr)
			{
				throw exception("Человек должен иметь имя");
			}
			if (_ID > 2 && mother == nullptr)
			{
				throw exception("Одним из родителей должна быть мать");
			}

			if (mother != nullptr && mother->aGender == gender::male)
			{
				throw exception("Мать должна быть женщиной");
			}
			if (father != nullptr && father->aGender == gender::female)
			{
				throw exception("Отец должен быть мужчиной");
			}
		}
		catch (const exception& exp)
		{
			cout << exp.what() << endl;
			exit(0);
		}
		aname = new char[strlen(name) + 1];
		strcpy(aname, name);
		aGender = gender;
		aMother = mother;
		aFather = father;
}
pers* pers::getBirth(const char* name, gender gender, pers* father)
{
	const char* addname = "";
	try
	{
		if (name == "")
		{
			throw exception("человек должен иметь имя");
		}
		else
		{
			addname = name;
		}
	}
	catch (const exception& exp)
	{
		cout << exp.what() << endl;
		exit(0);
	}

	auto childe = new pers(addname, gender, this, father);
	return childe;
}
	
