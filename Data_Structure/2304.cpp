#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
long long x, y, result = 0;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    int maxidx = -1;
    int maxval = 0;
    for(int i=0; i<n; i++){
        if(v[i].second > maxval){
            maxval = v[i].second;
            maxidx = i;
        }
    }

    result += maxval;
    // 문제에서 오목한 부분은 존재하지 않는다. 즉 산 형태로 올라갔다 내려가는 형태만 존재한다.
    // 가장 높은 정상 기준으로 양 쪽의 높이를 따로 구한다.

    x = v[0].first;
    y = v[0].second;
    for(int i=1; i<=maxidx; i++){
        if(v[i].second >= y){
            result += y * (v[i].first - x);
            y = v[i].second;
            x = v[i].first;
        }
    }

    x = v.back().first;
    y = v.back().second;
    for(int i=n-2; i>=maxidx; i--){
        if(v[i].second >= y){
            result += y * (x - v[i].first);
            y = v[i].second;
            x = v[i].first;
        }
    }
    cout << result;
    return 0;
}
