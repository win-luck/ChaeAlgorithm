#include <iostream>

using namespace std;
int n;

int main(){
    int res = 0;
    cin >> n;
    for(int i=1; i<=n; i*=10){
        res += n - i + 1;
    }
    cout << res;
}