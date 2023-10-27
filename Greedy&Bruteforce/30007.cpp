#include <iostream>

using namespace std;

int main(){
    int a, x, b, n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> x;
        cout << (a*(x-1)) + b << '\n';
    }
    return 0;
}
