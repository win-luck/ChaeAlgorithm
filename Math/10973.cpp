#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, a;
vector<int> v;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a;
        v.push_back(a);
    }

    bool flag = false;
    do{
        if(flag){
            for(int i=0; i<n; i++){
                cout << v[i] << " ";
            }
            return 0;
        }
        flag = true;
    } while(prev_permutation(v.begin(), v.end())); 

    cout << -1;
    return 0;
}