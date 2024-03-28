#include <iostream>
#include <queue>

using namespace std;
int arr[10001];
int visited[10001] = {0, };
int sx, ex, n;
int answer = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cin >> sx >> ex;

    queue<int> q;
    q.push(sx);
    visited[sx] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == ex){
            answer = visited[x]-1;
            break;
        }

        for(int i=1; i<=n; i++){
            int nx = x + i*arr[x];
            if(nx <= 0 || nx > n || visited[nx]) continue;
            q.push(nx);
            visited[nx] = visited[x] + 1;
        }

        for(int i=1; i<=n; i++){
            int nx = x - i*arr[x];
            if(nx <= 0 || nx > n || visited[nx]) continue;
            q.push(nx);
            visited[nx] = visited[x] + 1;
        }
    }
    cout << answer;
    return 0;
}
