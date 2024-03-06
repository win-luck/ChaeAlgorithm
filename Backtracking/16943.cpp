#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string a, b;
int answer = -1;

int main(){
    cin >> a >> b;
    sort(a.begin(), a.end());
    int B = stoi(b);
    do {
        int now = stoi(a);
        if(answer < now && now <= B && a[0] != '0'){
            answer = now;
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << answer;
    return 0;
}
