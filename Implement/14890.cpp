#include <iostream>
#include <vector>

using namespace std;
int n, L;
int map[101][101];
int answer = 0;

void row(int r, int c, int cnt){
    if(c == n-1){ // 성공
        answer++;
        return;
    }

    int h = map[r][c];
    int next = map[r][c+1];
    if(h == next){ // 같은 경우
        row(r, c+1, cnt+1);
    } else if(h == next+1){ // 내려가는 경우
        if(c+L < n){
            for(int i=c+1; i<=c+L; i++){
                if(next != map[r][i]) return;
            }
            row(r, c+L, 0);
        }
    } else if(h+1 == next){ // 올라가는 경우
        if(cnt >= L){
            row(r, c+1, 1);
        }
    } else{
        return;
    }
}

void col(int r, int c, int cnt){
    if(r == n-1){ // 성공
        answer++;
        return;
    }

    int h = map[r][c];
    int next = map[r+1][c];
    if(h == next){ // 같은 경우
        col(r+1, c, cnt+1);
    } else if(h == next+1){ // 내려가는 경우
        if(r+L < n){
            for(int i=r+1; i<=r+L; i++){
                if(next != map[i][c]) return;
            }
            col(r+L, c, 0);
        }
    } else if(h+1 == next){ // 올라가는 경우
        if(cnt >= L){
            col(r+1, c, 1);
        }
    } else{
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        row(i, 0, 1); // i행 0열
        col(0, i, 1); // 0행 i열
    }
    cout << answer;
    return 0;
}
