#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int copys[401][401]; // 복사본
int map[401][401]; // -2는 공백, -1은 검정, 0은 무지개
bool visited[401][401];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input(){ // 입력
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
}

void makecopy(){ // 복사본 배열 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            copys[i][j] = map[i][j];
        }
    }
}

bool cmp(pair<pair<int, int>, pair<int, int> > p1, pair<pair<int, int>, pair<int, int> > p2){ // 문제 요구에 따른 정렬
    if(p1.first.first == p2.first.first){
        if(p1.first.second == p2.first.second){
            if(p1.second.first == p2.second.first){
                return p1.second.second > p2.second.second;
            }
            return p1.second.first > p2.second.first;
        }
        return p1.first.second > p2.first.second;
    }
    return p1.first.first > p2.first.first;
}

pair<int, int> bfs(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));
    int cnt = 1;
    int rainbow = 0;
    int color = map[sx][sy];

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] || map[nx][ny] == -1) continue;
            if(map[nx][ny] == 0 || map[nx][ny] == color){
                if(map[nx][ny] == 0) rainbow++;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return make_pair(cnt, rainbow); // 그룹 크기, 무지개 개수
}

int deleteblock(int sx, int sy){
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));
    int cnt = 1;
    int color = map[sx][sy];
    copys[sx][sy] = -2; // 빈 블록

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] || map[nx][ny] == -1) continue;
            if(map[nx][ny] == 0 || map[nx][ny] == color){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                copys[nx][ny] = -2;
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = copys[i][j]; // 빈 블록 업데이트
        }
    }
    return cnt*cnt;
}

void gravity(){ // 중력
    for(int j=0; j<n; j++){
        int nextf = n-1; // 바닥
        for(int i=n-1; i>=0; i--){
            if(map[i][j] == -2) {
                continue;
            } else if(map[i][j] == -1){
                nextf = i;
                while(map[nextf][j] != -2) {
                    nextf--;
                    if(nextf < 0){
                        i = -1;
                        break;
                    }
                }
                i = nextf;
            } else {
                swap(map[nextf][j], map[i][j]);
                nextf--;
            }
        }
    }
}

void rotate(){ // 90도 반시계 회전
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            copys[i][j] = map[j][n-1-i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = copys[i][j];
        }
    }
}

void zeroreset(){ // 무지개 블록은 모든 그룹들이 쓸 수 있어야 하므로 매 탐색마다 초기화해줘야함
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] && map[i][j] == 0) visited[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    int answer = 0;
    while(1){
        memset(visited, false, sizeof(visited));
        makecopy();
        vector<pair<pair<int, int>, pair<int, int> > > v;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && map[i][j] >= 1){
                    pair<int, int> blocks = bfs(i, j);
                    v.push_back(make_pair(blocks, make_pair(i, j)));
                    zeroreset();
                }
            }
        }
        if(v.empty()) break; // 비었으면 종료
        sort(v.begin(), v.end(), cmp);
        if(v[0].first.first < 2) break; // 젤 큰 그룹 크기가 2 미만이면 종료
        answer += deleteblock(v[0].second.first, v[0].second.second);
        gravity(); // 중력
        rotate(); // 90도 반시계 회전
        gravity(); // 중력
    }
    cout << answer;
    return 0;
}
