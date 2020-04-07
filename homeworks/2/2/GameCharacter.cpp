#include <cstring>
#include <iostream>
#include "GameCharacter.h"
GameCharacter::GameCharacter()
{
	name = new char[1];
	name[0] = '\0';
	HP = 0;
	MP = 0;
	AP = 0;
	DP = 0;
}

GameCharacter::GameCharacter(const char* _name, int _HP, int _MP, int _AP, int _DP)
{
	int length = strlen(_name) + 1;
	name = new char[length];
	strcpy_s(name, length, _name);

	setHP(_HP);
	setMP(_MP);
	setAP(_AP);
	setDP(_DP);
}

GameCharacter::GameCharacter(const GameCharacter& rhs)
{
	int length = strlen(rhs.name) + 1;
	name = new char[length];
	strcpy_s(name, length, rhs.name);

	setHP(rhs.HP);
	setMP(rhs.MP);
	setAP(rhs.AP);
	setDP(rhs.DP);
}

GameCharacter& GameCharacter::operator=(const GameCharacter& rhs)
{
	if (this != &rhs)
	{
		setName(rhs.name);
		setHP(rhs.HP);
		setMP(rhs.MP);
		setAP(rhs.AP);
		setDP(rhs.DP);
	}
	return *this;
}

void GameCharacter::setName(const char* newName)
{
	delete[] name;

	int length = strlen(newName) + 1;
	name = new char[length];
	strcpy_s(name, length, newName);
}
void GameCharacter::setHP(const int& newHP)
{
	HP = newHP;
}
void GameCharacter::setMP(const int& newMP)
{
	MP = newMP;
}
void GameCharacter::setAP(const int& newAP)
{
	AP = newAP;
}
void GameCharacter::setDP(const int& newDP)
{
	DP = newDP;
}

const char* GameCharacter::getName() const
{
	return name;
}
const int GameCharacter::getHP() const
{
	return HP;
}
const int GameCharacter::getMP() const
{
	return MP;
}
const int GameCharacter::getAP() const
{
	return AP;
}
const int GameCharacter::getDP() const
{
	return DP;
}

void GameCharacter::attack(const GameCharacter& other)
{
	std::cout << getName() << " is attacked by " << other.getName() << "\n";
	getattacked(other.getAP());
	std::cout << "New HP: " << getHP() << "\n";
}

void GameCharacter::getattacked(int other_AP)
{
	int attack = other_AP - DP;
	if (attack > 0)
	{
		HP -= attack;
	}
}

std::ostream& operator<<(std::ostream& out, const GameCharacter& character)
{
	out << "Name: " << character.getName() <<
		"\tHP: " << character.getHP() <<
		"\tMP: " << character.getMP() <<
		"\tAP: " << character.getAP() <<
		"\tDP: " << character.getDP() << "\n";
	return out;
}

GameCharacter::~GameCharacter()
{
	delete[] name;
}