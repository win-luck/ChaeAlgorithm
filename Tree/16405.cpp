#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int n;
vector<pair<double, pair<int, int> > > edges;
vector<pair<int, int> > v;
int parent[1001];

double getDist(pair<int, int> p1, pair<int, int> p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin >> n;
        if(n == 0) break;
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }

        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
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
        cout.precision(2);
        cout << res << '\n';

        v.clear();
        edges.clear();
    }
    return 0;
}