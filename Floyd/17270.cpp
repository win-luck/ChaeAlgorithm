#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321 // 문제가 너무 더럽다.
using namespace std;
int p, q;
int a, b, c, residx;
int res = INF;
int dist[101][101];
vector<int> can;

void init(){ // 초기화
    res = INF;
    residx = -1;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void Floyd(){
    for(int k=1; k<=p; k++){
        for(int i=1; i<=p; i++){
            for(int j=1; j<=p; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[k][j] != INF & dist[i][k] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> q; // 위치의 수, 간선의 개수
    init();
    for(int i=0; i<q; i++){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    int s, e; // 지헌, 성하 -> 항상 지헌이가 성하보다 빠르거나 동시에 도착해야함
    cin >> s >> e;
    Floyd();

    int mincost = INF;
    for(int i=1; i<=p; i++){
        if(i == s || i == e) continue;
        if(mincost > dist[s][i] + dist[i][e]){
            mincost = dist[s][i] + dist[i][e];
        }
    } // 최단거리 값 뽑아내기

    int mintime = INF;
    for(int i=1; i<=p; i++){
        if(i == s || i == e) continue; // 조건 1: 각자의 출발위치는 배제
        if(dist[i][s] >= INF || dist[i][e] >= INF){ // 갈 수 없는 외딴 길이라면 불가능
            continue;
        }
        if(dist[i][s] > dist[i][e]){ // 조건 3 지헌이는 성하보다 도착 시간이 짧거나 같아야 함
            continue;
        }
        if(dist[s][i] + dist[i][e] == mincost){ // 최단 거리에 속하는 case에서
            if(mintime > dist[s][i]){ // 지헌이의 거리가 가장 짧은 것을 찾는다.
                mintime = dist[s][i];
            }
        }
    }

    for(int i=1; i<=p; i++){
        if(i == s || i == e) continue;
        if(mintime == dist[s][i] && mincost == dist[s][i] + dist[i][e]){ // 지헌이의 거리가 가장 짧은 경우를
            can.push_back(i); // 담는다.
        }
    }

    if(!can.empty()){
        sort(can.begin(), can.end());
        residx = can[0];
    }
    cout << residx << '\n';
    return 0;
}