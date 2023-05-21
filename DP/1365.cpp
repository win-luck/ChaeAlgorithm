#include <iostream>
#include <algorithm>
#include <vector>

#define INF 500001

using namespace std;
vector<pair<int, int> > line;
vector<int> LIS, idx;

// LIS + BinarySearch

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;

    cin >> n;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        line.push_back(make_pair(1, a));
    }

    LIS.push_back(line[0].second);
	idx.push_back(0);

    for(int i=1; i<n; i++){
        int pos = line[i].second;

        if(LIS.back() < pos){ // 자르지 않아도 되는 LIS 선
            idx.push_back(LIS.size()); // 현재 위치를 저장
            LIS.push_back(pos); // LIS 연장
        } else { // 이후에 잘라야 하는 선
            vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), pos);
            *iter = pos;
            idx.push_back(iter - LIS.begin());
        }
    }

    cout << n - LIS.size() << '\n';
    return 0;
}