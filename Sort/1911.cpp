#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for(int i=1; i<=N; i++){
        int s, e;
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }
    sort(v.begin(), v.end());

    int nowedge = 0; // 마지막으로 놓은 널빤지의 끝부분
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        int l = v[i].first;
        int r = v[i].second;
        if(nowedge >= r) continue; // 널빤지 안에 포함

        int range = (l < nowedge ? r-nowedge: r-l);
        int nowcnt = (range / L) + (range % L == 0 ? 0 : 1);
        nowedge = (l < nowedge ? nowedge : l) + nowcnt*L;
        cnt += nowcnt;
    }
    cout << cnt;
    return 0;
}

/**
 * 1. 널빤지 다음에 l-r 형태로 웅덩이 존재 -> 넘어감
 * 2. 널빤지 안에 l, 밖에 r 형태로 존재 -> r-nowedge만 커버
 * 3. 널빤지 안에 l, r 둘다 존재 -> 카운트할 가치 없음
*/
