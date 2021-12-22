#include <iostream>
#include <execution>
#include "pers.h"

using namespace std;

int main()
{
	setlocale(0, "");
	pers Adam("Adam", gender::male);
	Adam.print(cout);
	cout << endl;
	pers Eva("Eva", gender::female);
	Eva.print(cout);
	cout << endl;
	pers Masha = *Eva.getBirth("Masha", gender::female, &Adam);
	Masha.print(cout);
	cout << endl;
	pers Ivan = *Eva.getBirth("Ivan", gender::male, &Adam);
	Ivan.print(cout);
	cout << endl;
	pers Anya = *Masha.getBirth("Anya", gender::female, &Ivan);
	Anya.print(cout);
	cout << endl;
	pers Jenya = *Anya.getBirth("", gender::male);
	Jenya.print(cout);
	cout << endl;
	pers Fedya("Fedya", gender::male);

	system("PAUSE");
	return 0;
}