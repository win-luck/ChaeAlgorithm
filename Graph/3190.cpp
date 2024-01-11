#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
int n, k, l;
int result = 0;
bool apple[101][101]; // 사과의 위치 저장
deque<pair<int, int> > dq;
map<int, char> m;
int dx[4] = {0, 1, 0, -1}; // 우하좌상 순서 - 반시계
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt, int dir){
    if(x < 0 || y < 0 || x >= n || y >= n) { // 벽에 부딪힘
        result = cnt;
        return;
    }  
    if(find(dq.begin(), dq.end(), make_pair(x, y)) != dq.end() && !(x == 0 && y == 0)){ // 자기자신에 부딪힘
        result = cnt;
        return;
    }

    dq.push_back(make_pair(x, y));
    if(apple[x][y]) apple[x][y] = false;
    else dq.pop_front();
    
    if(m.count(cnt) != 0){ // 방향을 꺾는가?
        int i = 0;
        if(m[cnt] == 'L'){ // 왼쪽으로 꺾어라
            i = (dir + 3) % 4;
        } else { // 오른쪽으로 꺾어라
            i = (dir + 1) % 4;
        }
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, cnt+1, i);
    } else {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(nx, ny, cnt+1, dir);
    }
}

void input(){
    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        apple[a-1][b-1] = true;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int a;
        char c;
        cin >> a >> c;
        m[a] = c;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    dq.push_back(make_pair(0, 0));
    dfs(0, 0, 0, 0);
    cout << result;
    return 0;
}
