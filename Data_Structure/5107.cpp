#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
int n;
string str1, str2;
map<string, int> m;
int parent[21];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a > b) swap(a, b);
    if(a != b){
        parent[b] = a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int a=1; ; a++){
        cin >> n;
        if(n == 0) break;
        int idx = 1;
        m.clear();
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            cin >> str1 >> str2;
            if(m.find(str1) == m.end()){
                m[str1] = idx++;
            }
            if(m.find(str2) == m.end()){
                m[str2] = idx++;
            }
            merge(m[str1], m[str2]);
        }

        set<int> s;
        for(auto it: m){
            s.insert(find(it.second));
        }
        cout << a << " " << s.size() << '\n';
    }
    return 0;
}
