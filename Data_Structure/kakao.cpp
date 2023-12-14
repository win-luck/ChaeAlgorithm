#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
vector<int> fee;

int calfee(string t1, string t2){
    int totalfee = 0;
    int hour1 = stoi(t1.substr(2));
    int hour2 = stoi(t2.substr(2));
    int minute1 = stoi(t1.substr(3, 2));
    int minute2 = stoi(t2.substr(3, 2));
    
    int totalhour = hour2 - hour1;
    int totalminute = minute2 - minute1;
    if(totalminute < 0){
        totalminute += 60;
        totalhour--;
    }
    totalminute += (totalhour * 60);
    // fee 배열: 기본시간(분) 기본시간(원) 단위시간(분) 단위시간 (원)
    if(totalminute > fee[0]){
        totalminute -= fee[0];
        totalfee += fee[1];
    } else { // 기본시간보다 적은 경우엔 기본요금만!
        return fee[1];
    }
    
    while(1){
        totalminute -= fee[2];
        totalfee += fee[3];
        if(totalminute <= 0) break;
    }
    cout << "no";
    return totalfee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> m;
    map<string, int> total;
    fee = fees;
    
    for(int i=0; i<records.size(); i++){
        string times = records[i].substr(0, 5);
        string id = records[i].substr(6, 4);
        cout << id << '\n';
        cout << times << '\n';
        if(m.count(id) == 0) // 입차
            m[id] = times;
        else // 출차
            total[id] = calfee(m[id], times);
            m.erase(id);
    }
    for(auto it: m){
        total[it.first] = calfee(it.second, "23:59");
    }
    for(auto it: total){
        answer.push_back(it.second);
    }
    return answer;
}