#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, h;
int visited[5];
int damage[5];
int cool[5];
int answer = 987654321;

void dfs(int hp, int cnt){
    if(hp <= 0){
        answer = min(answer, cnt);
        return;
    }

    bool flag = false;
    for(int i=0; i<n; i++){
        if(visited[i]+cool[i] <= cnt){
            int tmp = visited[i];
            visited[i] = cnt;
            dfs(hp-damage[i], cnt+1);
            visited[i] = tmp;
            flag = true;
        }
    }
    if(!flag){
        dfs(hp, cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;
    for(int i=0; i<n; i++){
        cin >> cool[i] >> damage[i];
        visited[i] = -987654321;
    }
    dfs(h, 0);
    cout << answer;
    return 0;
}
