#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int n, e, p;
vector<pair<double, pair<int, int> > > edges;
vector<pair<double, double> > v;
int parent[1001];

double getDist(pair<double, double> p1, pair<double, double> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a > b) swap(a, b);
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> p;
    for(int i=0; i<=n; i++){ // 0번 노드부터 시작
        parent[i] = i;
    }

    for(int i=0; i<n; i++){
        double a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    for(int i=0; i<p; i++){
        int a, b;
        cin >> a >> b;
        merge(a-1, b-1);
    }

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(find(i) == find(j)) continue; // 이미 연결됨
            if(j == e-1){ // 도착지가 e-1이면 무료
                merge(i, j);
                continue;
            }
            double d = getDist(v[i], v[j]);
            edges.push_back(make_pair(d, make_pair(i, j)));
        }
    }

    sort(edges.begin(), edges.end());
    double res = 0;
    for(int i=0; i<edges.size(); i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        double val = edges[i].first;

        if(find(a) != find(b)){
            merge(a, b);
            res += val;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << res << '\n';
    return 0;
}
