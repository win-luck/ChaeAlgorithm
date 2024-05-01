#include <iostream>
#include <map>

using namespace std;
int n;
bool arr[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a;
        for(int j=0; j<a; j++){
            cin >> b;
            arr[i][b] = true;
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][k] == true && arr[k][j] == true){
                    arr[i][j] = true;
                }
            }
        }
    }

    bool flag = false;
    for(int i=1; i<=n-1; i++){
        if(arr[1][i] && arr[i][i]){
            flag = true;
            break;
        }
    }
    if(flag) cout << "CYCLE";
    else cout << "NO CYCLE";
    return 0;
}
