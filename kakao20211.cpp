#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
map<string, string> car;
map<string, int> total;

int caltime(string in, string out, vector<int> fees){
    string hour1 = out.substr(0, 2);
    string minute1 = out.substr(3, 2);
    string hour2 = in.substr(0, 2);
    string minute2 = in.substr(3, 2);
    
    return 0;
    
    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string endtime = "23:59";
    // fees -> 기본시간/기본요금/단위시간/단위요금
    for(int i=0; i<records.size(); i++){
        string times = records[i].substr(0, 5);
        string id = records[i].substr(6, 4);
        if(car.count(id) <= 0) { // 입차
            car[id] = times;
        } else { // 출차
            total[id] += caltime(car[id], times, fees);
            car.erase(id);
        }
    }
    for(auto it: car){
        total[it.first] += caltime(car[it.second], endtime, fees);
    }
    for(auto it: total){
        answer.push_back(it.second);
    }
    return answer;
}
