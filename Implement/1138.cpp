#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n, 0);
    for(int i=1; i<=n; i++){
        int tmp = 0;
        cin >> tmp;

        for(int j=0; j<n; j++){
            if(tmp == 0 && v[j] == 0){
                v[j] = i;
                break;
            }
            if(v[j] == 0){
                tmp--;
            }
        }
    }
    for(auto it: v){
        cout << it << " ";
    }
    return 0;
}
