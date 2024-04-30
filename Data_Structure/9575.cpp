#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;
int t, a, b, c;
vector<int> v1, v2, v3;

bool validcheck(int sum){
    string s = to_string(sum);
    for(int i=0; i<s.size(); i++){
        if(s[i] != '5' && s[i] != '8') return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        v1.clear();
        v2.clear();
        v3.clear();

        cin >> a;
        v1.resize(a, 0);
        for(int i=0; i<a; i++){
            cin >> v1[i];
        }
        cin >> b;
        v2.resize(b, 0);
        for(int i=0; i<b; i++){
            cin >> v2[i];
        }
        cin >> c;
        v3.resize(c, 0);
        for(int i=0; i<c; i++){
            cin >> v3[i];
        }

        set<int> s;
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                for(int k=0; k<c; k++){
                    int sum = v1[i] + v2[j] + v3[k];
                    if(validcheck(sum)) s.insert(sum);
                }
            }
        }
        cout << s.size() << '\n';
    }
    return 0;
}
