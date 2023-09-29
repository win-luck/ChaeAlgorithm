#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int answer = 0;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        stack<char> s;
        string str = v[i];

        for(int j=0; j<str.size(); j++){
            if(s.empty() || s.top() != str[j]){
                s.push(str[j]);
            } else {
                s.pop();
            }
        }

        if(s.empty()){
            answer++;
        }
    }
    cout << answer;
    return 0;
}
