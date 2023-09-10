#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
int arr[12];
int op[4];
long long mins = 10000000001;
long long maxs = -10000000001;

void backtrack(int cnt, long long sum){
    if(cnt == n-1){ // 종료조건
        maxs = max(maxs, sum);
        mins = min(mins, sum);
        return;
    }

    for(int i=0; i<4; i++){
        if(op[i] == 0) continue;
        
        op[i]--;
        if(i == 0){
            backtrack(cnt + 1, sum + arr[cnt + 1]);
        } else if(i == 1){
            backtrack(cnt + 1, sum - arr[cnt + 1]);
        } else if(i == 2){
            backtrack(cnt + 1, sum * arr[cnt + 1]);
        } else {
            backtrack(cnt + 1, sum / arr[cnt + 1]);
        }
        op[i]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    backtrack(0, arr[0]);
    cout << maxs << '\n';
    cout << mins << '\n';
    return 0;
}
