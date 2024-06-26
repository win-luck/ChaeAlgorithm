#include <iostream>
#include <map>
#include <vector>

using namespace std;
int m;
map<long long, long long> x;
map<long long, long long> w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            x[b] = c;
            w[x[b]] = b;
        } else {
            cin >> b;
            cout << w[b] << '\n';
        }
    }
    return 0;
}
