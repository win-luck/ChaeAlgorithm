#include <iostream>
#include <queue>

using namespace std;
int n;
int map[3][3];
bool visited[3][3];

bool BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == n-1 && y == n-1) return true;

        int nx = map[x][y] + x;
        if(nx >= 0 && nx < n && !visited[nx][y]){
            visited[nx][y] = true;
            q.push(make_pair(nx, y));
        }

        int ny = map[x][y] + y;
        if(ny >= 0 && ny < n && !visited[x][ny]){
            visited[x][ny] = true;
            q.push(make_pair(x, ny));
        }
    }
    return false;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cout << (BFS() ? "HaruHaru" : "Hing");
    return 0;
}
