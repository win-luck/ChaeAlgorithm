#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, s, fx, fy; // 1~k번 바이러스까지 존재할 수 있음
bool visited[201][201];
int map[201][201];
queue<pair<int, pair<int, int> > > q; // 좌표를 담을 큐
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
    while(!q.empty()){
        int t = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        if(x == fx-1 && y == fy-1 && t <= s){ // 시간 이내에 도착
            cout << map[fx-1][fy-1] << '\n';
            return;
        }

        if(map[x][y] == 0) continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            map[nx][ny] = map[x][y];
            q.push(make_pair(t+1, make_pair(nx, ny)));
        }
    }
    cout << 0 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<pair<int, pair<int, int> > > v;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                v.push_back(make_pair(map[i][j], make_pair(i, j)));
            }
        }
    }

    cin >> s >> fx >> fy;
    sort(v.begin(), v.end()); // 바이러스 위치를 낮은 번호, 빠른 좌표 순으로 정렬
    for(int i=0; i<v.size(); i++){
        q.push(make_pair(0, make_pair(v[i].second.first, v[i].second.second)));
        visited[v[i].second.first][v[i].second.second] = true;
    }
    BFS();
    return 0;
}