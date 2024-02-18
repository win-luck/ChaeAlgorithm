#include <iostream>
#include <vector>
#include <map>
#include <cstring>


using namespace std;
int n, m, k;
int candy[30001];
int child[30001];
int cnt[30001];
int parent[30001];
int dp[3001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
        candy[a] += candy[b];
        cnt[a] += cnt[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    fill(candy, candy+30001, 0);
    fill(dp, dp+3001, 0);
    for(int i=1; i<=n; i++){
        cin >> candy[i];
        parent[i] = i;
        cnt[i] = 1;
    }

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        merge(a, b);
    }

    // knapsack
    for(int i=1; i<=n; i++){
        if(parent[i] != i) continue;
        int candies = candy[i];
        int nowcnt = cnt[i];
        for(int j=k-1; j>=nowcnt; j--){
            dp[j] = max(dp[j], dp[j-nowcnt] + candies);
        }
    }
    cout << dp[k-1];
    return 0;
}
