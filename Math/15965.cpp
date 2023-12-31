#include <iostream>

#define MAX 7368788
using namespace std;
bool not_prime[MAX];

int main(){
    int k;
    cin >> k;

    not_prime[1] = true;
    for(int i=2; i*i<=MAX; i++){
        if(!not_prime[i]){
            for(int j=2; i*j<=MAX; j++){
                not_prime[i*j] = true;
            }
        }
    }

    int cnt = 1;
    for(int i=2; i<=MAX; i++){
        if(!not_prime[i]){
            if(cnt == k){
                cout << i;
                return 0;
            }
            cnt++;
        }
    }
    return 0;
}
