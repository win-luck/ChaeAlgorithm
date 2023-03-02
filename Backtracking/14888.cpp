#include <iostream>

using namespace std;
int n;
int minval = 100000001;
int maxval = -100000001;
int operators[12];
int operand[12];

void DFS(int value, int cnt){
    if(cnt == n){ // 백트래킹으로 값 갱신
        if(maxval < value){
            maxval = value;
        }
        if(minval > value){
            minval = value;
        }
        return;
    }

    for(int i=0; i<4; i++){
        if(operators[i] > 0){
            operators[i]--; // 연산자 삭감
            if(i == 0){ // 덧셈
                DFS(value + operand[cnt], cnt + 1);
            } else if(i == 1){ // 뺄셈
                DFS(value - operand[cnt], cnt + 1);
            } else if(i == 2){ // 곱셈
                DFS(value * operand[cnt], cnt + 1);
            } else { // 나눗셈
                DFS(value / operand[cnt], cnt + 1);
            }
            operators[i]++; // 연산자 부활 (DFS visited 생각하면 된다.)
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> operand[i];
    }

    for(int i=0; i<4; i++){
        cin >> operators[i];
    }

    DFS(operand[0], 1); // DFS와 백트래킹으로 모든 경우의 수를 순회하면서 값을 갱신한다.
    cout << maxval << '\n';
    cout << minval << '\n';
    return 0;
}