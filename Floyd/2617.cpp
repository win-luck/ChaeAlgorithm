#include <iostream>

#define INF 100000
using namespace std;
int n, m;
int dist[101][101];
int arr[101] = {0, };

int main(){
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1; // a가 b보다 무겁다.
        dist[b][a] = -1; // b가 a보다 가볍다.
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k] == 1 && dist[k][j] == 1){ // 일반적인 플로이드 식이랑 다를 수 있다는 걸 인지했어야 했다.
                    dist[i][j] = 1;
                    dist[j][i] = -1;
                }
            }
        }
    }

    int cnt = 0;
    int limit = (n+1)/2; // "중간" 값이 될 수 없다는 것은, 타 값과 비교하였을 때 과반으로 가볍거나 무거운 상황을 가리킨다.
    for(int i=1; i<=n; i++){
        int heavy = 0;
        int light = 0;
        for(int j=1; j<=n; j++){
            if(dist[i][j] > 0 && dist[i][j] != INF){
                heavy++;
            } else if(dist[i][j] < 0){
                light++;
            }
        }
        if(light >= limit || heavy >= limit){ // 과반인 경우가 감지되면 중간값이 될 수 없는 것이다.
            cnt++;
        }
    }
    
    cout << cnt << '\n'; // 중간값이 뭔지 인지하지 못한 채 시간을 굉장히 버렸다. 
    // 문제를 읽고 코딩을 시작하는 습관을 가지자. 교훈을 준 문제.
    return 0;
}