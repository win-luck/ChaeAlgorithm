#include <iostream>

struct belt{
    int hp; // 내구도
    bool isOn; // 로봇 탑승여부
};
using namespace std;
int n, k;
belt belts[2][101];

int countzero(){
    int a = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            if(belts[i][j].hp == 0) a++;
        }
    }
    return a;
}

void rotatebelt(){
    belt tmp1 = belts[0][n-1];
    belt tmp2 = belts[1][0];
    for(int i=n-1; i>=1; i--){ // ->
        belts[0][i] = belts[0][i-1];
    }
    for(int i=0; i<n; i++){ // <-
        belts[1][i] = belts[1][i+1];
    }
    belts[0][0] = tmp2;
    belts[1][n-1] = tmp1;

    if(belts[0][n-1].isOn) // 내리는 자리 비우기
        belts[0][n-1].isOn = false;
}

void moverobot(){
    for(int i=n-1; i>=1; i--){
        if(belts[0][i-1].isOn && !belts[0][i].isOn && belts[0][i].hp > 0){
            belts[0][i-1].isOn = false;
            belts[0][i].isOn = true;
            belts[0][i].hp--;
        }
    }
    if(belts[0][n-1].isOn) // 내리는 자리 비우기
        belts[0][n-1].isOn = false;
}

void addrobot(){ // 올리는 자리에 놓기
    if(belts[0][0].hp > 0){
        belts[0][0].hp--;
        belts[0][0].isOn = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){ // 위쪽
        cin >> belts[0][i].hp;
        belts[0][i].isOn = false;
    }
    for(int i=n-1; i>=0; i--){ // 아래쪽
        cin >> belts[1][i].hp;
        belts[1][i].isOn = false;
    }

    int cnt = 0;
    while(countzero() < k){
        rotatebelt();
        moverobot();
        addrobot();
        cnt++;
    }
    cout << cnt;
    return 0;
}
