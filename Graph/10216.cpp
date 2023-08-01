#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;
int t, n;
int parent[3001];
vector<pair<pair<int, int>, int> > v;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int a=0; a<t; a++){
        cin >> n;

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        v.clear();

        for(int i=0; i<n; i++){
            int x, y, r;
            cin >> x >> y >> r;
            v.push_back(make_pair(make_pair(x, y), r));
        }

        int ans = n;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int fx = v[i].first.first;
                int fy = v[i].first.second;
                int fr = v[i].second;

                int ex = v[j].first.first;
                int ey = v[j].first.second;
                int er = v[j].second;

                long long totalr = (fr+er)*(fr+er);
                long long dist = (fx-ex)*(fx-ex)+(fy-ey)*(fy-ey);
                if(find(i) == find(j)) continue;
                if(totalr >= dist) {
                    merge(i, j);
                    ans--;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}