#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> edge[1001]; // 노드들의 간선을 저장 edge[1].push_back(2) == 1->2 방향의 간선
int inDegree[1001]; // 각 노드(정점)의 진입차수 저장
vector<int> result; // 결과(위상 순서)를 저장할 배열  

void topologicalSort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) // 진입차수가 0이면
            q.push(i); // 큐에 노드 삽입
    }

    while(!q.empty()) { // 모든 노드를 탐색하기 전에 큐가 빈다면 종료
        int cur_node = q.front(); 
        q.pop(); // 현재 노드를 큐에서 꺼내고

        result.push_back(cur_node);
        for (int j = 0; j < edge[cur_node].size(); j++) { // 큐에서 꺼낸 노드와 연결된 모든 간선 제거
            int next_node = edge[cur_node][j];
            if (--inDegree[next_node] == 0) { // 간선을 제거한 다음 노드의 진입차수가 0이라면 큐에 저장
                q.push(next_node);
            }
        }
    }

    if(result.size() != n){ // 결과의 길이가 n이 아니면 불가능한 경우이므로 0 출력
        cout << 0 << '\n';
    } else {
        for (int i = 0; i < n; i++) { // 순서에 따른 처리 결과(위상 순서)를 출력
            cout << result[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int k;
        cin >> k;

        int d[k];
        for(int i=0; i<k; i++){ // k명 가수의 순서를 나타내는 배열을 입력받고
            cin >> d[i];
        }

        for(int i=0; i<k-1; i++){ // 꼬리물기하듯 순서 관계를 결정해준다.
            edge[d[i]].push_back(d[i+1]);
            inDegree[d[i+1]]++;
        }
    }

    // 위상 정렬 실행
    topologicalSort();
    return 0;
}