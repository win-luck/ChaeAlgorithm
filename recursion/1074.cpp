#include <iostream>
#include <cmath>

using namespace std;
int n, a, b;
int res = 0;

void makeZ(int r, int c, int n){
    if(a == r && b == c){ // 도착
        cout << res << '\n';
        return;
    }

    if(a < r+n && a >= r && b < c+n && b >= c){
        makeZ(r, c, n/2);
        makeZ(r, c + n/2, n/2);
        makeZ(r + n/2, c, n/2);
        makeZ(r + n/2, c + n/2, n/2);
    } else {
        res += n * n;
    }
}

int main(){

    cin >> n >> a >> b;
    int k = 1;
    for(int i=1; i<=n; i++){
        k *= 2;
    }
    makeZ(0, 0, k);
    return 0;
}