#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
* Problem Statement
Multiplayer Game Engine
Players, Weapons, and Abilities. 
Each player type (Warrior, Mage, Archer) has different attack logic.
*/

class Weapon {
protected:
	string Name;
	int Damage;
public:
	Weapon(const string& n,int dmg) : Name(n),Damage(dmg) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
	virtual void Use() const = 0;
};
class W1 : public Weapon {
public:
	void Use() const override {
		cout << "W1 ......\n";
	}
};
class W2 : public Weapon {
public:
	void Use() const override {
		cout << "W1 ......\n";
	}
};
class W3 : public Weapon {
public:
	void Use() const override {
		cout << "W1 ......\n";
	}
};


class Ability {
public:
	virtual void Effect() const = 0;
};
class Abl1 : public Ability {
public:
	void Effect() const override {
		cout << "Abl1 .......\n";
	}
};
class Abl2 : public Ability {
public:
	void Effect() const override {
		cout << "Abl2 .......\n";
	}
};
class Abl3 : public Ability {
public:
	void Effect() const override {
		cout << "Abl3 .......\n";
	}
};

class Player {
protected:
	string UserName;
	vector<shared_ptr<Weapon>> wpns;
	vector<shared_ptr<Ability>> abls;
public:
	Player(const string& n) : UserName(n){}
	const string& GetName() const { return UserName; }
	void SetName(const string& t) { UserName = t; }
	virtual void Attack() const = 0;
	virtual void Defend() const = 0;
	void AddWeapon(shared_ptr<Weapon>& wp) {
		wpns.push_back(wp);
	}
	void AddAbility(shared_ptr<Ability>& abl) {
		abls.push_back(abl);
	}
};
class Warrior : public Player {
public:
	Warrior(const string& n) : Player(n) {}
	void Attack() const override {

	}
	void Defend() const override {

	}
};
class Mage : public Player {
public:
	Mage(const string& n) : Player(n) {}
	void Attack() const override {

	}
	void Defend() const override {

	}
};
class Archer : public Player {
public:
	Archer(const string& n) : Player(n) {}
	void Attack() const override {

	}
	void Defend() const override {

	}
};

class Round {
	vector<unique_ptr<Player>> players;
public:
	void AddPayer(unique_ptr<Player>&& pl) {
		players.push_back(move(pl));
	}
};

int main() {
	shared_ptr<Weapon> wp1 = make_shared<W1>("1",30);
	shared_ptr<Weapon> wp2 = make_shared<W2>("2", 30);
	shared_ptr<Weapon> wp3 = make_shared<W3>("3", 30);

	shared_ptr<Ability> abl = make_shared<Abl2>();
	
	unique_ptr<Player> pl1 = make_unique<Archer>("hhh");

	pl1->AddAbility(abl);
	pl1->AddWeapon(wp1);


}