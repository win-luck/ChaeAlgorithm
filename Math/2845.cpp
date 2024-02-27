#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int total = n * m;
    vector<int> v;
    for(int i=0; i<5; i++){
        int a;
        cin >> a;
        v.push_back(a-total);
    }
    for(int i=0; i<5; i++){
        cout << v[i] << " ";
    }
    return 0;
}
