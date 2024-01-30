#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct fish { // 생선 구조체
    int dis;
    int x;
    int y;
    fish(int d, int a, int b){
        dis = d;
        x = a;
        y = b;
    }
};
int n;
bool flag = true;
pair<int, int> nowpos; // 상어 현재 위치
int nowsize = 2; // 상어 크기
int noweat = 0; // 상어가 레벨업 전까지 먹은 물고기
int map[21][21];
int visited[21][21];
int answer = 0;
vector<fish> fishes;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cmp(fish f1, fish f2){ // 먹을 수 있는 물고기 정렬
    if(f1.dis == f2.dis) {
        if(f1.x == f2.x) {  
            return f1.y < f2.y;
        }
        return f1.x < f2.x;
    }
    return f1.dis < f2.dis;
}

void BFS(int sx, int sy){
    fishes.clear();
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > q;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if(map[nx][ny] > nowsize) continue; // 크기가 큰 물고기 칸을 지나갈 수 없음

            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
            if(map[nx][ny] > 0 && map[nx][ny] < nowsize){ // 먹을 수 있는 물고기
                fishes.push_back(fish(visited[nx][ny]-1, nx, ny));
            }
        }
    }
    if(fishes.empty()) { // 비어있으면 종료
        flag = false;
        return;
    }
    if(fishes.size() >= 2) // 2개 이상이면 정렬
        sort(fishes.begin(), fishes.end(), cmp);
    answer += fishes[0].dis;
    nowpos = make_pair(fishes[0].x, fishes[0].y); // 현재 위치 갱신
    map[fishes[0].x][fishes[0].y] = 0; // 빈 칸이 됨
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                nowpos = make_pair(i, j);
                map[i][j] = 0;
            }
        }
    }

    while(1){
        BFS(nowpos.first, nowpos.second);
        if(!flag) break;

        if(++noweat == nowsize){ // 현재 크기와 같은수만큼 먹었으면 크기 증가
            noweat = 0;
            nowsize++;
        }
    }
    cout << answer;
    return 0;
}
