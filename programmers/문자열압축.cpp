#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int maxcutsize = s.size()/2;
    
    for(int a=1; a<=maxcutsize; a++){
        int nowlen = s.size();
        int cnt = 0;
        for(int i=0; i<s.size()-a; i+=a){
            string target = s.substr(i, a);
            string next = s.substr(i+a, a);
            if(target == next){
                cnt++;
                nowlen -= a;
            } else {
                if(cnt > 0) nowlen += to_string(cnt+1).size();
                cnt = 0;
            }
        }
        if(cnt > 0) nowlen += to_string(cnt+1).size();
        cnt = 0;
        answer = min(answer, nowlen);
    }
    return answer;
}
