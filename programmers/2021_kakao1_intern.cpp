#include <string>
#include <vector>
#include <map>
#include <algorithm>

// 19분 16초

using namespace std;

int solution(string s) {
    int answer = 0;
    string answerList = "";
    map<string, char> m;
    
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(m.count(tmp) >= 1){ // 숫자랑 매칭되는 문자열 발견
            answerList += m[tmp];
            tmp = "";
        }
        
        if(s[i] >= '0' && s[i] <= '9') answerList += s[i];
        else tmp += s[i];
    }
    
    if(m.count(tmp) >= 1){ // 마지막 부분이 문자열인 경우
        answerList += m[tmp];
    }
    
    answer = stoi(answerList);    
    return answer;
}