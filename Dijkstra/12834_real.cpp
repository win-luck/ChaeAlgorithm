#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;
int n, v, e, a, b;
int d[1001];
int sum = 0;
vector<pair<int, int> > edge[1001];
vector<pair<int, int> > person;

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    d[start] = 0;
    pq.push(make_pair(-d[start], start));

    while(!pq.empty()){
        int nowdist = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(nowdist > d[now]) continue;

        for(int i=0; i<edge[now].size(); i++){
            int next = edge[now][i].first;
            int nextdist = nowdist + edge[now][i].second;

            if(d[next] > nextdist){
                d[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> v >> e; // 팀원, 장소, 도로
    cin >> a >> b; // KIST, 씨알푸드의 위치
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        person.push_back(make_pair(tmp, 0));
    } // 팀원들 위치

    for(int i=1; i<=e; i++){
        int t, f, l;
        cin >> t >> f >> l;
        edge[t].push_back(make_pair(f, l));
        edge[f].push_back(make_pair(t, l));
    }

    for(int i=0; i<=1000; i++){
        d[i] = INF;
    }
    dijkstra(a);
    for(int i=0; i<person.size(); i++){
        int pos = person[i].first;
        if(d[pos] >= INF){
            person[i].second += -1;
        } else {
            person[i].second += d[pos];
        }
    }

    for(int i=0; i<=1000; i++){
        d[i] = INF;
    }
    dijkstra(b);
    for(int i=0; i<person.size(); i++){
        int pos = person[i].first;
        if(d[pos] >= INF){
            person[i].second += -1;
        } else {
            person[i].second += d[pos];
        }
    }

    for(int i=0; i<person.size(); i++){
        sum += person[i].second;
    }
    cout << sum;
    return 0;
}
