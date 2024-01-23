#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int arr[51][51];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx2[4] = {-1, 1, -1, 1};
int dy2[4] = {-1, -1, 1, 1};
vector<pair<int, int> > c;

bool incloud(int x, int y){
    for(int i=0; i<c.size(); i++){
        if(c[i].first == x && c[i].second == y) return true;
    }
    return false;
}

pair<int, int> nextpos(int sx, int sy, int a, int b){
    int nx = sx + b * dx[a-1];
    int ny = sy + b * dy[a-1];
    while(nx < 1){
        nx = n + nx;
    }
    while(ny < 1){
        ny = n + ny;
    }
    while(nx > n){
        nx = nx - n;
    }
    while(ny > n){
        ny = ny - n;
    }
    return make_pair(nx, ny);
}

void cloud(int a, int b){
    for(int i=0; i<c.size(); i++){ // 구름의 이동
        c[i] = nextpos(c[i].first, c[i].second, a, b);
    }

    for(int i=0; i<c.size(); i++){ // 구름에서 비가 내림
        arr[c[i].first][c[i].second]++;
    }

    for(int i=0; i<c.size(); i++){ // 대각선에 물이 있는지 확인
        for(int k=0; k<4; k++){
            int nx = c[i].first + dx2[k];
            int ny = c[i].second + dy2[k];
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if(arr[nx][ny] > 0){
                arr[c[i].first][c[i].second]++;
            }
        }
    }

    vector<pair<int, int> > v;
    for(int i=1; i<=n; i++){ // 새로 생기는 구름
        for(int j=1; j<=n; j++){
            if(incloud(i, j)) continue;
            if(arr[i][j] >= 2) { 
                v.push_back(make_pair(i, j));
                arr[i][j] -= 2;
            }
        }
    }
    c = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(arr, 0, sizeof(arr));

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    // 비바라기
    int sx = n-1;
    int sy = 1;
    c.push_back(make_pair(sx, sy));
    c.push_back(make_pair(sx, sy+1));
    c.push_back(make_pair(sx+1, sy));
    c.push_back(make_pair(sx+1, sy+1));

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        cloud(a, b);
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum += arr[i][j];
        }
    }
    cout << sum;
    return 0;
}
