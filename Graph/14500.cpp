#include <iostream>
#include <queue>

using namespace std;

int map[500][500];
bool visited[500][500];
int N, M, result;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void specialshape(int r, int c){ // ㅗ 형태는 DFS로 커버할 수가 없으므로 별도로 분리해서 직접 구한다.
    // ㅗ
    if(c+2 < M && r-1 >= 0){
        result = max(result, map[r][c] + map[r][c+1] + map[r][c+2] + map[r-1][c+1]);
    }
    // ㅓ
    if(c+1 < M && r-1 >= 0 && r+1 < N){
        result = max(result, map[r][c] + map[r+1][c+1] + map[r-1][c+1] + map[r][c+1]);
    }
    // ㅜ
    if(c+2 < M && r+1 < N){
        result = max(result, map[r][c] + map[r][c+1] + map[r][c+2] + map[r+1][c+1]);
    }
    // ㅏ
    if(r+1 < N && r-1 >= 0 && c+1 < M){
        result = max(result, map[r][c] + map[r][c+1] + map[r-1][c] + map[r+1][c]);
    }
}

void normalshape(int count, int sum, int row, int col){ // 나머지는 DFS로 4칸까지 순회한 합 중 최댓값을 계산하는 방식으로 볼 수 있다.
    if(count == 3){ // 백트래킹, count가 3일 때는, 총 4개의 좌표값을 더한 상황이므로, 이 상황에서 최댓값을 갱신 시도한 뒤 종료한다.
        result = max(result, sum);
        return;
    }
    for(int i=0; i<4; i++){
        int x = col + dx[i];
        int y = row + dy[i];
        if(visited[y][x])
            continue;
        if(y < 0 || y >= N || x < 0 || x >= M)
            continue;
        visited[y][x] = true;
        normalshape(count + 1, sum + map[y][x], y, x);
        visited[y][x] = false;
    }
}

void findanswer(int r, int c){
    specialshape(r, c);

    visited[r][c] = true;
    normalshape(0, map[r][c], r, c);
    visited[r][c] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    // 입력과정
    
    result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            findanswer(i, j);
    // 모든 좌표를 하나씩 순회하며 그 좌표 기준 최댓값을 찾아나선다.
    // 행과 열은 좌표평면으로 생각해서 x-y좌표가 아니라, y-x좌표다.. 시간 오지게 잡아먹은 실수..

    cout << result << '\n';
    return 0;
}