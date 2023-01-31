#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[500001];
int result = 0;

int find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = find(parent[num]);
} // 유니온 파인드

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){ // n개의 점
        parent[i] = i;
    } // 최초에 자신의 부모는 자기 자신임.

    // 모든 집을 연결해준 후, 가장 큰 가중치를 잘라내는 것이 목표다.
    for(int i=1; i<=m; i++){
        int s, e;
        cin >> s >> e;

        s = find(s); // 유니온 파인드 적용
        e = find(e);

        if(s != e){
            parent[s] = e;
        } else { // 사이클 발생
            result = i;
            break;
        }
    }

    if(result == 0) {
        cout << 0;
    } else {
        cout << result;
    }
    return 0;
}