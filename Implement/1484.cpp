#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int g;
    bool flag = false;
    cin >> g;

    for(int i=2; i<=50001; i++){
        if(i > g) break;

        for(int j=1; j<i; j++){
            if(i + j > g) break;
            if((i+j) * (i-j) == g){
                cout << i << '\n';
                flag = true;
            }
        }
    }
    if(!flag) cout << -1;
    return 0;
}
