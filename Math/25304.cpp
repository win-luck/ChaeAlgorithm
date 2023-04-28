#include <iostream>
#include <map>

using namespace std;
int n, a, b;
long long x;

int main(){
    long long sum = 0;
    cin >> x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        sum += a * b;
    }
    if(x == sum){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}