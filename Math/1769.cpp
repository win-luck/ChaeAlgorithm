#include <iostream>
#include <algorithm>

using namespace std;
string n;
int cnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(int(n.size()) != 1){ // 한 자리가 될 때까지 반복
        long long sum = 0;
        for(unsigned i=0; i<n.size(); i++){
            sum += int(n[i]) - '0';
        }
        n = to_string(sum);
        cnt++;
    }
    cout << cnt << '\n';
    if(n == "3" || n == "6" || n == "9"){
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';
    return 0;
}