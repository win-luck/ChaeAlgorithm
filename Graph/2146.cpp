#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n;
int visited[101][101];
int map[101][101];
int mapcnt = 2;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 100000;

void BFS(int sx, int sy){ // 섬에 숫자를 부여한다.
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 이탈
            if(map[nx][ny] == 0) continue; // 물인 경우
            if(!visited[nx][ny]){
                map[nx][ny] = mapcnt;
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int bridgemake(int num){ // 다리를 만든다.
    queue<pair<pair<int, int>, int> > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == num){
                visited[i][j] = 1;
                q.push(make_pair(make_pair(i, j), 0)); // 섬의 모든 땅을 큐에 담음
            }
        }
    }
    
    while(!q.empty()){ // 섬을 찾는 것은 단순 BFS로 불가능하다(다른 곳에서 출발하는 게 더 유리한 경우를 찾지 못한다)
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second; // 최단거리임을 증명할 정보인 이동 횟수를 저장한다.
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 이탈
            if(map[nx][ny] != 0 && map[nx][ny] != num) return cnt; // 다른 섬 도착
            if(map[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), cnt + 1));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n; // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){ // 각 섬에 번호를 부여한다.
        for(int j=0; j<n; j++){
            if(map[i][j] != 0 && !visited[i][j]){
                map[i][j] = mapcnt;
                BFS(i, j); 
                mapcnt++;
            }
        }
    }

    // 두 육지를 연결하는 가장 짧은 다리를 찾는다.
    memset(visited, 0, sizeof(visited));
    for(int i=2; i<mapcnt; i++){
        answer = min(answer, bridgemake(i)); // i번째 섬에서 다른 섬으로 출발
        memset(visited, 0, sizeof(visited));
    }

    cout << answer << '\n';
    return 0;
}