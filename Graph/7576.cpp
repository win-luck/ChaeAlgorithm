#include <iostream>
#include <queue>

using namespace std;
int map[1001][1001];
int m, n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int> > q;

void input(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
}

bool validcheck(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}

void BFS(){
    int total = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        total = cnt;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0){
                map[nx][ny] = 1;
                q.push(make_pair(make_pair(nx, ny), total + 1));
            }
        }
    }
    if(validcheck()){
        cout << total;
    } else {
        cout << -1;
    }
}

int main(){
    input();
    BFS();
    return 0;
}