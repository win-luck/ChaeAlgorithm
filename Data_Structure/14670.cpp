#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<int, int> drug;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        drug[a] = b;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a;
        bool flag = false;
        vector<int> v;

        cin >> a;
        for(int j=0; j<a; j++){
            int b;
            cin >> b;
            if(drug.count(b) > 0){
                v.push_back(drug[b]);
            } else {
                flag = true;
            }
        }
        if(!flag){
            for(int j=0; j<v.size(); j++){
                cout << v[j] << " ";
            }
            cout << '\n';
        } else {
            cout << "YOU DIED\n";
        }
    }
    return 0;
}