#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 9876543

using namespace std;
int  long n, m, t;
int dist[512][512];
vector<string> answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int s=1; s<=t; s++){
        cin >> n >> m;
        memset(dist, INF, sizeof(dist));

        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j] && i!=j && dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        bool flag = true;
        int maxval = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(dist[i][j] >= INF){
                    cout << "Bez spojeni neni veleni!\n";
                    flag = false;
                    break;
                } else {
                    maxval = max(maxval, dist[i][j]);
                }
            }
            if(!flag) break;
        }
        if(flag){
            cout << "Nejvetsi vzdalenost je " << maxval << ".\n";
        }
    }
    return 0;
}
