#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
vector<pair<int, int> > v; // 바이러스 배치 후보 명단
int map[51][51]; // 사용될 배열
int origin[51][51]; // 원본 배열
bool visited[51][51]; // 방문 여부
vector<pair<int, int> > vv; // 선택한 바이러스 위치
bool visit_v[11]; // 바이러스 위치 선택 여부
int ans = 999;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(vector<pair<int, int> > pos){
    queue<pair<int, int> > q;
    int cnt = 0;
    for(int i=0; i<pos.size(); i++){ // 최초 바이러스 위치 방문처리하고 큐에 담기
        q.push(make_pair(pos[i].first, pos[i].second));
        visited[pos[i].first][pos[i].second] = true;
    }

    while(!q.empty()){ // BFS
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        if(map[x][y] > cnt){ // 가장 큰 맵의 숫자 -> 마지막으로 전염시킨 위치가 된다.
            cnt = map[x][y];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || map[nx][ny] == -1) continue;
            if(!visited[nx][ny] && map[nx][ny] == 0){
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0 && !visited[i][j]){ // 실패 조건
                return -1;
            }
        }
    }
    return cnt;
}

void copys(){ // 원본 배열로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = origin[i][j];
        }
    }
}

void DFS(int idx, int cnt){
    if(cnt == m){ // m개 선택했다면
        memset(visited, false, sizeof(visited));
        copys(); // 각 선택의 경우마다 맵과 방문여부를 초기화해야한다.

        int cnt = BFS(vv);
        if(cnt != -1){ // -1이면 실패이므로 배제한다.
            ans = min(ans, cnt);
        }
        return;
    }

    for(int i=idx; i<v.size(); i++){ // 백트래킹 방식으로 nCm을 구현한다.
        if(visit_v[i]) continue;
        visit_v[i] = true;
        vv.push_back(v[i]);
        DFS(i + 1, cnt + 1);
        visit_v[i] = false;
        vv.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;  i<n; i++){
        for(int j=0; j<n; j++){
            cin >> origin[i][j];
            if(origin[i][j] == 2){
                origin[i][j] = 0; 
                v.push_back(make_pair(i, j)); // 바이러스 후보군에 담는다.
            } else if(origin[i][j] == 1){
                origin[i][j] = -1;
            }
        }
    }

    DFS(0, 0);

    if(ans == 999) ans = -1;
    cout << ans;
    return 0;
}