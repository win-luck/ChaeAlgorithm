#include <iostream>

using namespace std;
int n, s;
int map[21];
bool visited[21];
int cnt = 0;
int sum = 0;

void DFS(int sum, int depth){
    if(depth == n){
        return;
    }
    if(sum + map[depth] == s){
        cnt++;
    }

    DFS(sum + map[depth], depth + 1); // 현재 수를 더하거나
    DFS(sum, depth + 1); // 더하지 않고 넘어가거나 (생략)
}

int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> map[i];
    }

    DFS(0, 0);
    cout << cnt;
    return 0;
}