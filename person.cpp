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
	pers Dasha = *Eva.getBirth("Dasha", gender::female, &Adam);
	Dasha.print(cout);
	cout << endl;
	pers Ivan = *Eva.getBirth("Ivan", gender::male, &Adam);
	Ivan.print(cout);
	cout << endl;
	pers Vera = *Dasha.getBirth("Vera", gender::female, &Ivan);
	Vera.print(cout);
	cout << endl;
	pers Jenya = *Vera.getBirth("Jenya", gender::male);
	Jenya.print(cout);
	cout << endl;
	pers Eva2= *Vera.getBirth("Eva", gender::female);
	Eva2.print(cout);
	cout << endl;
	pers Fedya("Fedya", gender::male);

	system("PAUSE");
	return 0;
}