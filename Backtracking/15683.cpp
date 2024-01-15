#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
int map[9][9];
int tmp[9][9];
int totalzero = 0;
int answer = 0;
vector<pair<int, int> > pos;
vector<int> dir;
int dx[4] = {0, -1, 0, 1}; // 우상좌하 반시계
int dy[4] = {1, 0, -1, 0};

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = map[i][j];
        }
    }
}

int draw(int x, int y, int dir){
    int cnt = 0;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m || tmp[nx][ny] == 6) 
            break;
        if(tmp[nx][ny] == 0){
            tmp[nx][ny] = -1;
        }
        x = nx;
        y = ny;
    }
    return cnt;
}

int activate(int dir, int type, pair<int, int> pos){
    int cnt = 0;
    int x = pos.first;
    int y = pos.second;
    if(type == 1){
        cnt += draw(x, y, dir);
    } else if(type == 2){
        cnt += draw(x, y, dir);
        cnt += draw(x, y, (dir+2)%4);
    } else if(type == 3){
        cnt += draw(x, y, dir);
        cnt += draw(x, y, (dir+1)%4);
    } else if(type == 4){
        cnt += draw(x, y, dir);
        cnt += draw(x, y, (dir+1)%4);
        cnt += draw(x, y, (dir+2)%4);
    } else {
        cnt += draw(x, y, dir);
        cnt += draw(x, y, (dir+1)%4);
        cnt += draw(x, y, (dir+2)%4);
        cnt += draw(x, y, (dir+3)%4);
    }
    return cnt;
}

void bfs(){
    copy();
    for(int i=0; i<pos.size(); i++){
        int nowdir = dir[i]; // i번째 CCTV의 방향
        int type = map[pos[i].first][pos[i].second]; // CCTV의 성향
        activate(nowdir, type, pos[i]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0){
                cnt++;
            }
        }
    }
    answer = min(answer, cnt);
}

void dfs(int idx, int cnt){
    if(cnt == pos.size()){
        bfs();
        return;
    }

    for(int j=0; j<4; j++){
        dir.push_back(j);
        dfs(idx+1, cnt+1);
        dir.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) totalzero++;
            else if(map[i][j] > 0 && map[i][j] < 6){ // 1부터 5는 CCTV
                pos.push_back(make_pair(i, j));
            }
        }
    }
    answer = totalzero;
    dfs(0, 0);
    cout << answer;
    return 0;
}
