#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        int s, e;
        cin >> s >> e;
        v.push_back(make_pair(s, 1));
        v.push_back(make_pair(e, 0));
    }
    sort(v.begin(), v.end());

    int nowcnt = 0;
    int answer = 1;
    for(int i=0; i<v.size(); i++){
        if(v[i].second){ // 시작점
            nowcnt++;
        } else {
            answer = max(answer, nowcnt);
            nowcnt--;
        }
    }
    cout << answer;
    return 0;
}
