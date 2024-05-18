#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
stack<pair<int, string>> s;

int getTime(string time1){ // 시간 문자열을 정수값으로 변환
    int hour1 = stoi(time1.substr(0, 2));
    int minute1 = stoi(time1.substr(3, 2));
    return hour1*60 + minute1;
}

bool cmp(vector<string> v1, vector<string> v2){ // 시간순 정렬
    return getTime(v1[1]) < getTime(v2[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    int i = 0;
    while(1){
        if(i == plans.size()-1) {
            answer.push_back(plans[i][0]);
            while(!s.empty()){
                answer.push_back(s.top().second);
                s.pop();
            }
            break;
        }
        
        if(i < plans.size()-1){
            string name = plans[i][0];
            string time = plans[i][1];
            string len = plans[i][2];
            int endTime = getTime(time) + stoi(len);
            int nextTime = getTime(plans[i+1][1]);
            int gap = endTime - nextTime;
            if(gap > 0){ // 중간에 중단해야 하는 과제
                s.push({gap, name}); // (완료까지 남은 시간, 이름)
                i++;
            } else { // 중단하지 않고 완료됨 -> 스택 확인해야함
                answer.push_back(name);
                if(gap == 0) { // 바로 다음 과제가 붙어있는 경우 스택 여부와 상관없이 다음 과제로 이동
                    i++;
                } else { // 중단된 과제가 있을 때
                    while(!s.empty()){
                        pair<int, string> now = s.top();
                        s.pop();
                        if(endTime + now.first <= nextTime){
                            answer.push_back(now.second);
                            endTime += now.first;
                            if(endTime == nextTime){
                                break;
                            }
                        } else {
                            s.push({endTime+now.first-nextTime, now.second});
                            break;
                        }
                    }
                    i++;
                } 
            }
        } 
    }    
    return answer;
}
