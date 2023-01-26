#include <iostream>
#include <algorithm>

using namespace std;
int r, c;
int map[21][21];
int result;
bool visited[26]; // 밟은 좌표가 아니라 밟은 좌표의 알파벳을 기준으로 백트래킹을 건다.
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int row, int col, int count){
    result = max(result, count);

    for(int i=0; i<4; i++){
        int nr = row + dx[i];
        int nc = col + dy[i];

        if(nr >= 0 && nr < r && nc >= 0 && nc < c){
            if(visited[map[nr][nc] - 'A'] == false){ // 아직 밟지 않은 알파벳이라면 
                visited[map[nr][nc] - 'A'] = true; // 밟고
                DFS(nr, nc, count + 1); // 다음 좌표 탐색 후 
                visited[map[nr][nc] - 'A'] = false; // 끝나면 다시 안 밟은 것으로 처리해준다. (다른 탐색들을 위해)
            }
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        string str;
        cin >> str;
        for(int j=0; j<c; j++){
            map[i][j] = str[j];
        }
    } // 입력 

    visited[map[0][0] - 'A'] = true; // 좌측 상단부터 시작
    DFS(0, 0, 1);

    cout << result << endl;
    return 0;
}