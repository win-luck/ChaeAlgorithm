#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, s, p;
double res = 0;
int cnt = 0;
int parent[501];
vector<pair<int, int> > pos;
vector<pair<double, pair<int, int> > > edges;
vector<double> list;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

bool cmp(pair<double, pair<int, int> > p1, pair<double, pair<int, int> > p2){
    return p1.first < p2.first;
}

double getDist(pair<int, int> p1, pair<int, int> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int a=0; a<n; a++){
        cin >> s >> p;
        cnt = 0;
        res = 0;
        for(int i=0; i<=500; i++){
            parent[i] = i;
        }
        pos.clear();
        edges.clear(); // 초기화

        for(int i=0; i<p; i++){
            int a, b;
            cin >> a >> b;
            pos.push_back(make_pair(a, b)); // 각 지점의 x, y 좌표
        }

        for(int i=0; i<p; i++){ // i번째 위성과 j번째 위성 간 거리
            for(int j=i+1; j<p; j++){
                double dist = getDist(pos[i], pos[j]);
                edges.push_back(make_pair(dist, make_pair(i, j)));
            }
        }

        cnt = s-1; // 최초 위성의 개수를 기본적으로 깔아둔다.
        sort(edges.begin(), edges.end(), cmp);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(find(u) != find(v)){
                merge(u, v);
                res = edges[i].first;
                cnt++;
            }
            if(cnt == p-1) break; // p-1이라면 MST가 완성된 상황에서 위성간의 연결에 해당하는 s-1개가 모두 빠진 경우이므로 res가 답이다.
        }

        cout << fixed; // 자릿수 고정
        cout.precision(2);
        cout << res << '\n';
    }
    return 0;
}