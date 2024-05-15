#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct music { // 정렬 및 정답 반환을 위한 음악 구조체
    int idx, time;
    string name;
    
    music(int a, int b, string c){
        idx = a;
        time = b;
        name = c;
    }
};

bool cmp(music m1, music m2){ // 시간 내림차순 + 등장 오름차순
    if(m1.time == m2.time){
        return m1.idx < m2.idx;
    }
    return m1.time > m2.time;
}

int getTime(string s1, string s2){ // 시간 계산
    int hour1 = stoi(s1.substr(0, 2));
    int minute1 = stoi(s1.substr(3, 2));
    int hour2 = stoi(s2.substr(0, 2));
    int minute2 = stoi(s2.substr(3, 2));
    
    int gap = minute2 - minute1;
    if(gap < 0){
        hour2--;
        gap += 60;
    }
    gap += (hour2-hour1) * 60;
    return gap;
}

string getMusic(int time, string s){ // 재생 시간에 따른 음악 산출
    string str = "";
    vector<string> v; // #으로 끝나는 경우 #도 포함해야 함
    for(int i=0; i<s.size(); i++){
        if(i < s.size()-1 && s[i+1] == '#'){
            v.push_back(s.substr(i, 2));
            i++;
        } else {
            string a = "";
            a += s[i];
            v.push_back(a);
        }
    }
    
    int len = v.size();
    for(int i=0; i<time; i++){
        str += v[i % len];
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<music> candi;
    
    for(int i=0; i<musicinfos.size(); i++){
        string started = musicinfos[i].substr(0, 5); // 시작시각
        string finished = musicinfos[i].substr(6, 5); // 종료시각
        string other = musicinfos[i].substr(12);
        string name = ""; // 음악 이름
        string origin = ""; // 음악 문자열
        for(int j=0; j<other.size(); j++){
            if(other[j] == ','){
                name = other.substr(0, j);
                origin = other.substr(j+1);
                break;
            }
        }
        int nowtime = getTime(started, finished); 
        string now = getMusic(nowtime, origin);

        if(now.size() < m.size()) continue; // 찾으려는 문자열이 더 긴 경우엔 불가능
        for(int j=0; j<now.size(); j++){
            if(j+m.size() > now.size()) break;
            if(now.substr(j, m.size()) == m){
                if(now[j+m.size()] != '#'){
                    candi.push_back(music(i, nowtime, name));
                }
            }
        }
    }
    
    if(candi.empty()) return "(None)"; // 없는 경우 None
    sort(candi.begin(), candi.end(), cmp); // 조건에 따라 정렬
    return candi[0].name;
}
