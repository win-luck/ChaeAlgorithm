#include <iostream>
#include <algorithm>

using namespace std;
int n;
int b = 0, s = 0;
bool nprime[5000001];

int main(){
    cin >> n;
    nprime[1] = true;
    for(int i=2; i*i<=n; i++){
        if(!nprime[i]){
            for(int j=2; i*j<=n; j++){
                nprime[i*j] = true;
            }
        }
    }

    string a = "";
    for(int i=1; i<=n; i++){
        if(nprime[i]){
            a += 'B';
            b++;
        } else {
            if(!a.empty() && a.back() == 'B'){
                a.pop_back();
                b--;
                a += "SS";
                s += 2;
            } else {
                a += 'S';
                s++;
                reverse(a.begin(), a.end());
            }
        }
    }
    cout << b << " " << s;
    return 0;
}
