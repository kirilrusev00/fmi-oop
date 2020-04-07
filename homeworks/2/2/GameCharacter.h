#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>

class GameCharacter
{
private:
	char* name;
	int HP;
	int MP;
	int AP;
	int DP;

protected:
	GameCharacter();
	GameCharacter(const char* _name, int _HP, int _MP, int _AP, int _DP);
	GameCharacter(const GameCharacter&);

public:
	GameCharacter& operator=(const GameCharacter&);
	
	void setName(const char*);
	void setHP(const int&);
	void setMP(const int&);
	void setAP(const int&);
	void setDP(const int&);

	const char* getName() const;
	const int getHP() const;
	const int getMP() const;
	const int getAP() const;
	const int getDP() const;

	void attack(const GameCharacter&);
	void getattacked(int);

	friend std::ostream& operator<<(std::ostream&, const GameCharacter&);

	~GameCharacter();
};

#endif