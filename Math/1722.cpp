#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int factorial(unsigned int n){
    if(n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    string str;
    int n;
    while(cin >> str >> n){
        cout << str << " " << n << " = ";

        if(n > factorial(str.length())){
            cout << "No permutation" << '\n';
            continue;
        }

        int cnt = 0;
        do {
            cnt++;
            if(cnt == n){
                cout << str << '\n';
                break;
            }
        } while (next_permutation(str.begin(), str.end()));

    }
    return 0;
}