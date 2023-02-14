#include <iostream>

using namespace std;
int d[201][201];
int res[201][201];
#define INF 10000000

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i != j){ // 거리 초기화
                d[i][j] = INF;
            }
        }
    }

    for(int i=1; i<=M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c; // a에서 b로 가는 거리는 c이다. 단방향
        d[b][a] = c;
        res[a][b] = b; // a에서 b로 갈 때 거치는 첫번째 노드는 일단 b
        res[b][a] = a;
    }

    // 플로이드-워셜 알고리즘
    for(int k=1; k<=N; k++){ // 경유점에 해당하는 노드가 제일 위에 있어야 하고
        for(int i=1; i<=N; i++){ // 그 다음 출발점
            for(int j=1; j<=N; j++){ // 그 다음 도착점이 된다.
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j]; // 거리 갱신
                    res[i][j] = res[i][k]; // i에서 j로 갈 때 첫 노드는 i에서 k로 갈 때 k에 해당하는 노드이다. 
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j) {
                cout << "- ";
            } else {
                cout << res[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}