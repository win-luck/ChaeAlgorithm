#include <iostream>
#include <cstring>

using namespace std;
int n, m, k, x, y;
int map[17][17];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    if(k == 0){
        x = n-1;
        y = m-1;
    } else {
        int cnt = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(cnt == k){
                    x = i;
                    y = j;
                }
                cnt++;
            }
        }
    }

    memset(map, 0, sizeof(map));
    for(int i=0; i<16; i++){
        map[0][i] = 1;
        map[i][0] = 1;
    }

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
    int sum1 = map[x][y];

    if(x == n-1 || y == m-1){ // 도착점이거나, 도착점과 직선 관계면 종료
        cout << sum1;
        return 0;
    }

    memset(map, 0, sizeof(map));

    map[x][y] = 1;
    for(int i=x+1; i<n; i++){
        map[i][y] = 1;
    }
    for(int i=y+1; i<m; i++){
        map[x][i] = 1;
    }
    for(int i=x+1; i<n; i++){
        for(int j=y+1; j<m; j++){
            map[i][j] = map[i][j-1] + map[i-1][j];
        }
    }
    int sum2 = map[n-1][m-1];
    cout << sum1 * sum2;
    return 0;
}
