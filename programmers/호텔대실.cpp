#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> getTime(vector<string> time){
    int hour1 = stoi(time[0].substr(0, 2));
    int minute1 = stoi(time[0].substr(3, 2));
    int hour2 = stoi(time[1].substr(0, 2));
    int minute2 = stoi(time[1].substr(3, 2));
    
    int a = hour1 * 60 + minute1;
    int b = hour2 * 60 + minute2;
    return {a, b+10};
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> v;
    vector<pair<int, int>> line;
    
    for(int i=0; i<book_time.size(); i++){
        v.push_back(getTime(book_time[i]));
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        line.push_back({v[i].first, 0});
        line.push_back({v[i].second, -1});      
    }
    sort(line.begin(), line.end());
    
    int cnt = 0;
    for(auto it: line){
        if(it.second == 0){
            cnt++;
            answer = max(answer, cnt);
        } else {
            cnt--;
        }
    }
    return answer;
}
