#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> buildings;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        buildings.push_back(input);
    }

    vector<int> count(n, 0);
    // 다른 고층 빌딩을 지나거나 접할 때 -> 접한다? 기울기?
    // 특정 빌딩에서 다른 빌딩의 기울기가 직전 기울기보다 커진다면 "보인다"라고 할 수 있다.
    // A에서 B가 보이면, B도 A가 보인다. 따라서 양쪽을 별도로 순회할 필요는 없이 양쪽 다 더해주기만 하면 된다.

    for(int i = 0; i < n; i++){
        double maxflag = -9999999999.0;
        for(int j = i+1; j<n; j++){
            double slope = (buildings[j] - buildings[i])*(1.0) / (j-i); // double이므로 int에서 확장 시 데이터 손실을 막기 위해 1.0을 곱해준다.
            if(slope > maxflag){
                maxflag = slope;
                count[i]++;
                count[j]++;
            }
        }
    }

    cout << *max_element(count.begin(), count.end()); // 벡터 내부 최대값 출력
}
