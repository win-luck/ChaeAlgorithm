#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
long long map[2501][2501];
int parent[2501];
vector<pair<int, int> > ans;
vector<pair<long long, pair<int, int> > > v;

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

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            v.push_back(make_pair(map[i][j], make_pair(i, j)));
        }
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        int a = v[i].second.first;
        int b = v[i].second.second;
        long long val = v[i].first;

        if(find(a) != find(b)){
            merge(a, b);
            ans.push_back(make_pair(a, b));
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}