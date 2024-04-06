#include <iostream>

using namespace std;
long long k, a, b, c, d;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cin >> a >> b >> c >> d;
    if(a*k + b == c*k + d){
        cout << "Yes " << a*k + b << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}
