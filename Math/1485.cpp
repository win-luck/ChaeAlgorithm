#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;
vector<pair<long long, long long> > v;
long long dist[4][4];

long long getDist(pair<long long, long long> p1, pair<long long, long long> p2){
    return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        v.resize(4);
        for(int i=0; i<4; i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                dist[i][j] = getDist(v[i], v[j]);
            }
        }
        if(dist[0][1] == dist[0][2] && dist[3][1] == dist[3][2] && dist[1][2] == dist[0][3] && dist[0][1] == dist[3][1]){
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
