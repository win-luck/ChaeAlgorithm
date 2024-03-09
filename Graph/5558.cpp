#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int h, w, n, sx, sy;
char map[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer = 0;
vector<pair<int, int> > v; // 1~n번 위치

void cheese(int idx){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(sx, sy)));
    visited[sx][sy] = true;

    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(v[idx].first == x && v[idx].second == y){
            answer += cnt;
            sx = x;
            sy = y;
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || map[nx][ny] == 'X') continue;
            q.push(make_pair(cnt+1, make_pair(nx, ny)));
            visited[nx][ny] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w >> n;
    v.resize(12);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j];
            if(map[i][j] >= '1' && map[i][j] <= '9'){
                v[map[i][j] - '0'] = make_pair(i, j);
            }
            if(map[i][j] == 'S'){
                sx = i;
                sy = j;
                map[i][j] = '.';
            }
        }
    }
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        cheese(i); // 1부터 n번 치즈까지 순차적으로!
    }
    cout << answer;
    return 0;
}
