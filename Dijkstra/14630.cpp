#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;
int n;
int d[1001];
int start, endp;
vector<pair<int, int> > edge[1001];
vector<string> v;

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

int moneycnt(int i, int j){
    string a = v[i];
    string b = v[j];

    int sum = 0;
    for(int i=0; i<a.size(); i++){
        sum += abs(a[i]-b[i]) * abs(a[i]-b[i]);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    fill(d, d + 1001, INF);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            // cout << i+1 << " to " << j+1 << ": " << moneycnt(i, j) << '\n';
            edge[i].push_back(make_pair(j, moneycnt(i, j)));
        }
    }
    cin >> start >> endp;
    dijkstra(start-1);
    cout << d[endp-1] << '\n';
    return 0;
}
