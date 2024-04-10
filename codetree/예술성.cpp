#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 901
using namespace std;
int n;
int map[MAX][MAX];
int tmp[MAX][MAX];
int visited[MAX][MAX];
int area[MAX][MAX];
int harmony[MAX][MAX];
int answer = 0;
pair<int, int> teaminfo[MAX];
vector<pair<int, int>> team[MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

void cross(int x, int y){
    int arr[MAX] = {0,};
    for(int i=0; i<x; i++){
        arr[i] = map[x][y+i+1]; // 우측 세이프
    }
    // 아래에서 우측으로
    for(int i=0; i<x; i++){
        map[x][y+i+1] = map[x+i+1][y];
    }

    // 좌측에서 아래로
    for(int i=0; i<x; i++){
        map[x+i+1][y] = map[x][y-(i+1)];
    }

    // 위에서 좌측으로
    for(int i=0; i<x; i++){
        map[x][y-(i+1)] = map[x-(i+1)][y];
    }

    // 우측에서 위로
    for(int i=x-1; i>=0; i--){
        map[i][y] = arr[(x-1)-i];
    }
}

void rotate_square(int y1, int x1) {
	int mid = n/2;
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < mid; j++) 
            tmp[y1 + j][x1 + mid - i - 1] = map[y1 + i][x1 + j];
	}
}

void rotate(){
    // 십자가 반시계 회전
    cross(n/2, n/2);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = map[i][j];
        }
    }

    // 4개 영역은 각각 시계 (내부 포함)
    int mid = n/2;
    rotate_square(0, 0); // 좌상
    rotate_square(0, mid + 1); // 우상
    rotate_square(mid + 1, 0); // 좌하
    rotate_square(mid + 1, mid + 1); // 우하

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = tmp[i][j];
        }
    }
}

pair<int,int> bfs(int now, int sx, int sy){
    int val = map[sx][sy];
    queue<pair<int,int>> q;
    int cnt = 1;
    visited[sx][sy] = now;
    team[now].push_back({sx, sy});
    q.push({sx, sy});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if(map[nx][ny] == val){
                visited[nx][ny] = now;
                q.push({nx, ny});
                team[now].push_back({nx, ny});
                cnt++;
            }
        }
    }
    return {val, cnt};
}

void find(int a, int b){
    // 팀 a 기준으로 순회하며 b과 맞닿은 부분 세기
    for(int i=0; i<team[a].size(); i++){
        int x = team[a][i].first;
        int y = team[a][i].second;

        for(int j=0; j<4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] == b){
                area[a][b]++;
            }
        }
    }
}

int getscore(){
    int sum = 0;
    memset(visited, false, sizeof(visited));
    memset(area, false, sizeof(area));
    memset(harmony, false, sizeof(harmony));
    for(int i=0; i<MAX; i++){
        team[i].clear();
    }

    // 각 팀별 크기 및 팀 구성요소 저장
    int now = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                teaminfo[now] = bfs(now, i, j);
                now++;
            }
        }
    }
    
    // 조화 계산
    for(int i=1; i<now; i++){
        for(int j=i+1; j<now; j++){
            find(i, j);
            harmony[i][j] = (teaminfo[i].second + teaminfo[j].second) * (area[i][j]) * (teaminfo[i].first) * (teaminfo[j].first);
            if(harmony[i][j] > 0) {
                sum += harmony[i][j];
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    answer += getscore();
    for(int i=0; i<3; i++){
        rotate();
        answer += getscore();
    }
    cout << answer;
    return 0;
}
