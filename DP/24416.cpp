#include <iostream>

using namespace std;
int cnt1 = 0, cnt2 = 0;

void fib(int n){
    if(n == 1 || n == 2) {
        cnt1++;
        return;
    } else {
        fib(n-1);
        fib(n-2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    fib(n);
    cnt2 = n-2;
    cout << cnt1 << " " << cnt2;
    return 0;
}
