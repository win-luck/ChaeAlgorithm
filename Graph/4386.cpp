#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

// 1647번과 유니온 파인드 연습 시 다시 풀어보기

using namespace std;
double n, result;
double x, y, dis;
int parent[101];
vector<pair<double, double> > map;
vector<pair<double, pair<int, int> > > distances;

double GetDis(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
} // 두 점 사이의 거리를 반환

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} // 간선의 부모를 찾는 유니온 파인드 적용

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    for(int i=0; i<n; i++){
        cin >> x >> y;
        map.push_back(make_pair(x, y));
    } // i번째 좌표의 좌표평면 값 입력

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dis = GetDis(map[i].first, map[i].second, map[j].first, map[j].second);
            distances.push_back(make_pair(dis, make_pair(i, j))); // i번째 좌표와 j번째 좌표 간의 거리를 저장
        }
    }

    sort(distances.begin(), distances.end()); // 최소 스패닝 트리 적용을 위해 오름차순으로 정렬

    for(int i=0; i<pow(n, 2); i++){ // Kruskal 방식으로 최소 스패닝 트리 적용
        int a = Find(distances[i].second.first);
        int b = Find(distances[i].second.second);
        if(a != b){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            parent[a] = b;
            result += distances[i].first;
        }
    }

    cout.precision(3);
    cout << result << endl;
}