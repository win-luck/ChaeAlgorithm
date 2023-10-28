#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v;

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    double x, y;
    cin >> x >> y;
    double d = x / 100;
    int cnt = 0;
    cout << v.size() * (d);
    for(int i=0; i<n; i++){
        if(v[i] >= y){
            cnt++;
        }
    }
    cout << " " << cnt;
    return 0;
}
