#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t, n, sum, a, b;

    cin >> t;
    while(t--){
        cin >> sum;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            sum += (a*b);
        }
        cout << sum << '\n';
    }
    return 0;
}
