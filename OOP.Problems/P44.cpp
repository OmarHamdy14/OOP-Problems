#include "P44.h"
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
Music Streaming Platform
*/

class Song {
protected:
	string Name;
	string ArtistName;
public:
	Song(const string& n, const string& an) : Name(n),ArtistName(an) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
	const string& GetArtistName() const { return ArtistName; }
	void SetArtistName(const string& t) { ArtistName = t; }
	virtual void Play() const = 0;
};
class LocalSong : public Song {
public:
	LocalSong(const string& n, const string& an) : Song(n,an) {}
	void Play() const override { cout << "Playing Local Song ...\n"; }
};
class StreamedSong : public Song {
public:
	StreamedSong(const string& n, const string& an) : Song(n, an) {}
	void Play() const override { cout << "Playing Streamed Song ...\n"; }
};

class Album {
	string Name;
	vector<shared_ptr<Song>> sngs;
public:
	Album(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }

	void AddSong(shared_ptr<Song> sng) {
		sngs.push_back(sng);
	}

	void DisplaySongs() const {
		for (auto& sng : sngs) {
			cout << sng->GetName() << " " << sng->GetArtistName() << "\n";
		}
	}
};

class Playlist {
	string Name;
	vector<shared_ptr<Song>> sngs;
public:
	Playlist(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }

	void AddSong(shared_ptr<Song>& sng) {
		sngs.push_back(sng);
	}

	void DisplaySongs() const {
		for (auto& sng : sngs) {
			cout << sng->GetName() << " " << sng->GetArtistName() << "\n";
		}
	}

	void RemoveSong(const string& SongName) {
		for (auto it = sngs.begin(); it < sngs.end(); it++) {
			if (it->get()->GetName() == SongName) {
				sngs.erase(it);
				break;
			}
		}
	}

	void PlayList() const {
		for (auto& sng : sngs) {
			sng->Play();
		}
	}
};

class MusicService {
	vector<unique_ptr<Album>> albms;
	vector<unique_ptr<Playlist>> plys;
public:
	void AddAlbum(unique_ptr<Album>&& alb) {
		albms.push_back(move(alb));
	}
	void AddPlaylist(unique_ptr<Playlist>&& ply) {
		plys.push_back(move(ply));
	}
};

int main() {

}