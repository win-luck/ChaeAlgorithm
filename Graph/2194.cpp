#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[501][501];
bool visited[501][501];
int n, m, a, b, k;
pair<int, int> s;
pair<int, int> e;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool validcheck(int x, int y){ // 범위 이탈 혹은 장애물 존재 여부를 판정
    for(int i=x; i<x+a; i++){
        for(int j=y; j<y+b; j++){
            if(i < 0 || j < 0 || i >= n || j >= m) return false;
            if(map[i][j] == -1) return false;
        }
    }
    return true;
}

void BFS(){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(s.first, s.second)));
    visited[s.first][s.second] = true;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;

        if(x == e.first && y == e.second){ // 도착
            cout << cnt;
            return;
        }

        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(validcheck(nx, ny)){
                visited[nx][ny] = true;
                q.push(make_pair(cnt + 1, make_pair(nx, ny)));
            }
        }
    }
    cout << -1; // 도달 실패
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> a >> b >> k;
    memset(map, 0, sizeof(map));
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        map[x-1][y-1] = -1;
    }

    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    s.first--;
    s.second--;
    e.first--;
    e.second--;

    BFS();
    return 0;
}