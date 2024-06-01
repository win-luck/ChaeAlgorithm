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
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;
    vector<pair<int, int> > tmp;
    for(int i=1; i<n; i++){
        if(v[i].first <= r){
            r = max(v[i].second, r);
        } else {
            tmp.push_back(make_pair(l, r));
            l = v[i].first;
            r = v[i].second;
        }
    }
    tmp.push_back(make_pair(l, r));

    int answer = 0;
    int len = 0;
    for(int i=0; i<tmp.size(); i++){
        if(tmp[i].first > len){
            break;
        } else {
            len = max(len, tmp[i].second + (tmp[i].second - tmp[i].first));
            answer = tmp[i].second;
        }
    }
    cout << answer;
    return 0;
}
