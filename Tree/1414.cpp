#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int parent[51];
int map[51][51];
int result, mins;
vector<pair<int, pair<int, int> > > distances; // (비용, a에서 b로)

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
	else {
		parent[u] = v; // 부모 노드 지정
		return true;
	}
}

int makeNum(char a) { // 문자열을 문제에 제시한 숫자로 바꿔주는 함수
    if(a >= 'A' && a <= 'Z'){
        return a - 38;
    } else if(a >= 'a' && a <= 'z'){
        return a - 96;
    }
    return 0;
}

bool isAllConnected(int n) { // 모든 간선이 연결되었다면 부모는 무조건 Find(1)와 동일하다.
    for(int i=2; i<=n; i++){
        if(Find(1) != Find(i)){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, counts;
    string str;
    cin >> n;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=1; j<=n; j++){
            map[i][j] = makeNum(str[j-1]);
            if(map[i][j] == 0) continue; // 0이면 연결되지 않았으므로 생략
            result += map[i][j];
            distances.push_back(make_pair(map[i][j], make_pair(i, j))); 
        }
    }

    sort(distances.begin(), distances.end()); // 정렬

    for(int i=0; i<distances.size(); i++) { // Kruskal 방식으로 최소 스패닝 트리 적용
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        if(Union(a, b)) { // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌
            mins += distances[i].first;
        }
    }

    if(!isAllConnected(n)) { // 모든 노드가 연결되지 않았다면 -1 출력해야함
        cout << -1 << endl;
    } else {
        cout << result - mins << endl;  
    }
    return 0;
}