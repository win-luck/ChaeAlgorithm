#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
int map[1000][1000]; // 맵
bool visited[1000][1000][10]; // 맵과 벽 부순 횟수
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
    queue<pair<pair<int, int>, pair<int, int > > > q; // 두 좌표, 최단경로의 길이, 벽부순횟수 
    q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
    visited[0][0][0] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int breaks = q.front().second.second;
        q.pop();

        if(x == n-1 && y == m-1){ // 도착
            cout << cnt << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 초과
            if(!visited[nx][ny][breaks]){ // 아직 이 벽 파괴 횟수로 방문하지 않음
                if(map[nx][ny] == 0){
                    visited[nx][ny][breaks] = true; // 이 벽 파괴 횟수로 방문함
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, breaks)));
                } else {
                    if(breaks < k){ // 깨뜨릴 수 있음
                        visited[nx][ny][breaks+1] = true; // 벽 파괴횟수 추가하여 방문처리
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, breaks + 1)));
                    }
                }
            }
        }
    }
    cout << -1 << '\n'; // 실패
}

void input(){ // 입력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j] - '0';
        }
    }
}

int main(){
    input();
    BFS();
    return 0;
}