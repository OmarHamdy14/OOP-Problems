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
Mobile Phone System
A Phone has Apps.
Apps can be opened or closed.
Some apps use internet, some don’t. 
Battery usage differs per app.
*/


class App {
protected:
    bool opened = false;
public:
    virtual ~App() = default;

    virtual string Name() const = 0;
    virtual bool UsesInternet() const = 0;
    virtual int BatteryDrain() const = 0;

    virtual void Open() {
        opened = true;
        cout << Name() << " opened\n";
    }

    virtual void Close() {
        opened = false;
        cout << Name() << " closed\n";
    }

    bool IsOpen() const { return opened; }
};


class SocialMediaApp : public App {
public:
    string Name() const override { return "Social Media App"; }
    bool UsesInternet() const override { return true; }
    int BatteryDrain() const override { return 15; }
};

class MusicApp : public App {
public:
    string Name() const override { return "Music App"; }
    bool UsesInternet() const override { return false; }
    int BatteryDrain() const override { return 8; }
};

class NavigationApp : public App {
public:
    string Name() const override { return "Navigation App"; }
    bool UsesInternet() const override { return true; }
    int BatteryDrain() const override { return 20; }
};