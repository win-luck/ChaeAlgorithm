#include <iostream>

using namespace std;


int main(){
    int n, m, r;
    cin >> n >> m >> r;
    int answer = (n+1)*(m+1)/(r+1) - 1;
    cout << answer;
    return 0;
}
