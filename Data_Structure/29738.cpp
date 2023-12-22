#include <iostream>

using namespace std;
int n, t;

int main(){
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> n;
        if(n > 4500){
            cout << "Case #" << i << ": " << "Round 1\n";
        } else if(n > 1000){
            cout << "Case #" << i << ": " << "Round 2\n";
        } else if(n > 25){
            cout << "Case #" << i << ": " << "Round 3\n";
        } else {
            cout << "Case #" << i << ": " << "World Finals\n";
        }
    }
    return 0;
}
