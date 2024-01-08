#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, answer = "";
    cin >> str;
    int n = str.size();
    
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            string tmp = str;
            reverse(tmp.begin(), tmp.begin()+i+1);
            reverse(tmp.begin()+i+1, tmp.begin()+j+1);
            reverse(tmp.begin()+j+1, tmp.end());
            if(answer == "" || tmp < answer){
                answer = tmp;
            }
        }
    }
    cout << answer;
    return 0;
}
