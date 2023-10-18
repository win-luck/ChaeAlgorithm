#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;

    cin >> n;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        for(long long j=a; ; j++){
            bool flag = false;
            if(j <= 1) continue;
            if(j == 2 || j == 3){
                cout << j << '\n';
                break;
            }
            for(long long k=2; k<=sqrt(j); k++){
                if(j % k == 0){
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}
