#include <iostream>
#include <algorithm>

using namespace std;

long long factorial(long long n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    long long week = 604800;
    long long a = factorial(n);
    cout << a / week;
    return 0;
}
