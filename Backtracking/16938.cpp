#include <iostream>
#include <algorithm>

using namespace std;
int n, l, r, x;
int arr[16];
bool visited[16];
int answer = 0;

void dfs(int idx, int sum, int cnt, int minval, int maxval){
    if(l <= sum && sum <= r && cnt >= 2 && maxval-minval >= x){
        answer++;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, sum+arr[i], cnt+1, min(minval, arr[i]), max(maxval, arr[i]));
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r >> x;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0, 0, 0, 1000000001, -1);
    cout << answer;
    return 0;
}
