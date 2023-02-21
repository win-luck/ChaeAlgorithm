#include <iostream>
#include <vector>

using namespace std;
int d[21][21];
int answer[21][21];
int n;

int main(){
    int result = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> d[i][j];
            answer[i][j] = d[i][j];
        }
    }
    // 도로 개수가 최소일 때 모든 도로의 시간의 합 구하기

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == k || j == k) continue;
                if(d[i][j] > d[i][k] + d[k][j]){ // 현재 경로가 애초에 최소가 아니라는 뜻이므로 -1
                    cout << -1 << '\n';
                    return 0;
                }
                if(d[i][j] == d[i][k] + d[k][j]){ // 거쳐가는 거리 = 직행 거리이면 직행 도로를 없애도 된다.
                    answer[i][j] = 0;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            result += answer[i][j];
        }
    }
    cout << result / 2 << '\n'; // 대칭
    return 0;
}