#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321
using namespace std;

vector<pair<int, int> > edge[1001];
int dist[1001];
int n, m, x, y;
vector<int> answer;

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int nowval = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < nowval) continue;

        for(int i=0; i<edge[now].size(); i++){
            int next = edge[now][i].first;
            int nextcost = nowval + edge[now][i].second;

            if(dist[next] > nextcost){
                dist[next] = nextcost;
                pq.push(make_pair(-nextcost, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dist, dist + 1001, INF);
    cin >> n >> m >> x >> y;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    dijkstra(y);

    for(int i=0; i<n; i++){
        if(dist[i] >= INF){ // 갈 수가 없는 경우
            cout << -1;
            return 0;
        }
        answer.push_back(dist[i] * 2);
    }

    sort(answer.begin(), answer.end());
    if(answer.back() > x){
        cout << -1;
        return 0;
    }

    int cnt = 1;
    int sum = 0;
    for(int i=0; i<answer.size(); i++){
        if(sum + answer[i] > x){
            sum = 0;
            cnt++;
        }
        sum += answer[i];
    }
    cout << cnt;
    return 0;
}
