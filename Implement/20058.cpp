#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int n, q;
int len; // 2^n
int arr[64][64];
bool visited[64][64];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int BFS(int sx, int sy){
    int cnt = 1;
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= len || ny >= len || visited[nx][ny]) continue;
            if(arr[nx][ny] > 0){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

void melt(){
    vector<pair<int, int> > v;
    for(int i=0; i<len; i++){ // 녹일 칸 찾기
        for(int j=0; j<len; j++){
            if(arr[i][j] >= 1){
                int cnt = 0;
                for(int a=0; a<4; a++){
                    int nx = i + dx[a];
                    int ny = j + dy[a];
                    if(nx >= 0 && ny >= 0 && nx < len && ny < len){
                        if(arr[nx][ny] >= 1) cnt++;
                    }
                }
                if(cnt < 3) v.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<v.size(); i++){ // 녹이기
        arr[v[i].first][v[i].second]--;
    }
}

void rotate(int sx, int sy, int s){

    // 맨 위쪽 배열 임시 저장
    int temp[64] = {0,};
    for(int i=0; i<s; i++){
        temp[i] = arr[sx][sy+i];
    }

    // 왼쪽이 위쪽으로 이동
    for(int i=0; i<s; i++){
        arr[sx][sy+i] = arr[sx+s-1-i][sy];
    }

    // 아래쪽이 왼쪽으로 이동
    for(int i=0; i<s; i++){
        arr[sx+i][sy] = arr[sx+s-1][sy+i];
    }

    // 오른쪽이 아래쪽으로 이동
    for(int i=0; i<s; i++){
        arr[sx+s-1][sy+i] = arr[sx+s-1-i][sy+s-1];
    }

    // 맨 위쪽이 오른쪽으로 이동
    for(int i=0; i<s; i++){
        arr[sx+s-1-i][sy+s-1] = temp[s-1-i];
    }

    // 안쪽으로 이동
    if(s > 2){
        rotate(sx+1, sy+1, s-2);
    }
}

void solve(){
    int a = 0;
    while(q--){
        cin >> a;
        int s = pow(2, a);
        for(int i=0; i<len; i+=s){ // 부분 격자별 회전
            for(int j=0; j<len; j+=s){
                rotate(i, j, s);
            }
        }
        melt(); // 녹이기
    }
}

void input(){
    cin >> n >> q;
    len = pow(2, n);
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cin >> arr[i][j];
        }
    }
}

void output(){
    // 남아있는 얼음의 합
    int sum = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            sum += arr[i][j];
        }
    }
    cout << sum << '\n';

    // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
    int maxsize = 0;
    memset(visited, false, sizeof(visited));
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(!visited[i][j] && arr[i][j] >= 1){
                maxsize = max(maxsize, BFS(i, j));
            }
        }
    }
    cout << maxsize << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    output();
    return 0;
}
