#include <iostream>

using namespace std;
int n;
char map[2188][2188]; // 3의 7제곱

void Blank(int r, int c, int n){
    for(int i=r; i<r+n; i++){
        for(int j=c; j<c+n; j++){
            map[i][j] = ' ';
        }
    }
}

void Backtracking(int r, int c, int n){
    if(n == 3){
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(i%3 == 1 && j%3 == 1){ // 중앙
                    map[i][j] = ' ';
                } else {
                    map[i][j] = '*';
                }
            }
        }
        return;
    }

    n /= 3;
    Backtracking(r, c, n);
    Backtracking(r, c+n, n);
    Backtracking(r, c+2*n, n);
    Backtracking(r+n, c, n);
    Blank(r+n, c+n, n); // 중앙은 공백이다.
    Backtracking(r+n, c+2*n, n);
    Backtracking(r+2*n, c, n);
    Backtracking(r+2*n, c+n, n);
    Backtracking(r+2*n, c+2*n, n);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    Backtracking(0, 0, n);
    for(int i=0; i<n; i++){ // 결과 출력
        for(int j=0; j<n; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}