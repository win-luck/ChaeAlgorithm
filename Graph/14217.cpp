#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, q;
vector<int> v[501];
int visited[501];


void BFS(int s){
    queue<int> q;
    for(int i=0; i<=500; i++) 
        visited[i] = 0; // 초기화
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){ // BFS
        int x = q.front();
        q.pop();

        for(int i=0; i<v[x].size(); i++){
            if(visited[v[x][i]] == 0){
                q.push(v[x][i]);
                visited[v[x][i]] = visited[x] + 1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(!visited[i]) visited[i] = -1; // 0이면 갈 수 없다는 의미
        else visited[i]--; // 1로 시작했으므로 하나씩 빼주어서 맞춰주었음
    }
    visited[1] = 0; // 수도는 0
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    } 

    cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){ // 새로운 도로를 생성
            v[b].push_back(c);
            v[c].push_back(b);
        } else { // 기존 도로를 제거 (도로는 양방향임)
            v[b].erase(find(v[b].begin(), v[b].end(), c));
            v[c].erase(find(v[c].begin(), v[c].end(), b));
        }

        BFS(1); // BFS로 1번부터 N번까지의 길이를 파악
        for(int j=1; j<=n; j++){
            cout << visited[j] << " ";
        }
        cout << '\n';
    }
    return 0;
}