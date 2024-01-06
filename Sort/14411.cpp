#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int> > v;
int n;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    
    long long result = 0;
    long long maxY = 0;
    for(int i=0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;

        if(y > maxY){
            result += x * (y - maxY);
            maxY = y;
        }
    }
    cout << result;
    return 0;
}
