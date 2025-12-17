#include "P55.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Virtual Zoo
Animals share a base class but have specialized behaviors (Eat, Move, Sound).
Habitats manage different groups of animals and environmental factors.
Visitors can interact virtually with animals through an interface.
*/

class IInteractable {
public:
    virtual void Interact() = 0;
};

class Animal : public IInteractable {
protected:
    string name;
public:
    Animal(const string& n) : name(n) {}

    virtual void Eat() = 0;
    virtual void Move() = 0;
    virtual void Sound() = 0;

    void Interact() override {
        cout << "You interact with " << name << "." << endl;
        Sound();
    }
};

class Lion : public Animal {
public:
    Lion(const string& n) : Animal(n) {}

    void Eat() override { cout << name << " eats meat.\n"; }
    void Move() override { cout << name << " runs quickly.\n"; }
    void Sound() override { cout << name << " llll!\n"; }
};
class Elephant : public Animal {
public:
    Elephant(const string& n) : Animal(n) {}

    void Eat() override { cout << name << " eats grass.\n"; }
    void Move() override { cout << name << " walks slowly.\n"; }
    void Sound() override { cout << name << " eeee!\n"; }
};