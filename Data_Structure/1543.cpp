#include <iostream>
#include <string>
#include <vector>

using namespace std;
string input;
string pattern;

bool validcheck(int idx){
    int pidx = 0;
    for(int i=idx; i<idx + pattern.size(); i++){
        if(pattern[pidx++] != input[i]) return false;
    }  
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, input);
    getline(cin, pattern);
    int cnt = 0;
    if(input.size() < pattern.size()) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0; i<=input.size()-pattern.size(); i++){
        if(validcheck(i)){
            i += pattern.size() - 1;
            cnt++;
            continue;
        }
    }
    cout << cnt;
    return 0;
}