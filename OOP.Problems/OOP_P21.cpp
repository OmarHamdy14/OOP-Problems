#include "OOP_P21.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Hotel Booking System
- Rooms can be reserved, canceled, and upgraded.
- Guests may check availability and pricing.
*/
enum State {
	available,
	reserved
};

class Room {
	int RoomNum;
	State RoomState;
	int Price;
public:
	Room(int rn,State rs,int p) : RoomNum(rn), RoomState(rs), Price(p) {}
	void DisplayRoomDetails() {
		cout << "Room " << RoomNum << "\n";
		if (RoomState == available) { cout << "Availabe for booking\n"; }
		else { cout << "Not availabe for booking\n"; }
		cout << "Price: " << Price << "\n";
	}
	State GetRoomState() const { return RoomState; }
	void SetRoomState(State n) { RoomState = n; }
	int GetRoomNum() const { return RoomNum; }
	void SetRoomNum(int n) { RoomNum = n; }
	int GetPrice() const { return Price; }
	void SetPrice(int n) { Price = n; }
};

class Hotel {
	vector<unique_ptr<Room>> Rooms;
public:
	void AddRoom(unique_ptr<Room> r) {
		Rooms.push_back(move(r));
	}
	void AddRoom_2(int RoomNum, State RoomState, int Price) {
		Rooms.push_back(make_unique<Room>(RoomNum, RoomState, Price));
	}
	void ShowAllRooms() {
		for (auto& room : Rooms) {
			room->DisplayRoomDetails();
			cout << "----------------------------------\n";
		}
	}
	void ReserveRoom(int roomNum) {
		for (auto& room : Rooms) {
			if (room->GetRoomNum() == roomNum) {
				if (room->GetRoomState() == available) room->SetRoomState(reserved);
				else cout << "U cant .... this room is already reserved\n";
			}
		}
	}
	void Cancel(int roomNum) {
		for (auto& room : Rooms) {
			if (room->GetRoomNum() == roomNum) {
				if (room->GetRoomState() == available) cout << "this room is already available\n";
				else room->SetRoomState(available);
			}
		}
	}
};