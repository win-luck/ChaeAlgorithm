#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<pair<double, int> > v;

bool cmp(pair<double, int> p1, pair<double, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w, h;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w >> h;
        double ppi = sqrt(w*w + h*h) / 77.0;
        v.push_back(make_pair(ppi, i));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout << v[i].second << '\n';
    }
    return 0;
}
