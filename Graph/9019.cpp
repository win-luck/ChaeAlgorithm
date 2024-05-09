#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int t, a, b;

void bfs(int a, int b){
    int visited[10000] = {0,};
    queue<pair<string, int> > q;
    q.push(make_pair("", a));
    visited[a] = 1;

    while(!q.empty()){
        string now = q.front().first;
        int x = q.front().second;
        q.pop();

        if(x == b){
            cout << now << '\n';
            return;
        }

        // D
        int tmp = (x*2) % 10000;
        if(!visited[tmp]){
            q.push(make_pair(now + 'D', tmp));
            visited[tmp] = 1;
        }

        // S
        int snum = (x == 0 ? 9999 : x-1);
        if(!visited[snum]){
            q.push(make_pair(now + 'S', snum));
            visited[snum] = 1;
        }

        // L
        int lnum = (x%1000) * 10 + (x/1000);
        if(!visited[lnum]){
            q.push(make_pair(now + 'L', lnum));
            visited[lnum] = 1;
        }

        // R
        int rnum = (x%10) * 1000 + (x/10);
        if(!visited[rnum]){
            q.push(make_pair(now + 'R', rnum));
            visited[rnum] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b;
        bfs(a, b);
    }
    return 0;
}
