#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int, int> > v(n, make_pair(0, 0));
    bool flag = true;
    for(int i=0; i<n; i++){
        cin >> v[i].first;
    }
    for(int i=0; i<n-1; i++){
        cin >> v[i].second;
        v[i].second += v[i].first;
    }
    v[n-1].second = v[n-1].first;
    sort(v.begin(), v.end());
    int l = v[0].first;
    int r = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].first > r){
            flag = false;
            break;
        } else {
            r = max(v[i].second, r);
        }
    }
    if(flag){
        cout << "권병장님, 중대장님이 찾으십니다\n";
    } else {
        cout << "엄마 나 전역 늦어질 것 같아\n";
    }
    return 0;
}
