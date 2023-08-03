#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
int n, L, R;
bool visited[51][51];
int map[51][51];
int sum = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > v;

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    sum = map[sx][sy];
    q.push(make_pair(sx, sy));
    v.push_back(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(abs(map[nx][ny] - map[x][y]) >= L && abs(map[nx][ny] - map[x][y]) <= R){ // L 이상 R 이하
                visited[nx][ny] = true;
                v.push_back(make_pair(nx, ny));
                q.push(make_pair(nx, ny));
                sum += map[nx][ny];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    cin >> n >> L >> R;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    } // 입력

    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    BFS(i, j);
                }

                if(v.size() >= 2){ // 연합이 존재
                    flag = true;
                    int val = sum / v.size();
                    for(int a=0; a<v.size(); a++){
                        map[v[a].first][v[a].second] = val;
                    }
                }
            }
        }

        if(flag) answer++;
        memset(visited, false, sizeof(visited));
    }
    cout << answer << '\n';
    return 0;
}