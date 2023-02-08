#include <iostream>

using namespace std;
int d[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, s, a, b;
    cin >> n >> k;

    for(int i=0; i<k; i++){
        cin >> a >> b;
        d[a][b] = -1; // a가 b보다 먼저 일어나면 -1
        d[b][a] = 1;
    }

    // 플로이드-워셜 알고리즘
    for(int k=1; k<=n; k++){ // 경유점에 해당하는 노드가 제일 위에 있어야 하고
        for(int i=1; i<=n; i++){ // 그 다음 출발점
            for(int j=1; j<=n; j++){ // 그 다음 도착점이 된다.
                if(d[i][k] == 1 && d[k][j] == 1){
                    d[i][j] = 1;
                    d[j][i] = -1;
                }
            }
        }
    }

    cin >> s;
    for(int i=1; i<=s; i++){
        cin >> a >> b;
        cout << d[a][b] << '\n'; // endl은 '\n'보다 압도적인 시간 소모를 요구한다. '\n'을 사용하는 습관을 들이자.
    } // 사건의 전후 관계를 알고 싶은 쌍 입력

    return 0;
}