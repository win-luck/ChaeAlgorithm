#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int answer = 0;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int start = 600; // 오전 10시
    int end = 1320; // 오후 10시
    for(int i=1; i<=n; i++){
        string a, b;
        cin >> a >> b;
        int t1 = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(2, 2)) - 10;
        int t2 = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(2, 2)) + 10;
        v.push_back(make_pair(t1, t2));
    }
    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;
    answer = max(answer, l-start);
    for(int i=1; i<n; i++){
        if(v[i].first > r){
            answer = max(answer, v[i].first-r);
            l = v[i].first;
            r = v[i].second;
        } else {
            r = max(r, v[i].second);
        }
    }
    answer = max(answer, end-r);
    cout << answer;
    return 0;
}
