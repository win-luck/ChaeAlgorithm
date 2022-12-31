#include <iostream>
#include <queue>

using namespace std;
int visited[1000][1000][2]; // 최단거리 저장
int row, col;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(vector<string> map){
    queue<pair<pair<int,int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 1)); // 맵의 왼쪽 위에서, 오른쪽 아래로 움직인다.
    visited[0][0][1] = 1;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int breakflag = q.front().second; // "벽 1회 파괴권을 가지고 있음"을 의미함.
        q.pop();

        if(r == row-1 && c == col-1){ // 도착
            return visited[r][c][breakflag];
        }
        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                // 벽을 뚫을 수 있을 때와 벽 없이 단순히 길을 지날 때를 한꺼번에 판단하여 계산한다.
                if(map[nr][nc] == '0' && visited[nr][nc][breakflag] == 0){ // 단순히 아직 가지 않은 길을 지날 때
                    q.push(make_pair(make_pair(nr, nc), breakflag));
                    visited[nr][nc][breakflag] = visited[r][c][breakflag] + 1;
                } else if(map[nr][nc] == '1' && breakflag == 1){ // 벽이 있고 깰 수 있을 때
                    q.push(make_pair(make_pair(nr, nc), breakflag-1)); // 한번 깨버렸으므로 flag는 0이 됨.
                    visited[nr][nc][breakflag-1] = visited[r][c][breakflag] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;
    vector<string> map(row);
    for (int i = 0; i < row; i++) {
        cin >> map[i];
    } // 입력

    cout << BFS(map);
    return 0;
}