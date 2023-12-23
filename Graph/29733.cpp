#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
char map[101][101][101];
int result[101][101][101];
int d[9][2] = {
    {0,0}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}
};
int r, c, h;

// 폭탄 주변 지점(최대 26개)에 +1
void addcnt(int i, int j, int k){
    for(int a=0; a<=8; a++){
        for(int b=-1; b<=1; b++){
            int nx = i + d[a][0];
            int ny = j + d[a][1];
            int nz = k + b;
            if(nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= h) continue;
            if(map[nx][ny][nz] == '.'){
                result[nx][ny][nz]++;
            }
        }
    }
}

int main(){
    cin >> r >> c >> h; // 가로 세로 높이
    for(int k=0; k<h; k++){
        for(int i=0; i<r; i++){
            string str;
            cin >> str;
            for(int j=0; j<c; j++){
                map[i][j][k] = str[j];
                result[i][j][k] = 0;
            }
        }
    }
    for(int k=0; k<h; k++){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(map[i][j][k] == '*'){ // 폭탄
                    addcnt(i, j, k);
                }
            }
        }
    } 

    // 출력
    for(int k=0; k<h; k++){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(map[i][j][k] == '*'){
                    cout << "*";
                } else {
                    cout << (result[i][j][k] % 10);
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
