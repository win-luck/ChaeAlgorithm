#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    string todaypart[3];
    int todaypartint[3];
    
    int cnt = 0;
    for(int i=0; i<today.size(); i++){
        if(today[i] == '.'){
            todaypartint[cnt] = stoi(todaypart[cnt]);
            cnt++;
            continue;
        }
        todaypart[cnt] += today[i];
    }
    todaypartint[cnt] = stoi(todaypart[cnt]);
    cnt = 0;
    // todaypart[0]은 년도, [1]은 월, [2]는 일
    
    for(int a=1; a<=privacies.size(); a++){
        int limits = 0;
        for(int j=0; j<terms.size(); j++){
            if(terms[j].front() == privacies[a-1].back()){
                string t = terms[j];
                for(int b=0; b<terms[j].size(); b++){
                    if(t[b] == ' '){
                        t = t.substr(b+1, 3);
                    }
                }
                limits = stoi(t); // 유효기간
                break;
            }
        } // 이 개인정보의 종류를 결정
        
        string thispart[3];
        int thispartint[3];
        string now = privacies[a-1];
        for(int k=0; k<now.size(); k++){
            if(now[k] == '.'){
                thispartint[cnt] = stoi(thispart[cnt]);
                cnt++;
                continue;
            }
            if(now[k] == ' '){
                thispartint[cnt] = stoi(thispart[cnt]);
                cnt++;
                break;
            }
            thispart[cnt] += now[k];
        }
        cnt = 0;
        
        // 이제 특정 개인정보와 오늘과의 날짜 차이를 검증한다.
        // 특정 개인정보 + limits가 오늘보다 작을 경우 이를 포함해야 한다.
        if(thispartint[1] + limits > 12){
            thispartint[0] += (thispartint[1] + limits) / 12;
            thispartint[1] = (thispartint[1] + limits) % 12;
            if(thispartint[1] == 0){ // 예외처리: 12월에서 12를 더하면 24가 되므로 1년을 따로 빼준 뒤 0을 12로 고쳐야 한다.
                thispartint[0]--;
                thispartint[1] = 12;
            }
        } else {
            thispartint[1] += limits;
        }
                        
        bool flag = false;
        if(todaypartint[0] > thispartint[0]){ // 2022 > 2021
            flag = true;
        } else if(todaypartint[0] == thispartint[0]){ 
            if(todaypartint[1] > thispartint[1]){ // 2022.7 > 2022.6
                flag = true;
            } else if(todaypartint[1] == thispartint[1]){
                if(todaypartint[2] >= thispartint[2]){ // 2022.7.19 > 2022.6.18
                    flag = true;
                }
            }
        }
        if(flag) answer.push_back(a);
    }
    return answer;
}