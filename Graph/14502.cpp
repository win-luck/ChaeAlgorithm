#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[8][8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, result;

void BFS(){
    queue<pair<int,int> > q;
    int count = 0;
    int copys[8][8] = { 0, };
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copys[i][j] = map[i][j];
        }
    } // 배열 복사 과정

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(copys[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    } // 바이러스 진원지 저장

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nc >= 0 && nr < N && nc < M){
                if(copys[nr][nc] == 0){
                    q.push(make_pair(nr, nc));
                    copys[nr][nc] = 2;
                }
            }
        }
    } // 0을 2로 전염시키는 과정, visited가 필요 없음. (2로 바뀐 상황이 곧 visited이므로)

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(copys[i][j] == 0){
                count++;
            }
        }
    } // 살아남은 0의 개수 = 안전지역
    result = max(result, count);
}

void setWall(int count){
    if(count == 3){ // 백트래킹, 3개의 벽을 모두 세웠다면, 세워진 맵 기준으로 BFS 돌입
        BFS();
        return;
    }
    for(int i=0; i<N; i++){ // 하나씩 벽을 세우고 count + 1
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                setWall(count+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    } // 입력

    result = 0;
    setWall(0);

    cout << result;
    return 0;
}

