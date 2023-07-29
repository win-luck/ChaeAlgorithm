#include <iostream>
#include <vector>
#include <cstring>

#define INF 1000000
using namespace std;
int n, m;
int dist[301][301];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    } // 초기화

    for(int a=0; a<m; a++){
        int num;
        cin >> num;
        vector<int> v;
        for(int i=0; i<num; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }

        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                dist[v[i]][v[j]] = 1;
                dist[v[j]][v[i]] = 1;
            }
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    double res = INF;
    double cnt = n-1;
    for(int i=1; i<=n; i++){
        double sum = 0;
        for(int j=1; j<=n; j++){
            sum += dist[i][j];
        }
        double a = sum / cnt;
        res = min(res, a);
    }
    int ans = res * 100;
    cout << ans << '\n';
    return 0;
}
