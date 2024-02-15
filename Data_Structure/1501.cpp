#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        string newstr = str;
        if(str.size() >= 4){
            sort(newstr.begin()+1, newstr.end()-1);
        }
        m[newstr]++;
    }

    cin >> k;
    cin.ignore();
    while(k--){
        long long answer = 1;
        string str;
        getline(cin, str);
        stringstream ss(str);
        string tmp;
        while(ss >> tmp){
            if(tmp.size() >= 4){
                sort(tmp.begin()+1, tmp.end()-1);
            }
            answer *= m[tmp];
        }
        cout << answer << '\n';
    }
    return 0;
}
