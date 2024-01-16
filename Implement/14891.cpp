#include <iostream>
#include <algorithm>

using namespace std;
int map[4][8];
bool visited[4];
int k;


void rotate(int num, int type){
    bool flag1 = false;
    bool flag2 = false;
    if(num+1 < 4 && !visited[num+1]){
        if(map[num][2] != map[num+1][6]){
            flag1 = true;
        }
    }
    if(num-1 >= 0 && !visited[num-1]){
        if(map[num][6] != map[num-1][2]){
            flag2 = true;
        }
    }

    if(type == 1){ // 시계
        int tmp = map[num][7];
        for(int i=7; i>=1; i--){
            map[num][i] = map[num][i-1];
        }
        map[num][0] = tmp;
    } else { // 반시계
        int tmp = map[num][0];
        for(int i=0; i<7; i++){
            map[num][i] = map[num][i+1];
        }
        map[num][7] = tmp;
    }
    visited[num] = true;
    if(flag1) rotate(num+1, -type);
    if(flag2) rotate(num-1, -type);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    for(int i=0; i<4; i++){
        cin >> str; // 12시부터 시계방향 순서대로
        for(int j=0; j<str.size(); j++){
            map[i][j] = str[j] - '0'; // n극은 0, s극은 1
        }
    }

    cin >> k;
    for(int i=0; i<k; i++){
        int a, b;
        fill(visited, visited+4, false);
        cin >> a >> b;
        rotate(a-1, b);
    }

    int answer = 0;
    if(map[0][0] == 1) answer += 1;
    if(map[1][0] == 1) answer += 2;
    if(map[2][0] == 1) answer += 4;
    if(map[3][0] == 1) answer += 8;
    cout << answer;
    return 0;
}
