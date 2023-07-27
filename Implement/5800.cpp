#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k, n;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    cin >> k;
    for(int i=1; i<=k; i++){
        int maxval, minval, val = 0;
        vector<int> v;

        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), cmp);
        minval = v.back();
        maxval = v.front();

        for(int i=0; i<n-1; i++){
            int gap = abs(v[i] - v[i+1]);
            val = max(val, gap);
        }

        cout << "Class " << i << '\n';
        cout << "Max " << maxval << ", ";
        cout << "Min " << minval << ", ";
        cout << "Largest gap " << val << '\n';
    }
    return 0;
}