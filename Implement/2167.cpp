#include <iostream>

using namespace std;
int n, m, k;
int map[301][301];

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    cin >> k;
    for(int i=0; i<k; i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int sum = 0;
        for(int j=sx; j<=ex; j++){
            for(int a=sy; a<=ey; a++){
                sum += map[j][a];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}