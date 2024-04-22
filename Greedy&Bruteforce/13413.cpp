#include <iostream>

using namespace std;
int t, n;
string str1, str2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        cin >> str1;
        cin >> str2;
        int w = 0;
        int b = 0;

        for(int i=0; i<n; i++){
            if(str1[i] != str2[i]){
                if(str1[i] == 'B') b++;
                else w++;
            }
        }
        cout << (w > b ? w : b) << '\n';
    }
    return 0;
}
