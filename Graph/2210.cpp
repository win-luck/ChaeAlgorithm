#include <iostream>
#include <set>

using namespace std;
char arr[6][6];
set<string> s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int x, int y, string str){
    if(str.size() == 6){
        s.insert(str);
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        DFS(nx, ny, str + arr[nx][ny]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            DFS(i, j, "");
        }
    }
    cout << s.size();
    return 0;
}
