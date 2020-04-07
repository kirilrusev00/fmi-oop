#include "GameCharacter.h"
#include "Guardian.h"
#include "Warrior.h"
#include "Wizzard.h"
#include <iostream>

int main()
{
	Guardian a;
	Guardian g("guard");
	Warrior b;
	Wizzard c;

	std::cout << a;
	std::cout << g;
	std::cout << b;
	std::cout << c;
	b.attack(a);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	system("pause");

	return 0;
}