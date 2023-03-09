#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pi pair<int, int>
#define INF 987654321;
using namespace std;
int n, m, a;
int minres = INF;
int visited[14];
vector<pi> chicken;
vector<pi> people;
vector<pi> chicken_picked;


int findpos(pi p1, pi p2){ // 집과 치킨집의 거리 반환
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void findmin(){
    int res = 0;
    for(int i=0; i<people.size(); i++){
        int cost = INF;
        for(int j=0; j<chicken_picked.size(); j++){ // 치킨집 중 지금 집과 가장 가까운 치킨집을 찾아
            cost = min(cost, findpos(people[i], chicken_picked[j]));
        }
        res += cost; // 그 거리를 더해준다.
    }
    minres = min(minres, res);
}

void DFS(int pos, int depth){
    if(depth == m){ // m개의 치킨집을 선택했다면 치킨거리 구하기 (백트래킹))
        findmin();
        return;
    }

    for(int i=pos; i<chicken.size(); i++){
        if(visited[i]) continue;

        visited[i] = true;
        chicken_picked.push_back(make_pair(chicken[i].first, chicken[i].second));
        DFS(i, depth + 1);
        visited[i] = false;
        chicken_picked.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a;
            if(a == 1){
                people.push_back(make_pair(i, j)); // 집
            } else if (a == 2){ 
                chicken.push_back(make_pair(i, j)); // 치킨집
            }
        }
    }

    DFS(0, 0);
    cout << minres;
    return 0;
}