#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, cnt, a;
map<int, pair<int, int> > m; // 학생번호 - <추천횟수, 진입시점>

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    if(p1.second.first == p2.second.first){
        return p1.second.second < p2.second.second;
    }
    return p1.second.first < p2.second.first;
}

void remove(){
    vector<pair<int, pair<int, int> > > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    m.erase(v[0].first);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> cnt;
    for(int i=1; i<=cnt; i++){
        cin >> a;
        if(m.find(a) == m.end()){ // 해당 학생이 사진틀에 없음
            if(m.size() == n){ // 비어있는 사진틀이 없음
                remove(); // 특정 학생 삭제
            } 
            m[a] = make_pair(1, i);
        } else { // 현재 사진틀에 있는데 추천을 받는 경우 횟수만 증가
            m[a].first++;
        }
    }
    for(auto it: m){
        cout << it.first << " ";
    }
    return 0;
}
