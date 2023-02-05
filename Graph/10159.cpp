#include <iostream>

using namespace std;
int d[101][101];

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        d[a][b] = 1; // a가 b보다 더 무겁다는 의미이다. 즉 단방향이라고 봐야 한다. 양방향이라고 생각해서 뻘짓했다.
    }

    // 플로이드-워셜 알고리즘
    for(int k=1; k<=N; k++){ // 경유하는 노드가 제일 위에 있어야 하고
        for(int i=1; i<=N; i++){ // 그 다음 출발점
            for(int j=1; j<=N; j++){ // 그 다음 도착점이 된다.
                if(d[i][k] == 1 && d[k][j] == 1){ // i가 k보다 무겁고 k가 j보다 무거우면
                    d[i][j] = 1; // i는 j보다 무겁다.
                }
            }
        }
    }    
    
    for(int i=1; i<=N; i++){
        int count = 0;
        for(int j=1; j<=N; j++){
            if(i == j) continue; // 자기 자신 비교 제외
            if(d[i][j] == 0 && d[j][i] == 0){ // i가 j보다 무거운지도 모르고, j가 i보다 무거운지도 모름.
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}