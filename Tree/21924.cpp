#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
long long result, firstsum;
long long parent[100001];
vector<pair<long long, pair<long long, long long> > > distances; // (거리, a와, b의)

long long Find(long num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} // 간선의 부모를 찾는 유니온 파인드 적용

bool isAllConnected(int n) { // 모든 간선이 연결되었다면 부모는 무조건 Find(1)와 동일하다.
    for(int i=2; i<=n; i++){
        if(Find(1) != Find(i)){
            return false;
        }
    }
    return true;
}

bool Union(long long u, long long v) // 유니온 함수를 따로 분리하는 습관을 기르자. 조금이라도 복잡해지니 바로 흐름을 놓치는 결과가 많은 것 같다.
{
	u = Find(u);
	v = Find(v);

	// 부모 노드가 같다면 싸이클이	 생기므로 건너뜀
	if (u == v) return false;
	else
	{
		parent[u] = v; // 부모 노드 지정
		return true;
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m, x, y, val;
    cin >> n >> m;

    for(long long i=1; i<=n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    for(long long i=1; i<=m; i++){
            cin >> x >> y >> val;
            distances.push_back(make_pair(val, make_pair(x, y))); // i번째 좌표와 j번째 좌표 간의 거리를 저장
            distances.push_back(make_pair(val, make_pair(y, x))); // i번째 좌표와 j번째 좌표 간의 거리를 저장
            firstsum += val;
    }

    sort(distances.begin(), distances.end()); // 거리 기준 오름차순 정렬

    for(long long i=0; i<distances.size(); i++){ // Kruskal 방식으로 최소 스패닝 트리 적용
        long long a = distances[i].second.first;
        long long b = distances[i].second.second;
        if(Union(a, b)){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            result += distances[i].first;
        }
    }

    long long fin = firstsum - result;
    if(!isAllConnected(n)){ // 모든 지역이 연결되었는지 확인
        fin = -1;
    }
    cout << fin << endl;  
    return 0;
}