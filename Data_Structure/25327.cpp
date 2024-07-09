#include <iostream>
#include <map>

using namespace std;
int n, m;
map<string, int> dict;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string a, b, c;
        cin >> a >> b >> c;
        dict[a+b+c]++;
        dict["---"]++;
        dict[a+"--"]++;
        dict["-"+b+"-"]++;
        dict["--"+c]++;
        dict["-"+b+c]++;
        dict[a+"-"+c]++;
        dict[a+b+"-"]++;
    }
    for(int i=0; i<m; i++){
        string a, b, c;
        cin >> a >> b >> c;
        string now = a + b + c;
        cout << dict[now] << '\n';
    }
    return 0;
}
