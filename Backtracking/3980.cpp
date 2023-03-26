#include <iostream>
#include <cstring>

using namespace std;

int mem[11][11];
bool visited[11];
int res, t;

void backtracking(int sum, int cnt){
    if(cnt == 11){ // 11명 포지션 전부 결정되면 갱신
        res = max(res, sum);
    }

    for(int i=0; i<11; i++){
        if(mem[cnt][i] != 0 && !visited[i]){ // 아직 포지션에 아무도 없으면서 그 포지션에서 0이 아닌 선수
            sum += mem[cnt][i];
            visited[i] = true;
            backtracking(sum, cnt + 1); // 의 포지션을 결정하고 다음으로 넘어감
            visited[i] = false;
            sum -= mem[cnt][i];
        }
    }
}

int main(){
    cin >> t;
    for(int a=0; a<t; a++){
        res = 0;
        memset(mem, 0, sizeof(mem));
        memset(visited, false, sizeof(visited));

        for(int i=0; i<11; i++){ // 입력
            for(int j=0; j<11; j++){
                cin >> mem[i][j];
            }
        }

        backtracking(0, 0);
        cout << res << '\n';
    }
    return 0;
}