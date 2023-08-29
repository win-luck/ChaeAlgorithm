#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int parent[100001];
int nation[100001];
int n, m;
vector<int> v;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){ // 최초 입력
        parent[i] = i;
        cin >> nation[i];
    }

    for(int i=1; i<=m; i++){
        int k, a, b;
        cin >> k >> a >> b;

        a = find(a);
        b = find(b);
        if(a != b){
            if(k == 1){ // 동맹: 두 집단이 하나로 합쳐짐
                if(a > b) swap(a, b); // 편의상 더 작은 숫자가 부모가 되도록
                parent[b] = a;
                nation[a] += nation[b];
            } else { // 전쟁: 두 집단 중 더 큰 집단이 부모가 됨
                if(nation[b] > nation[a]) swap(a, b); // 편의상 항상 b 집단의 크기가 더 작아지도록
                parent[b] = a;
                nation[a] -= nation[b];
                if(nation[a] == 0){ // 두 집단이 같을 경우 모두 멸망(부모를 -1로 처리)
                    parent[a] = parent[b] = -1;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(parent[i] == i){
            v.push_back(nation[i]);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end()); // 오름차순 정렬
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}
