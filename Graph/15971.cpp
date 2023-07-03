#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, s, e;
long sum = 0;
vector<pair<int, int> > v[100001];
vector<int> lines;
bool visited[100001];

void DFS(int pos, long sum){
    if(pos == e){ // 도착점에 도착함
        sort(lines.begin(), lines.end()); // 출발점~도착점까지의 거리에서 가장 긴 간선을 빼면 된다.
        if(lines.empty()) cout << sum << '\n'; // 출발/도착점이 동일한 경우에 대한 예외처리
        else cout << sum - lines.back() << '\n'; // 가장 긴 간선을 둔 양쪽 노드에서 만나면 최소이다.
        return;
    }

    if(visited[pos]) return;
    visited[pos] = true; // 방문처리
    for(int i=0; i<v[pos].size(); i++){
        if(!visited[v[pos][i].first]){
            lines.push_back(v[pos][i].second); // 간선 리스트에 추가
            DFS(v[pos][i].first, sum + v[pos][i].second);
            lines.pop_back(); // 재귀 빠져나오면 간선 리스트에서 배제
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> e;
    for(int i=1; i<=n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    } // 입력
    
    DFS(s, 0);
    return 0;
}