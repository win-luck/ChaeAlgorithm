#include <iostream>
#include <vector>

using namespace std;
int n, k;
long long arr[100001];
long long sum[100001] = {0, };
long long answer = -10e8;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    for(int i=0; i<=n-k; i++){
        if(sum[i+k] - sum[i] > answer){
            answer = sum[i+k] - sum[i];
        }
    }
    cout << answer << '\n';
    return 0;
}
