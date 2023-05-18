#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int n, m, a, b, c, d;
long long res = 0;
int parent[10001];
vector<pair<int , pair<int, int> > > dist; // (애정점수, a와, b의)

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

   cin >> n >> m;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    } 

    for(int i=0; i<m; i++){ // 목표: 포기하도록 만든 애정도의 합을 최소화한다 (=최대 스패닝 트리를 만들어라)
        cin >> a >> b >> c >> d; // a와 b가 c만큼의 사랑점수를 갖는다
        if(d == 0){ // d = 0인 경우 dist에 저장
            res += c;
            dist.push_back(make_pair(c, make_pair(a, b)));
        } else { // d = 1인 경우 바로 MST에 편입
            Union(a, b);
        }
    }

    sort(dist.rbegin(), dist.rend()); // 점수순 내림차순 정렬
    
    for(int i=0; i<dist.size(); i++){ // d=0인 간선 대상으로 MST 형성
        int a = dist[i].second.first;
        int b = dist[i].second.second;

        if(Find(a) != Find(b)){ 
            Union(a, b);
            res -= dist[i].first;
        }
    }

    cout << res << '\n';
    return 0;
}