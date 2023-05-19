#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int parent[1001];
int a, b, c;
int cnt = 0;
vector<pair<long long, pair<int, int> > > distances; // (거리, a와, b의)

bool cmp(pair<long long, pair<int, int> > p1, pair<long long, pair<int, int> > p2){
    return p1.first > p2.first;
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.


    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        distances.push_back(make_pair(c, make_pair(a, b)));
    } // i행성과 j행성 간의 거리 입력

    sort(distances.begin(), distances.end(), cmp); // 거리 기준 오름차순 정렬

    long long result = 0; // int범위를 넘을 수도 있음.
    for(int i=0; i<distances.size(); i++){ // Kruskal 방식으로 최소 스패닝 트리 적용
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        if(Find(a) != Find(b)){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            Union(a, b);
            result += distances[i].first;
            cnt++;
        }
    }

    if(cnt == n-1){
        cout << result << '\n';
    } else {
        cout << -1 << '\n';
    }  
    return 0;
}