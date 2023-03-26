#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, bool> m;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++){
        for(int j=1; j<str.size()-i+1; j++){
            if(m[str.substr(i, j)]) continue;
            m[str.substr(i, j)] = true;
        }
    }

    cout << m.size();
    return 0;
}