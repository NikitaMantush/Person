#pragma once
#pragma warning (disable:4996)
#include<iostream>
using namespace std;
const enum class gender { male , female };
class pers
{
private:
	const int _ID;
	char* aname;
	gender aGender;
	pers* aMother;
	pers* aFather;
	static int _nextID;
public:
	pers(const char*, gender, pers* = nullptr, pers* = nullptr);
	pers* getBirth(const char*, gender, pers* = nullptr);
    const int getID();
	const char* getName();
	void print(ostream& oc);
	const char* getMother();
	const char* getFather();
	const char* getGender();

};

