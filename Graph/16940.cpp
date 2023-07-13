#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
vector<int> v[100001];
queue<int> q; // BFS용 큐
queue<int> order; // 순서 저장용 큐
int priority[100001]; // 간선의 우선순위를 부여

bool cmp(int a, int b){
    return priority[a] < priority[b];
} // 우선순위 앞서는 대로 정렬



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); // 트리는 무방향
    }

    for(int i=1; i<=n; i++){
        int p;
        cin >> p;
        order.push(p);
        priority[p] = i; // 각 노드에 우선순위 부여
    }

    for(int i=0; i<=n; i++){
        sort(v[i].begin(), v[i].end(), cmp);
    } // 우선순위대로 정렬

    if(order.front() != 1){
        cout << 0;
        return 0;
    } // 시작점은 반드시 1

    q.push(1);
    order.pop();
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<v[x].size(); i++){
            if(v[x][i] == order.front()){
                order.pop();
                q.push(v[x][i]);
            }
        }
    }
    if(order.empty()) cout << 1 << '\n'; // order가 비었다 -> 성공
    else cout << 0 << '\n';
    return 0;
}