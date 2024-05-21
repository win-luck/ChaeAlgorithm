#include <string>
#include <vector>
#define MAX 1000001
using namespace std;

int outDegree[MAX]; // 바깥으로 나가는 간선
int inDegree[MAX]; // 안으로 들어오는 간선
vector<int> graph[MAX];
bool visited[MAX];
vector<int> answer(4); // 출발점, 도넛, 막대, 8자

void dfs(int now){
    if(visited[now]){ // 사이클 -> 도넛
        answer[1]++;
        return;
    }
    if(outDegree[now] >= 2){// 나가는 간선 2개 -> 8자
        answer[3]++;
        return;
    }
    if(outDegree[now] == 0){ // 막대의 끝
        answer[2]++;
        return;
    }
    visited[now] = true;
    
    for(auto it: graph[now]){
        dfs(it);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    for(int i=0; i<edges.size(); i++){
        outDegree[edges[i][0]]++;
        inDegree[edges[i][1]]++;
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    // 시작 정점
    for(int i=1; i<MAX; i++){
        if(inDegree[i] == 0 && outDegree[i] >= 2){
            answer[0] = i;
            break;
        }
    }
    for(auto it: graph[answer[0]]){
        dfs(it);
    }
    return answer;
}
