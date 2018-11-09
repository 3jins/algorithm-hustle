// 15:10 ~ 15:19, 16:25 ~ 17:22
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class MusicInfo {
public:
    string title;
    string notes;

    MusicInfo(string title, string notes) {
        this->title = title;
        this->notes = notes;
    }
};

// Replace /.#/ to single byte characters
string convertSharps(string str) {
    string converted;
    int strLen = str.length();
    char buffer = str[0];
    for (int i = 1; i < strLen; i++) {
        if(str[i] == '#') {
            buffer += 'G' - 'A' + 1;
            converted += buffer;
            continue;
        }
        converted += buffer;
        buffer = str[i];
    }
    converted += buffer;
    return converted;
}

string solution(string neoNotes, vector<string> musicInfos) {
    neoNotes = convertSharps(neoNotes);

    // Refine the raw information
    vector<MusicInfo *> refinedMusicInfos;
    vector<string>::iterator iter;
    for (iter = musicInfos.begin(); iter != musicInfos.end(); iter++) {
        const string musicInfo = *iter;
        regex tester("([0-9]{2}:[0-9]{2}),([0-9]{2}:[0-9]{2}),([A-Z]+),([A-Z#]+)");
        smatch match;
        if (regex_search(musicInfo.begin(), musicInfo.end(), match, tester)) {
            // time info
            string startStr = match[1];
            int start = stoi(startStr.substr(0, 2)) * 60 + stoi(startStr.substr(3, 2));
            string endStr = match[2];
            int end = stoi(endStr.substr(0, 2)) * 60 + stoi(endStr.substr(3, 2));
            int broadcastTime = end - start;

            // title info
            string title = match[3];

            // note info
            string wholeNotes = "";
            string notes = convertSharps(match[4]);
            int musicLength = notes.length();
            for (int i = 0; i < broadcastTime; i++) {
                wholeNotes += notes[i % musicLength];
            }

            refinedMusicInfos.push_back(new MusicInfo(title, wholeNotes));
        }
    }

    // Find the music
    vector<MusicInfo *>::iterator iter2;
    for (iter2 = refinedMusicInfos.begin(); iter2 != refinedMusicInfos.end(); iter2++) {
        MusicInfo *refinedMusicInfo = *iter2;
        if ((refinedMusicInfo->notes).find(neoNotes) != string::npos) return refinedMusicInfo->title;
    }

    return "(None)";
}