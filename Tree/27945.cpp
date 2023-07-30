#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans = 0;
int parent[100001];
vector<pair<int, pair<int, int> > > edge;

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
    
    for(int i=0; i<=100000; i++){
        parent[i] = i;
    }

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
        edge.push_back(make_pair(c, make_pair(b, a)));
    }

    sort(edge.begin(), edge.end());
    for(int i=0; i<edge.size(); i++){
        int val = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;

        if(find(a) != find(b)){
            merge(a, b);
            if(ans+1 == val){
                ans++;
            } else { // 연속으로 이어지지 않음
                break;
            }
        }
    }
    cout << ans+1 << '\n';
    return 0;
}
