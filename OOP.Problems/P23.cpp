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
	string Name;
public:
	Song(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

enum Mode {
	repeat,
	autoGenerate
};
class Playlist {
	string Name;
	Mode mode;
	vector<shared_ptr<Song>> Songs;
public:
	Playlist(const string& n, Mode m) : Name(n),mode(m) {}
	void AddSong(shared_ptr<Song>& sg) {
		Songs.push_back(sg);
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	Mode GetMode() const { return mode; }
	void SetMode(Mode n) { mode = n; }
};

class MusicManager {
	vector<unique_ptr<Playlist>> pls;
public:
	void AddPL(unique_ptr<Playlist>&& pl) {
		pls.push_back(move(pl));
	}
};