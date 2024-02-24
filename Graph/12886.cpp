#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
bool visited[1501][1501];
int a, b, c, d = 0;

int bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int z = d - x - y;

        int arr[3] = {x, y, z};
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(arr[i] < arr[j]){
                    int nx = arr[i] * 2;
                    int ny = arr[j] - arr[i];
                    if(!visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    return visited[d/3][d/3];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    d = a + b + c;
    memset(visited, false, sizeof(visited));
    if(d % 3 != 0){
        cout << 0;
    } else {
        cout << bfs();
    }
    return 0;
}
