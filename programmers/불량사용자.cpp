#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
set<string> cases;

bool check(string s1, string s2){ // 두 문자열 매칭
    if(s1.size() != s2.size()) return false;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] == s2[i] || s2[i] == '*') continue;
        else return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    sort(user_id.begin(), user_id.end());
    
    do {
        bool flag = false;
        vector<string> v;
        for(int i=0; i<banned_id.size(); i++){
            if(!check(user_id[i], banned_id[i])){
                flag = true;
                break;
            } else {
                v.push_back(user_id[i]);
            }
        }
        if(flag) continue;
        
        string tmp = "";
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            tmp += v[i];
        }
        cases.insert(tmp);
    } while (next_permutation(user_id.begin(), user_id.end()));
    answer = cases.size();
    return answer;
}
