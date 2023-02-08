#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int parent[1001];
vector<pair<double, pair<int, int> > > distances; // (거리, a와, b의)

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} // 간선의 부모를 찾는 유니온 파인드 적용

bool Union(int u, int v) // 유니온 함수를 따로 분리하는 습관을 기르자. 조금이라도 복잡해지니 바로 흐름을 놓치는 결과가 많은 것 같다.
{
	u = Find(u);
	v = Find(v);

	// 부모 노드가 같다면 싸이클이 생기므로 건너뜀
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

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int dis;
            cin >> dis;
            distances.push_back(make_pair(dis, make_pair(i, j)));
        }
    } // i행성과 j행성 간의 거리 입력

    sort(distances.begin(), distances.end()); // 거리 기준 오름차순 정렬

    long result = 0; // int범위를 넘을 수도 있음.
    for(int i=0; i<distances.size(); i++){ // Kruskal 방식으로 최소 스패닝 트리 적용
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        if(Union(a, b)){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            result += distances[i].first;
        }
    }

    cout << result;  
    return 0;
}