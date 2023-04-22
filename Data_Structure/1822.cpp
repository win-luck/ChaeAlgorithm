#include <iostream>
#include <map>
#include <vector>

using namespace std;
int n, m;
int a;
map<int, bool> A;
map<int, bool> B;
vector<int> v;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a;
        A[a] = true;
    }
    for(int i=0; i<m; i++){
        cin >> a;
        A[a] = false;
    }

    for(auto it: A){
        if(it.second == true){
            v.push_back(it.first);
        }
    }

    if(v.empty()){
        cout << 0 << '\n';
    } else {
        cout << v.size() << '\n';
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
    }

    return 0;
}