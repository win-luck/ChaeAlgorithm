#include <iostream>
#include <algorithm>

using namespace std;
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int cnt = 0;
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            cnt++;
            if(cnt == k){
                answer = i;
                break;
            }
        }
    }
    if(cnt == k) cout << answer;
    else cout << 0;
    return 0;
}
