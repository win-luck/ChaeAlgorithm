#include <iostream>
#include <stack>

using namespace std;
long long k, num, sum;

int main(){
    long long sum = 0;
    cin >> k;
    stack<long long> s;
    for(int i=0; i<k; i++){
        cin >> num;
        if(num == 0){
            s.pop();
        } else {
            s.push(num);
        }
    }
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}