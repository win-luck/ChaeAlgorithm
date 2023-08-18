#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int visited[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(visited, 0, sizeof(visited));
    int s, e;
    cin >> s >> e;
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == e){
            cout << visited[e]-1 << '\n';
            break;
        }

        if(x + 1 <= 1000000 && !visited[x+1]){
            q.push(x+1);
            visited[x+1] = visited[x] + 1;
        }

        if(x * 2 <= 1000000 && !visited[x*2]){
            q.push(x*2);
            visited[x*2] = visited[x] + 1;
        }
    }
    return 0;
}