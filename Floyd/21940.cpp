#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 200001
using namespace std;
int d[201][201];
int n, m, k;
int a, b, c;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    } // 초기화

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        d[a][b] = c;
    } // 간선 입력

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> a;
        v.push_back(a);
    } // 친구들
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    } // 플로이드

    int sum = INF;
    vector<pair<int, int> > ans;
    for(int i=1; i<=n; i++){
        int tmp = -1;
        for(int j=0; j<k; j++){
            tmp = max(tmp, d[i][v[j]] + d[v[j]][i]); // 왕복거리의 최대의
        }
        sum = min(sum, tmp); // 최소
        ans.push_back(make_pair(i, tmp));
    }
    
    for(int i=0; i<ans.size(); i++){
        if(ans[i].second == sum){
            cout << ans[i].first << " ";
        }
    }
    return 0;
}