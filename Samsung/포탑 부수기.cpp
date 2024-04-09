#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n, m, k;
int map[11][11];
pair<int, int> visited[11][11];
bool fight[11][11];
int lastattacktime[11][11] = {0,};
int answer = 0;
pair<int, int> now, target;
vector<pair<pair<int, int>, pair<int, int>>> v;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1}; // 우하좌상
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

bool cmp(pair<pair<int, int>, pair<int, int>>& a,  pair<pair<int, int>, pair<int, int>>& b) {
    if(a.second.first==b.second.first) {
        if(a.second.second==b.second.second) {
            if(a.first.first+a.first.second==b.first.first+b.first.second)
                return a.first.second>b.first.second;
            return a.first.first+a.first.second>b.first.first+b.first.second;
        }
        return a.second.second>b.second.second;
    }
    return a.second.first<b.second.first;
}


void select(int nowturn){
    v.clear();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] > 0) 
                v.push_back({{i, j}, {map[i][j], lastattacktime[i][j]}});
        }
    }

    sort(v.begin(), v.end(), cmp);
    now = v[0].first;
    target = v.back().first;
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

void bomb(){
    map[target.first][target.second] -= map[now.first][now.second];
    if(map[target.first][target.second] < 0){
        map[target.first][target.second] = 0;
    }
    fight[now.first][now.second] = true;
    fight[target.first][target.second] = true;
    for(int i=0; i<8; i++){
        int nx = target.first + dx[i];
        int ny = target.second + dy[i];
        if(nx < 0){
            nx += n;
        }
        if(nx >= n){
            nx -= n;
        }
        if(ny < 0){
            ny += m;
        }
        if(ny >= m){
            ny -= m;
        }
        if(nx==now.first && ny==now.second) continue;
        map[nx][ny] -= map[now.first][now.second]/2;
        if(map[nx][ny] < 0) map[nx][ny]=0;
        fight[nx][ny] = true; 
    }
}

bool razor(){
    queue<pair<int, int>> q;
    int sx = now.first;
    int sy = now.second;
    int ex = target.first;
    int ey = target.second;
    q.push({sx, sy});
    visited[sx][sy] = {ex, ey};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == ex && y == ey){ // 도착
            fight[sx][sy] = true;
            fight[ex][ey] = true;
            pair<int, int> p = visited[ex][ey];
            if(p.first == sx && p.second == sy){
                map[ex][ey] -= map[sx][sy];
                if(map[ex][ey] < 0 ) map[ex][ey] = 0;
                return true;
            }
            while(1){
                if(p.first == sx && p.second == sy){
                    break;
                }
                fight[p.first][p.second] = true;
                map[p.first][p.second] -= map[now.first][now.second]/2;
                p = visited[p.first][p.second];
            }
            map[ex][ey] -= map[sx][sy];
            if(map[ex][ey] < 0) map[ex][ey] = 0;
            return true;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0){
                nx += n;
            }
            if(nx >= n){
                nx -= n;
            }
            if(ny < 0){
                ny += m;
            }
            if(ny >= m){
                ny -= m;
            }

            if(visited[nx][ny] != make_pair(-1, -1) || map[nx][ny] <= 0) continue;
            visited[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }
    return false;
}

// 공격과 무관했던 포탑은 공격력 1씩 증가
void healturret(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!fight[i][j] && map[i][j] > 0){
                map[i][j] += 1;
            }
        }
    }
    //print();
}

void attack(){
    if(!razor()){
        bomb();
    }
    healturret();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                v.push_back({{i, j}, {map[i][j], 0}});
            }
        }
    }

    for(int i=1; i<=k; i++){
        for(int j=0; j<n; j++){
            for(int a=0; a<m; a++){
                visited[j][a] = {-1, -1};
            }
        }
        memset(fight, false, sizeof(fight));
        select(i);
        lastattacktime[now.first][now.second] = i;
        map[now.first][now.second] += (n+m);
        attack();

        int cnt = 0;
        for(int j=0; j<n; j++){
            for(int a=0; a<m; a++){
                if(map[j][a] > 0) cnt++;
            }
        }
        if(cnt == 1) break;
    }
    // 남아있는 포탑 중 가장 강한 포탑의 공격력 출력
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer = max(answer, map[i][j]);
        }
    }
    cout << answer;
    return 0;
}
