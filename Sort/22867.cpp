#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
string str1, str2;
vector<pair<double, int> > v;

double caltime(string str){
    double hour = stod(str.substr(0, 2)) * 3600;
    double minute = stod(str.substr(3, 2)) * 60;
    double second = stod(str.substr(6));
    double res = hour + minute + second;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str1 >> str2;
        double left = caltime(str1);
        double right = caltime(str2);
        v.push_back(make_pair(left, 1));
        v.push_back(make_pair(right, 0));
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    int answer = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 1){
            cnt++;
        } else {
            answer = max(cnt, answer);
            cnt--;
        }
    }
    cout << answer;
    return 0;
}
