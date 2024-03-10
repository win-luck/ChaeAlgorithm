#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int n, m;
char a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--){
        cin >> m;
        deque<char> d;
        for(int i=0; i<m; i++){
            cin >> a;
            if(d.empty() || d.front() >= a){
                d.push_front(a);
            } else {
                d.push_back(a);
            }
        }
        for(auto it: d){
            cout << it;
        }
        cout << '\n';
    }
    return 0;
}
