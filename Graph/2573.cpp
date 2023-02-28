#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int map[301][301];
int melt[301][301];
bool visited[301][301];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy)); // r와 c
    visited[sx][sy] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(!visited[nr][nc] && map[nr][nc] > 0){
                q.push(make_pair(nr, nc));
                visited[nr][nc] = true;
            }
        }
    }
} // 빙산 한 덩어리 BFS

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
} // 입력

int main(){
    input();
    int cnt = 0;

    while(1){
        // 전반적인 로직의 흐름: BFS로 빙산 개수 판정 -> 분리 및 완전녹음 판정 -> 브루트포스로 모든 빙산 순회하며 녹일 양 저장 -> 녹이기 -> 반복
        // 깔끔한 판정이 필요하다. 한 함수에 너무 많은 역할을 우겨넣으려고, 즉 한번에 다 처리하려고 한 게 문제의 원인이었던 것. 
        // 로직의 흐름대로 역할을 분리하는 것이 중요하다는 결론
        
        memset(visited, false, sizeof(visited));
        memset(melt, 0, sizeof(melt)); // 매 웨이브마다 초기화

        int icecnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] > 0 && !visited[i][j]){
                    icecnt++;
                    BFS(i, j);
                }
            }
        } // BFS로 빙산 개수와 크기 파악
        
        if(icecnt >= 2){ // 빙산의 분리가 발생
            break;
        }else if(icecnt == 0){ // 모든 빙산이 녹아버린 경우
            cnt = 0;
            break;
        }     

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] > 0){ // 빙산이 존재하는 경우에
                    for(int a=0; a<4; a++){ // 주변 0의 개수에 따라 녹여야 할 빙산의 양을 저장
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(map[nx][ny] <= 0){
                            melt[i][j]++;
                        }
                    }
                }
            }
        }

        for(int i=0; i<n; i++){ // 녹이기
            for(int j=0; j<m; j++){
                map[i][j] -= melt[i][j];
            }
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}