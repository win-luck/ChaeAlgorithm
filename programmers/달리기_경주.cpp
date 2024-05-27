#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m; // 선수-등수
    map<int, string> m2; // 등수-선수
    for(int i=0; i<players.size(); i++){
        m[players[i]] = i+1;
        m2[i+1] = players[i];
    }
    for(int i=0; i<callings.size(); i++){
        int tmp1 = m[callings[i]]; // 현재 이름이 불린 선수의 등수
        string tmp2 = m2[tmp1-1]; // 추월할 선수 이름
        m2[tmp1] = tmp2;
        m2[tmp1-1] = callings[i];
        m[callings[i]] = tmp1-1;
        m[tmp2] = tmp1;
    }
    vector<pair<int, string>> a = vector<pair<int, string>>(m2.begin(), m2.end());
    for(int i=0; i<a.size(); i++){
        answer.push_back(a[i].second);
    }
    return answer;
}
