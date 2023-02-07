#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
double dis, result;
int x, y;
int parent[1001];
vector<pair<int, int> > god; // 신들의 좌표
vector<pair<double, pair<int, int> > > distances; // (거리, a와, b의)

double GetDis(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
} // 두 점 사이의 거리를 반환

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} // 간선의 부모를 찾는 유니온 파인드 적용

bool Union(int u, int v) // 유니온 함수를 따로 분리하는 습관을 기르자. 조금이라도 복잡해지니 바로 흐름을 놓치는 결과가 많은 것 같다.
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

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    god.push_back(make_pair(0, 0));
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        god.push_back(make_pair(x, y));
    } // i번째 신의 좌표 값 입력

    for(int i=1; i<=m; i++){
        cin >> x >> y;
        Union(x, y);
    }

    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            dis = GetDis(god[i].first, god[i].second, god[j].first, god[j].second);
            distances.push_back(make_pair(dis, make_pair(i, j))); // i번째 좌표와 j번째 좌표 간의 거리를 저장
        }
    }

    sort(distances.begin(), distances.end()); // 거리 기준 오름차순 정렬

    for(int i=0; i<distances.size(); i++){ // Kruskal 방식으로 최소 스패닝 트리 적용
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        if(Union(a, b)){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            result += distances[i].first;
        }
    }

    printf("%.2lf", result);   
    return 0;
}