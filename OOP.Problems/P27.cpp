#include "P27.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Video Streaming Service
- Users can play, pause, and resume videos.
- Track watch history and suggest recommendations.
*/
class Video {
	string Name;
public:
	Video(const string& n) : Name(n) {}
	void Info() {
		cout << Name << "\n";
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Channel {
	string Name;
	vector<unique_ptr<Video>> OwnVds;
	WatchHistory WH;
public:
	void AddVideo(const string& n) {
		OwnVds.push_back(make_unique<Video>(n));
	}
	void WatchVideo() {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

struct VideoData {
	string Name;
	time_t time;
 };
class WatchHistory {
	vector<VideoData> vdt;
public:
	void AddVDT(unique_ptr<Video>& v) {
		VideoData vv = { v->GetName(), time(0)};
		vdt.push_back(vv);
	}
};

class VideoPlatform {
	vector<unique_ptr<Channel>> Chs;
public:
	void AddChannel(const string& n) {
		Chs.push_back(make_unique<Channel>(n));
	}
	void PlayVideo() {

	}
	void PauseVideo() {

	}
	void ResumeVideo() {

	}
};