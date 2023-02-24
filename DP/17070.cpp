#include <iostream>

using namespace std;
int map[17][17];
int n, result;
int dr[3] = {0, 1, 1}; // 파이프는 가로, 세로, 혹은 대각선 아래로만 움직인다.
int dc[3] = {1, 0, 1};

bool validcheck(int r, int c){ // 유효성 검사 - 범위 이탈 혹은 벽인 경우 감지
    if(c < 1 || r < 1 || c > n || r > n || map[r][c] == 1) return false;
    return true;
}

void DFS(int r, int c, int dir){ // 결국 또다시 DFS는 백트래킹
    // dir 방향은 가로 1, 세로 0, 대각선 2이다.
    if(r == n && c == n){
        result++;
        return;
    }

    for(int i=0; i<3; i++){
        if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(validcheck(nr, nc) == false) continue;
        if(i == 2 && (map[nr][nc-1] == 1 || map[nr-1][nc] == 1)) continue;
        DFS(nr, nc, i);
    }

}

int main(){
    result = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    DFS(1, 2, 0); // 생각을 조금만 해보면 파이프 뒷부분은 의미가 없음을 알 수 있다. 방향이 중요한 것.
    cout << result << '\n';
    return 0;
}