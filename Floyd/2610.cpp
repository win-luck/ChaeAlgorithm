#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define INF 10000
using namespace std;
int n, m;
int f, t;
int parent[101];
int maxs[101];
int reps[101];
int dp[101][101];
map<int, int> maps;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
        reps[i] = -1; // i번째 사람이 속한 집합의 대표
        parent[i] = i; // 부모 초기화
        maxs[i] = INF; // 
    }

    for(int i=0; i<m; i++){
        cin >> f >> t;
        dp[f][t] = 1;
        dp[t][f] = 1;
        merge(f, t); // 같은 위원회로 편입
    }

    /* 같은 집합 내에서 플로이드를 통해 그 집합 내에서 대장을 선출한다. */
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    // 조건: 특정 집합 내에서, 특정인으로부터 자신에게 가는 길이 가장 짧은 사람 = 대표
    for(int i=1; i<=n; i++){ // 조건을 완전히 잘못 이해해서 시간낭비
        int p = find(i);
        int dis = -1;
        for(int j=1; j<=n; j++){
            if(dp[i][j] == INF) continue;
            dis = max(dis, dp[i][j]);
        }
        if(maxs[p] > dis){ // 갱신 -> 부모에 해당하는 인덱스에 접근해 갱신
            maxs[p] = dis;
            reps[p] = i;
        }
    }

    vector<int> v;
    for(int i=1; i<=n; i++){
        if(reps[i] != -1) v.push_back(reps[i]); // 그 값을 벡터에 담아 정렬하면 정답
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    // map이 아니라 처음부터 vector였다면 더욱 편했을 것이다.
    // 자료구조를 다룰 때 번거로우면 과감하게 교체하는 결단이 필요했다.
}