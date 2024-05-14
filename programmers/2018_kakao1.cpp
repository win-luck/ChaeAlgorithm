#include <string>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cnt = 0; // 차례
    int score[3]; // 점수
    char special[3]; // 옵션
    string s = ""; // 파싱을 위한 문자열
    
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] == 'S'){
            score[cnt] = stoi(s);
            cnt++;
            s = "";
            continue;
        } else if(dartResult[i] == 'D'){
            score[cnt] = (stoi(s) * stoi(s));
            cnt++;
            s = "";
            continue;
        } else if(dartResult[i] == 'T'){
            score[cnt]= (stoi(s) * stoi(s) * stoi(s));
            cnt++;
            s = "";
            continue;
        } // S, D, T 조건에 따라 stoi로 정수로 변환하여 점수 배열에 추가
        
        if(dartResult[i] == '#'){
            int pos = cnt - 1;
            special[pos] = '#';
            continue;
        } else if(dartResult[i] == '*'){
            int pos = cnt - 1;
            special[pos] = '*';
            continue;
        } // 특수기호 배열에 기호 추가
        s += dartResult[i];
    }
    
    for(int i=0; i<3; i++){ // 점수 계산
        if(special[i] == '#'){
            score[i] = score[i] * -1; // 현재 점수 * -1로 변환
        } else if(special[i] == '*'){
            score[i] = score[i] * 2; // 현재 점수 2배로
            if(i-1 >= 0){
                score[i-1] = score[i-1] * 2; // 직전 점수 2배로
            }
        }
    }

    answer += score[0] + score[1] + score[2];
    return answer;
}