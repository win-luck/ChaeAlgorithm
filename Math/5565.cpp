#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<9; i++){
        int a;
        cin >> a;
        n -= a;
    }
    cout << n;
    return 0;
}
