#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
int parent[200001];
int cnt[200001];
map<string, int> m;
int idx = 1;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

void init(){
    idx = 1;
    m.clear();
    fill(cnt, cnt+200001, 0);
    for(int i=1; i<=200000; i++){
        parent[i] = i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        vector<pair<int, int> > v;
        cin >> n;
        init();
        for(int i=1; i<=n; i++){
            string str1, str2;
            cin >> str1 >> str2;
            if(m.find(str1) == m.end()){
                m[str1] = idx++;
                cnt[m[str1]] = 1;
            }
            if(m.find(str2) == m.end()){
                m[str2] = idx++;
                cnt[m[str2]] = 1;
            }
            int a = m[str1];
            int b = m[str2];
            if(a > b) swap(a, b);
            v.push_back(make_pair(a, b));
        }
        for(int i=0; i<v.size(); i++){
            merge(v[i].first, v[i].second);
            cout << cnt[find(v[i].first)] << '\n';
        }
    }
    return 0;
}
