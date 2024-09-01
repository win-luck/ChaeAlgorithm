#include <iostream>
#include <queue>

using namespace std;
int c, s, t;
int visited[201][201] = { 0, };

int bfs(int start, int end){
    queue<pair<int, int> > q;
    visited[start][end] = 1;
    q.push(make_pair(start, end));

    while(!q.empty()){
        int s = q.front().first;
        int e = q.front().second;
        q.pop();

        if(s == e){
            return visited[s][e] - 1;
        }

        if(s+1 <= e){
            q.push(make_pair(s+1, e));
            visited[s+1][e] = visited[s][e] + 1;
        }
        if(s*2 <= e+3){
            q.push(make_pair(s*2, e+3));
            visited[s*2][e+3] = visited[s][e] + 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c;
    for(int i=1; i<=c; i++){
        cin >> s >> t;
        cout << bfs(s, t) << '\n';
    }
    return 0;
}
