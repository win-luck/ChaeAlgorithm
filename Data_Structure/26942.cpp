#include <iostream>
#include <set>
#include <map>

using namespace std;
int n, m;
int parent[101];
map<string, int> dict;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        dict[str] = i;
    }
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        string a, b;
        cin >> a >> b;
        merge(dict[a], dict[b]);
    }
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(find(i));
    }
    cout << s.size();
    return 0;
}
