#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
vector<int> v;
vector<int> idx;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        idx.push_back(i);
    }
    int cnt = 0;
    do{
        int val = 500;
        for(int i=0; i<n; i++){
            val += v[idx[i]];
            val -= k;
            if(val < 500) break;
            if(i == n-1) cnt++;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    cout << cnt;
    return 0;
}
