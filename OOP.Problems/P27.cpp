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
public:
	string Name;
	Video(string& n) : Name(n) {}
	void Info() {
		cout << Name << "\n";
	}
};

class Channel {
public:
	string Name;
	vector<unique_ptr<Video>> OwnVds;
	WatchHistory WH;
	void AddVideo(string& n) {
		OwnVds.push_back(make_unique<Video>(n));
	}
	void WatchVideo() {}
};

struct VideoData {
	string Name;
	time_t time;
 };
class WatchHistory {
public:
	vector<VideoData> vdt;
	void AddVDT(unique_ptr<Video>& v) {
		VideoData vv = { v->Name, time(0) };
		vdt.push_back(vv);
	}
};

class VideoPlatform {
public:
	vector<unique_ptr<Channel>> Chs;
	void AddChannel(string& n) {
		Chs.push_back(make_unique<Channel>(n));
	}
	void PlayVideo() {

	}
	void PauseVideo() {

	}
	void ResumeVideo() {

	}
};