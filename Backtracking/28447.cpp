#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
int answer = -100001;
int arr[11][11];
bool visited[11];
vector<int> v;

void dfs(int idx, int cnt){
    if(cnt == k){
        int sum = 0;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                sum += arr[v[i]][v[j]];
            }
        }
        answer = max(answer, sum);
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i, cnt+1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if(k == 1){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);
    cout << answer;
    return 0;
}
