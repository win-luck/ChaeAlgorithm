#include <iostream>

using namespace std;
int map[129][129];
int result[2];

bool checkcolor(int r, int c, int size){ // 색종이가 정사각형을 이루고 있는가?
    int color = map[r][c];
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            if(color != map[i][j]) return false;
        }
    }
    return true;
}

void divcon(int r, int c, int s){ // 분할정복은 백트래킹과 연계되는 경우가 많다.
    if(checkcolor(r, c, s)){
        if(map[r][c] == 1){
            result[1]++;
        } else {
            result[0]++;
        }
        return;
    }
    s /= 2;
    divcon(r, c, s);
    divcon(r, c+s, s);
    divcon(r+s, c, s);
    divcon(r+s, c+s, s);
}


int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    divcon(0, 0, N);
    cout << result[0] << " " << result[1] << '\n';
}
