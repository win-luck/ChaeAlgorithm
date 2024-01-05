#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    long long l = 0;
    long long r = 0;
    long long answer = 987654321;
    long long cnt = 0;
    bool flag = true;
    while(1){
        if(cnt >= k){ // k개 이상
            if(v[l] == 1) cnt--;
            l++;
            if(cnt < k){
                answer = min(answer, r-l+1);
            }
        } else {
            if(r > n) {
                if(answer == 987654321) flag = false;
                break;
            }
            if(v[r] == 1) cnt++;
            r++;
        }
    }
    if(!flag) answer = -1;
    cout << answer;
    return 0;
}
