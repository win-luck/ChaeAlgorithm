#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v1(10, 0);
vector<int> v2(10, 0);

int main(){
    for(int i=0; i<10; i++){
        cin >> v1[i];
    }
    for(int i=0; i<10; i++){
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int sum1 = v1[9] + v1[8] + v1[7];
    int sum2 = v2[9] + v2[8] + v2[7];
    cout << sum1 << " " << sum2;
    return 0;
}
