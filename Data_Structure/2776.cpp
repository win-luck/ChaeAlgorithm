#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m, a;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> t;
    for(int k=0; k<t; k++){
        vector<int> v;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            v.push_back(a);
        }   

        sort(v.begin(), v.end());
        cin >> m;

        for(int i=0; i<m; i++){
            cin >> a;
            if(binary_search(v.begin(), v.end(), a)){ // 이분 탐색으로 존재 여부 확인
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}