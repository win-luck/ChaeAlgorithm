#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    if(m == 1){
        cout << 1;
        return 0;
    }
    long long a=1;
    long long b=1;
    for(int i=1; i<=n; i++){
        a *= m;
    }
    for(int i=1; i<=n; i++){
        b *= m-1;
    }
    cout << (a-b) % 1000000007;
}
