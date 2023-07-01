#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int todaypartint[3];
    int cnt = 0;
    string s = "";

    for(int i=0; i<today.size(); i++){
        if(today[i] == '.'){
            todaypartint[cnt] = stoi(s); // 추출한 문자열 정수로 변환
            cnt++;
            s = "";
            continue;
        }
        s += today[i];
    }
    todaypartint[cnt] = stoi(s);
    cnt = 0;
    s = "";
    // todaypart[0]은 년도, [1]은 월, [2]는 일
    
    for(int a=1; a<=privacies.size(); a++){
        int limits = 0;
        for(int j=0; j<terms.size(); j++){
            if(terms[j].front() == privacies[a-1].back()){ // privacies 배열의 한 원소의 마지막 글자는 terms 배열의 한 원소의 첫글자와 동일
                string t = terms[j];
                for(int b=0; b<terms[j].size(); b++){
                    if(t[b] == ' '){ // ' ' 다음에 유효기간이 등장한다.
                        t = t.substr(b+1, 3); // 유효기간은 최대 3자리이므로 
                        break;
                    }
                }
                limits = stoi(t); // 추출한 유효기간 문자열 정수로 변환
                break;
            }
        } // 이 개인정보의 종류를 결정하고 유효기간을 추출
        
        int thispartint[3];
        string now = privacies[a-1];
        for(int k=0; k<now.size(); k++){
            if(now[k] == '.'){
                thispartint[cnt] = stoi(s);
                cnt++;
                s = "";
                continue;
            }
            if(now[k] == ' '){
                thispartint[cnt] = stoi(s);
                cnt++;
                s = "";
                break;
            }
            s += now[k];
        } // 이 개인정보의 연, 월, 일을 today와 유사하게 추출
        cnt = 0;
        s = "";

        // 이제 특정 개인정보와 오늘과의 날짜 차이를 검증한다.
        // 특정 개인정보 + limits가 오늘보다 작을 경우 이를 포함해야 한다.
        if(thispartint[1] + limits > 12){
            thispartint[0] += (thispartint[1] + limits) / 12;
            thispartint[1] = (thispartint[1] + limits) % 12;
            if(thispartint[1] == 0){ // 예외처리: 12월인 상태에서 limits가 12면 24가 되는데, 이 경우 2년이 증가하므로 하나 깎아준다.
                thispartint[0]--;
                thispartint[1] = 12;
            }
        } else {
            thispartint[1] += limits;
        }
                        
        bool flag = false;
        if(todaypartint[0] > thispartint[0]){ // 2023 > 2022
            flag = true;
        } else if(todaypartint[0] == thispartint[0]){ 
            if(todaypartint[1] > thispartint[1]){ // 2023.07 > 2023.06
                flag = true;
            } else if(todaypartint[1] == thispartint[1]){
                if(todaypartint[2] >= thispartint[2]){ // 2023.07.20 > 2023.07.18
                    flag = true;
                }
            }
        }
        
        if(flag) answer.push_back(a); // 조건 성립시 벡터에 담음
    }
    return answer;
}