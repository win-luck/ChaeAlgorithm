#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int x, y;
long long res = 0;
int parent[1001];
vector<pair<int, int> > pos;
vector<pair<long long, pair<int, int> > > dist; // (비용, a와, b의)

long long makedist(pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} 

void Union(int u, int v) 
{
	u = Find(u);
	v = Find(v);

    parent[u] = v;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    } 

    pos.push_back(make_pair(0, 0));
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        pos.push_back(make_pair(x, y));
    }

    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            dist.push_back(make_pair(makedist(pos[i], pos[j]), make_pair(i, j))); // i번째 소와 j번째 소 간의 거리를 저장
        }
    }

    sort(dist.begin(), dist.end());
    for(int i=0; i<dist.size(); i++){
        int a = dist[i].second.first;
        int b = dist[i].second.second;
        if(Find(a) != Find(b)){ 
            Union(a, b);
            if(res < dist[i].first) // MST 내에서 가장 긴 거리를 찾아내는 것이 정답
                res = dist[i].first;
        }
    }

    cout << res << endl;  
    return 0;

}