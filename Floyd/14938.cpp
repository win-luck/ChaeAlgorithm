#include <iostream>

using namespace std;
int d[101][101];
int val[101];
#define INF 10000000

int main(){
    int N, M, R;
    cin >> N >> M >> R;

    for(int i=1; i<=N; i++){
        cin >> val[i];
    }

    for(int i=1; i<=R; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c; // a에서 b로 가는 거리는 c이다. 단방향
        d[b][a] = c;
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

    int result = 0;
    for(int i=1; i<=N; i++){
        int temp = 0;
        temp += val[i];
        for(int j=1; j<=N; j++){
            if(i == j) continue;

            if(d[i][j] <= M){
                temp += val[j];
            }
        }
        result = max(result, temp);
    }
    cout << result << endl;
    return 0;
}