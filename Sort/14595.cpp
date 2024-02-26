#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;
    if(m == 0){
        cout << n;
        return 0;
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    if(m == 1){
        cout << n - (v[0].second-v[0].first);
        return 0;
    }
    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;
    int cnt = 1;
    if(l > 1){
        cnt += l-1;
    }
    for(int i=1; i<v.size(); i++){
        if(v[i].first > r){
            cnt += (v[i].first-r);
            l = v[i].first;
            r = v[i].second;
        } else {
            r = max(v[i].second, r);
        }
    }
    if(r < n){
        cnt += (n-r);
    }
    cout << cnt;
    return 0;
}
