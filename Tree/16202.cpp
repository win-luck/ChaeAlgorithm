#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k;
int x, y;
vector<pair<int, pair<int, int> > > edges; // 가중치, 간선이 잇는 노드
int parent[1001];
int cnt = 0;
bool flag = true;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    return p1.first > p2.first; // 내림차순
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // n: 정점, m: 간선, k: 턴
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        edges.push_back(make_pair(i, make_pair(x, y)));
        edges.push_back(make_pair(i, make_pair(y, x)));
    }
    sort(edges.begin(), edges.end(), cmp); // 내림차순으로 정렬

    for(int i=1; i<=k; i++){
        if(!flag){ // 남아있는 모든 턴의 점수는 0
            cout << 0 << " ";
            continue;
        }
        cnt = 0;
        long long sum = 0;
        for(int j=0; j<=n; j++){
            parent[j] = j;
        }

        int s = edges.size();
        for(int j = s-1; j >= 0; j--){ // 역순으로 오름차순처럼 MST를 생성해나감
            if(find(edges[j].second.first) != find(edges[j].second.second)){
                merge(edges[j].second.first, edges[j].second.second);
                cnt++;
                sum += edges[j].first;
            }
        }

        if(cnt != n-1){ // MST가 만들어질 수 없음을 감지 -> 앞으로도 MST는 만들어지지 않는다는 flag 활성화
            flag = false;
            cout << 0 << " ";
        } else {
            cout << sum << " ";
            edges.pop_back(); // MST를 형성했던 가장 작은 간선 배제, 양방향이므로 두 번 빼줘야 함
            edges.pop_back();
        }
    }
    return 0;
}