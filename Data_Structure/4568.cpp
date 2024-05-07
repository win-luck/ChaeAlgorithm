#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
string str;
vector<char> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int a=1; ; a++){
        v.clear();
        cin >> n;
        if(n == 0) break;
        cin >> str;
        cout << "Simulation " << a << '\n';
        for(int i=0; i<str.size(); i++){
            if(str[i] == '!'){
                for(int i=v.size()-1; i>=0; i--){
                    cout << v[i];
                }
                cout << '\n';
            } else {
                if(find(v.begin(), v.end(), str[i]) == v.end()){ // 새로운 수
                    if(v.size() >= n){ // 포화 -> 기존 수 하나 지워야함
                        v.pop_back();
                        v.insert(v.begin(), str[i]);
                    } else { // 포화 X
                        v.insert(v.begin(), str[i]);
                    }
                } else { // 기존에 존재하던 수 -> 맨 앞으로 이동
                    v.erase(find(v.begin(), v.end(), str[i]));
                    v.insert(v.begin(), str[i]);
                }
            }
        }
    }
    return 0;
}
