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

class Habitat {
private:
    string type;
    vector<Animal*> animals;
    double temperature;
    double humidity;

public:
    Habitat(const string& t, double temp, double hum)
        : type(t), temperature(temp), humidity(hum) {
    }

    void AddAnimal(Animal* a) {
        animals.push_back(a);
    }

    void ShowEnvironment() {
        
    }

    void ShowAnimals() {
        for (auto a : animals) {
            a->Sound();
        }
    }
};

class Visitor {
private:
    string visitorName;

public:
    Visitor(const string& n) : visitorName(n) {}

    void InteractWith(IInteractable* a) {
        cout << visitorName << " interacts: ";
        a->Interact();
    }
};

int main() {
    Animal* lion = new Lion("aa");
    Animal* elephant = new Elephant("bb");

    Habitat savanna("Savanna", 35, 20);
    Habitat arctic("Arctic Zone", -5, 60);

    savanna.AddAnimal(lion);
    savanna.AddAnimal(elephant);

    Visitor v("Omar");

    savanna.ShowEnvironment();
    savanna.ShowAnimals();

    arctic.ShowEnvironment();
    arctic.ShowAnimals();

    v.InteractWith(lion);
    v.InteractWith(elephant);

}
