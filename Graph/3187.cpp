#include <iostream>
#include <queue>

using namespace std;
int r, c;
char map[251][251];
bool visited[251][251];
int total1 = 0, total2 = 0; // 총 양과 늑대
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS(int sx, int sy){
    int sheep = 0;
    int wolf = 0;
    queue<pair<int, int> > q;

    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        if(map[x][y] == 'v') wolf++;
        else if(map[x][y] == 'k') sheep++;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny]) continue;
            if(map[nx][ny] != '#'){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    if(sheep > wolf) {
        total1 += sheep;
    } else {
        total2 += wolf;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        string str;
        cin >> str;
        for(int j=0; j<c; j++){
            map[i][j] = str[j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j] && map[i][j] != '#'){
                BFS(i, j);
            }
        }
    }
    cout << total1 << " " << total2;
    return 0;
}
