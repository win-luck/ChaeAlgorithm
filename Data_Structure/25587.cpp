#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int parent[100001];
int capacity[100001];
int cnt[100001];
int rain[100001];
int answer = 0;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a > b) swap(a, b);
    if(a != b){
        if(rain[a] > capacity[a]) // 이미 넘치고 있음 -> 배제
            answer -= cnt[a];
        if(rain[b] > capacity[b])
            answer -= cnt[b];

        parent[b] = a;
        rain[a] += rain[b];
        capacity[a] += capacity[b];
        cnt[a] += cnt[b];

        if(rain[a] > capacity[a]) // 합친 이후에 넘치는 경우 재포함
            answer += cnt[a];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> capacity[i];
        cnt[i] = 1;
        parent[i] = i;
    }
    for(int i=1; i<=n; i++){
        cin >> rain[i];
        if(rain[i] > capacity[i]) {
            answer++;
        }
    }
    for(int i=1; i<=m; i++){
        int f;
        cin >> f;
        if(f == 1){
            int a, b;
            cin >> a >> b;
            merge(a, b);
        } else {
            cout << answer << '\n';
        }
    }
    return 0;
}
