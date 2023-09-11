#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int t, n;
int sx, sy;
int ex, ey;
bool visited[101];
vector<pair<int, int> > v;

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    visited[0] = true;
    q.push(make_pair(v[0].first, v[0].second));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        if(x == ex && y == ey){
            cout << "happy\n";
            return;
        }

        q.pop();
        for(int i=0; i<v.size(); i++){
            if(!visited[i]){
                if(abs(x - v[i].first) + abs(y - v[i].second) <= 1000){
                    visited[i] = true;
                    q.push(make_pair(v[i].first, v[i].second));
                }
            }
        }
    }
    cout << "sad\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int q=0; q<t; q++){
        cin >> n;
        cin >> sx >> sy;
        v.clear();
        fill(visited, visited + 101, false);
        
        v.push_back(make_pair(sx, sy));
        for(int i=0; i<n+1; i++){
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        ex = v.back().first;
        ey = v.back().second;
        BFS(sx, sy);
    }
    return 0;
}
