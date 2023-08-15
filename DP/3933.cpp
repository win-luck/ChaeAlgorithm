#include <iostream>
#include <cmath>

using namespace std;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        int ans = 0;
        cin >> n;
        if(n == 0) break;

        int m = sqrt(n);
        for(int i=1; i<=m; i++){
            if(i*i == n) {
                ans++;
                continue;
            }
            for(int j=i; j<=m; j++){
                if(i*i + j*j == n){
                    ans++;
                    continue;
                }
                for(int k=j; k<=m; k++){
                    if(i*i + j*j + k*k == n){
                        ans++;
                        continue;
                    }
                    for(int a=k; a<=m; a++){
                        if(i*i + j*j + k*k + a*a == n){
                            ans++;
                            continue;
                        }
                        if(i*i + j*j + k*k + a*a > n){
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}