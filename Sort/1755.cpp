#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;
map<int, string> dic;
vector<int> v;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    dic[1] = "one";
    dic[2] = "two";
    dic[3] = "three";
    dic[4] = "four";
    dic[5] = "five";
    dic[6] = "six";
    dic[7] = "seven";
    dic[8] = "eight";
    dic[9] = "nine";
    dic[0] = "zero";
}

bool cmp(int a, int b){
    if(a < 10 && b < 10){
        return dic[a] < dic[b];
    } else if(a < 10 && b >= 10){
        string tmp = "";
        tmp += dic[b/10] + " " + dic[b%10];
        return dic[a] < tmp;
    } else if(a >= 10 && b < 10){
        string tmp = "";
        tmp += dic[a/10] + " " + dic[a%10];
        return dic[b] > tmp;
    } else {
        string sa = dic[a/10] + " " + dic[a%10];
        string sb = dic[b/10] + " " + dic[b%10];
        return sa < sb;
    }
}

int main(){
    input();
    for(int i=m; i<=n; i++){
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
        cnt++;
        if(cnt == 10) {
            cnt = 0;
            cout << '\n';
        }
    }
    return 0;
}
