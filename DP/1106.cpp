#include <iostream>
#include <vector>

using namespace std;
int n, c;
int res = 20002;
int cost[21], people[21];
int dp[100300] = { 0, }; // 인덱스만큼의 비용을 사용하여 유치한 고객 수
vector<pair<int, int > > v;

int main(){
    cin >> c >> n;
    for(int i=1; i<=n; i++){
        cin >> cost[i] >> people[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=100000; j++){ // 최대 10만 (1000명의 고객, 한 도시 당 최대 100원)
            if(j >= cost[i]){
                dp[j] = max(dp[j], dp[j-cost[i]] + people[i]);
            } 

            // "앱" 문제처럼 이 부분에서 dp값 갱신을 시도할 수 있으나, 현재 dp가 1차원 배열이기 때문에 최소를 담보할 수 없다.
            // 관성적으로 문제를 해결하려고 하면 안 된다는 교훈을 주는 문제.
        }
    }

    for(int j=1; j<=100000; j++){ // 처음부터 순회하며 최초로 c와 같거나 큰 부분이 정답 인덱스
        if(dp[j] >= c){
            cout << j << '\n';
            break;
        }
    }
    return 0;
}