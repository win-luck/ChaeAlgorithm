#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b, n;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    n = to_string(stoi(a) + stoi(b));
    reverse(n.begin(), n.end());
    cout << stoi(n);
    return 0;
}
