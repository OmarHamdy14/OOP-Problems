#include "OOP_P23.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Music Playlist
- Songs can be added, removed, or shuffled.
- Playlists can repeat, or auto-generate based on mood.
*/
class Song {
public:
	string Name;
	Song(string& n) : Name(n) {}
};

enum Mode {
	repeat,
	autoGenerate
};
class Playlist {
public:
	string Name;
	Mode mode;
	vector<shared_ptr<Song>> Songs;
	Playlist(string& n, Mode m) : Name(n),mode(m) {}
	void AddSong(shared_ptr<Song>& sg) {
		Songs.push_back(sg);
	}
};

class MusicManager {
public:
	vector<unique_ptr<Playlist>> pls;
	void AddPL(unique_ptr<Playlist>&& pl) {
		pls.push_back(move(pl));
	}
};