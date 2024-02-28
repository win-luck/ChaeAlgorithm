#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[21][21];
bool visited[21];
int answer = 987654321;

void dfs(int idx, int cnt){
    if(idx >= n) return;

    if(cnt >= 1){
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i] && visited[j]){
                    sum1 += arr[i][j];
                }
                else if(!visited[i] && !visited[j]){
                    sum2 += arr[i][j];
                }
            }
        }
        answer = min(answer, abs(sum1-sum2));
    }

    visited[idx] = true;
    dfs(idx+1, cnt+1);
    visited[idx] = false;
    dfs(idx+1, cnt);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);
    cout << answer;
    return 0;
}
