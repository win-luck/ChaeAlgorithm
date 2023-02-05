#include <iostream>

using namespace std;
int d[401][401];
#define INF 10000000

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c; // a에서 b로 가는 거리는 c이다. 단방향
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(d[i][j] == 0){ // 거리 초기화
                d[i][j] = INF;
            }
        }
    }

    // 플로이드-워셜 알고리즘
    for(int k=1; k<=N; k++){ // 경유점에 해당하는 노드가 제일 위에 있어야 하고
        for(int i=1; i<=N; i++){ // 그 다음 출발점
            for(int j=1; j<=N; j++){ // 그 다음 도착점이 된다.
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j]; // 거리 갱신
                }
            }
        }
    }
    
    int result = INF;
    for(int i=1; i<=N; i++){
        result = min(result, d[i][i]); // 자기 자신으로 돌아오는 길 -> 사이클 형성 경우 대조
    }
    cout << (result == INF ? -1 : result) << endl; // 만약 모든 사이클이 INF면 -1 출력
    return 0;
}