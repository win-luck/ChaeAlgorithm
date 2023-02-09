#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b;
vector<int> edge[32001]; // 노드들의 간선을 저장 edge[1].push_back(2) == 1->2 방향의 간선
int inDegree[32001]; // 각 노드(정점)의 진입차수 저장
vector<int> result; // 결과(위상 순서)를 저장할 배열  

void topologicalSort() {
    priority_queue<int> q; // 우선순위 큐는 항상 내림차순으로 정렬된다.

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) // 진입차수가 0이면
            q.push(-i); // 큐에 노드 삽입, 문제가 쉬운 순으로 풀어야 하므로 음수를 붙여 강제로 오름차순으로 만든다.
    }

    while(!q.empty()) { // 모든 노드를 탐색하기 전에 큐가 빈다면 종료
        int cur_node = -q.top(); // 음수를 붙여서 넣었으므로 음수를 다시 붙여서 양수로 만든다.
        q.pop(); // 현재 노드를 큐에서 꺼내고

        result.push_back(cur_node);
        for (int j = 0; j < edge[cur_node].size(); j++) { // 큐에서 꺼낸 노드와 연결된 모든 간선 제거
            int next_node = edge[cur_node][j];
            if (--inDegree[next_node] == 0) { // 간선을 제거한 다음 노드의 진입차수가 0이라면 큐에 저장
                q.push(-next_node);
            }
        }
    }

    for (int i = 0; i < result.size(); i++) { // 순서에 따른 처리 결과(위상 순서)를 출력
        cout << result[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        edge[a].push_back(b); // 순서 관계 지정
        inDegree[b]++;
    }

    // 위상 정렬 실행
    topologicalSort();
    return 0;
}