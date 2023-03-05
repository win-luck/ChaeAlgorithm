#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, x, y, val;
int parent[1001];
int map[1001][1001];
int sum = 0;

bool cmp (pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    return p1.first < p2.first;
}

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

int main(){
    vector<pair<int, pair<int, int> > > dist;
    vector<pair<int, int> > vec;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
            parent[i] = i;
    }

    for(int i=0; i<m; i++){
        cin >> x >> y;
        if(find(x) != find(y)){ // 이미 연결된 컴퓨터
            Union(x, y);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            dist.push_back(make_pair(map[i][j], make_pair(i, j)));
        }
    }

    sort(dist.begin(), dist.end(), cmp);

    for(int i=0; i<dist.size(); i++){
        int u = dist[i].second.first;
        int v = dist[i].second.second;
        if(u == 1 || v == 1) continue; // 1번 컴퓨터는 이미 연결되어 있다.
        
        int cost = dist[i].first;

        if(find(u) != find(v)){ // 새로 연결해야하는 경우
            Union(u, v);
            sum += cost; // 연결 비용 추가
            vec.push_back(make_pair(u, v)); // 새로 연결한 컴퓨터 쌍
        }
    }

    if(vec.size() == 0){ // 없으면 0 0 출력하기
        cout << 0 << " " << 0 << '\n';
    } else { // 있으면 형식에 맞게 출력
        cout << sum << " " << vec.size() << '\n';
        for(int i=0; i<vec.size(); i++){
            cout << vec[i].first << " " << vec[i].second << '\n';
        }
    }
    return 0;
}