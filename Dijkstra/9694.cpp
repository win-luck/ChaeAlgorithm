#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;
int t, n, m;
int dist[21];
int path[21];
vector<pair<int, int> > edge[21];
vector<int> answer;

void dijkstra(int start){ // 다익스트라
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int nowcost = -pq.top().first;
        int nowpos = pq.top().second;
        pq.pop();

        if(dist[nowpos] < nowcost) continue;

        for(int i=0; i<edge[nowpos].size(); i++){
            int nextpos = edge[nowpos][i].first;
            int nextcost = nowcost + edge[nowpos][i].second;

            if(dist[nextpos] > nextcost){
                path[edge[nowpos][i].first] = nowpos; // 최단경로 저장
                dist[nextpos] = nextcost;
                pq.push(make_pair(-nextcost, nextpos));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int k=1; k<=t; k++){
        answer.clear();
        fill(dist, dist + 21, INF);
        for(int i=0; i<21; i++) {
            edge[i].clear();
            path[i] = i;
        }
        
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back(make_pair(b, c));
            edge[b].push_back(make_pair(a, c));
        }
        dijkstra(0);

        if(dist[m-1] >= INF){
            cout << "Case #" << k << ": " << -1 << '\n';
        } else {
            cout << "Case #" << k << ": ";
            int x = m-1;
            while(x != path[x]){ // 최단거리 역추적
                answer.push_back(x);
                x = path[x];
            }
            answer.push_back(x);
            reverse(answer.begin(), answer.end()); // 뒤집으면 경로가 나온다.
            for(int i=0; i<answer.size(); i++){
                cout << answer[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
