#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
string s, target;
string arr;
int answer = INF;
int n;

void push(int pos){
    arr[pos] = (arr[pos] == '0' ? '1' : '0');
    if(pos > 0)
        arr[pos-1] = (arr[pos-1] == '0' ? '1' : '0');
    if(pos+1 < n)
        arr[pos+1] = (arr[pos+1] == '0' ? '1' : '0');
}

void turn(int pos, int cnt){
    if(pos == n-1){
        if(arr == target){
            answer = min(answer, cnt);
        } else {
            push(pos);
            if(arr == target){
                answer = min(answer, cnt+1);
            }
        }
        return;
    }

    if(arr[pos-1] != target[pos-1]){ // 이전 칸이 다르다면 현재 칸을 눌러 맞춰주어야 한다.
        push(pos);
        turn(pos, cnt+1);
    } else {
        turn(pos+1, cnt); // 문제 없다면 이제 현재 칸의 유효성 판별을 위해 다음 칸으로 이동한다.
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    cin >> target;

    arr = s;
    turn(1, 0);

    arr = s;
    push(0); // 최초 스위치 누르기
    turn(1, 1);

    cout << (answer == INF ? -1 : answer);
    return 0;
}
