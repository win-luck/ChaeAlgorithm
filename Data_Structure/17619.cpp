#include <iostream>
#include <vector>
#include <algorithm>

struct line{
    int x1;
    int x2;
    int y;
    int idx;
    line(int a, int b, int c, int d){
        x1 = a;
        x2 = b;
        y = c;
        idx = d;
    }
};

using namespace std;
int parent[100001];
int n, q;
vector<line> v;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b)
        parent[a] = b;
}

bool cmp(line a, line b){
    return a.x1 < b.x1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(line(a, b, c, i));
        parent[i] = i;
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i].x2 >= v[j].x1){ // 이어가기
                merge(v[i].idx, v[j].idx);
            } else { // 이어가기 불가능
                break;
            }
        }
    }

    for(int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;
        cout << (find(a) == find(b) ? 1 : 0) << '\n';
    }
    return 0;
}
