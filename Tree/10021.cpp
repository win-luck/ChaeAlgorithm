#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
long long dis, result;
int x, y, cnt = 0;
int parent[2001];
vector<pair<int, int> > pipes;
vector<pair<long long, pair<int, int> > > distances; // (거리, a와, b의)

long long GetDis(int x1, int y1, int x2, int y2){
    return pow(x1-x2, 2) + pow(y1-y2, 2);
} // 두 점 사이의 거리를 반환

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);

	parent[u] = v; // 부모 노드 지정
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    for(int i=0; i<=n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    for(int i=1; i<=n; i++){
        cin >> x >> y;
        pipes.push_back(make_pair(x, y)); // 한 지점의 x좌표 y좌표
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            dis = GetDis(pipes[i].first, pipes[i].second, pipes[j].first, pipes[j].second);
            if(dis < c) continue;
            distances.push_back(make_pair(dis, make_pair(i, j))); // i번째 좌표와 j번째 좌표 간의 거리를 저장
        }
    }

    sort(distances.begin(), distances.end()); // 거리 기준 오름차순 정렬

    for(int i=0; i<distances.size(); i++){ // Kruskal 방식으로 최소 스패닝 트리
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        if(Find(a) != Find(b)){ // 사이클이 형성되지 않는다면 연결하고 그 값을 결과에 더해줌.
            Union(a, b);
            result += distances[i].first;
            cnt++;
        }
    }

    if(result == 0 || cnt != n-1) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}