#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n, x, y, d, g;
bool visited[101][101];
int dx[4] = {0, -1, 0, 1}; // 우상좌하
int dy[4] = {1, 0, -1, 0};
vector<int> path;

void curve(int cnt){
    if(cnt > g) return;
    if(cnt == 0){
        visited[x][y] = true;
        x = x + dx[d];
        y = y + dy[d];
        path.push_back(d);
        visited[x][y] = true;
        curve(cnt+1);
    } else {
        for(int i=path.size()-1; i>=0; i--){
            d = (path[i] + 1) % 4;
            x = x + dx[d];
            y = y + dy[d];
            visited[x][y] = true;
            path.push_back(d);
        }
        curve(cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, 0, sizeof(visited));

    cin >> n;
    for(int i=0; i<n; i++){
        path.clear();
        cin >> y >> x >> d >> g;
        curve(0);
    }

    int a = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(visited[i][j] && visited[i+1][j] && visited[i][j+1] && visited[i+1][j+1]){
                a++;
            }
        }
    }
    cout << a;
    return 0;
}
