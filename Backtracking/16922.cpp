#include <iostream>
#include <algorithm>

using namespace std;
int n;
bool isExist[1001] = {false, };
int val[4] = {1, 5, 10, 50};
int answer = 0;

void dfs(int cnt, int idx, int sum){
    if(cnt == n){
        if(isExist[sum] == false){
            isExist[sum] = true;
            answer++;
        }
        return;
    }

    for(int i=idx; i<4; i++){
        dfs(cnt+1, i, sum + val[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dfs(0, 0, 0);
    cout << answer;
    return 0;
}
