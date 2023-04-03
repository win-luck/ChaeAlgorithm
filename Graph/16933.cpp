#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
int map[1000][1000];
bool visited[1000][1000][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct status { // 두 좌표, 경로의 개수, 벽 부순 횟수, 낮/밤 여부를 저장한 구조체
    int x;
    int y;
    int cnt;
    int wall;
    bool day;
    status(int a, int b, int c, int d, bool e){ // 생성자
        x = a;
        y = b;
        cnt = c;
        wall = d;
        day = e;
    }
};

void BFS(){
    queue<status> q;
    q.push(status(0, 0, 1, 0, true)); // 최초에는 (0,0)에서, 경로 1개이며, 벽은 0개 부수었고, 낮인 상태
    visited[0][0][0] = true; // (0, 0)을 벽을 0개 부순 상태로 방문처리

    while(!q.empty()){
        status now = q.front();
        q.pop();

        if(now.x == n - 1 && now.y == m - 1){ // 도착했으면 경로 개수 출력
            cout << now.cnt << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 이탈 방지
            if(map[nx][ny] == 0 && !visited[nx][ny][now.wall]){ // 벽이 아니고 아직 안 갔다면 방문처리
                visited[nx][ny][now.wall] = true;
                if(now.day){ // 현재 낮이면 내일 밤으로 갱신
                    q.push(status(nx, ny, now.cnt + 1, now.wall, false));
                } else { 
                    q.push(status(nx, ny, now.cnt + 1, now.wall, true));
                }       
            } else if(map[nx][ny] == 1 && now.wall < k){ // 벽이면서 부술 수 있다면
                if(!visited[nx][ny][now.wall + 1]){ // 아직 안 부쉈을 때 
                    if(!now.day){ // 밤에는 벽을 부술 수 없기에 원래 좌표에서 하루 기다린다.
                        q.push(status(now.x, now.y, now.cnt + 1, now.wall, true));
                    } else { // 낮이면 부수고 지나간다.
                            visited[nx][ny][now.wall + 1] = true;
                            q.push(status(nx, ny, now.cnt + 1, now.wall + 1, false));
                    }
                }
            }
        }
    }   
    cout << -1 << '\n'; // 실패
}

void input(){
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