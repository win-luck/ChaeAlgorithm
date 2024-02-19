#include <iostream>
#include <vector>
#include <algorithm>

struct bus{
    int s;
    int e;
    int cost;
    bus(int a, int b, int c){
        s = a;
        e = b;
        cost = c;
    }
};
using namespace std;
int n;
vector<bus> v;

bool cmp(bus b1, bus b2){
    if(b1.s == b2.s) {
        if(b1.e == b2.e){
            return b1.cost < b2.cost;
        }
        return b1.e < b2.e;
    }
    return b1.s < b2.s;
}

bool cmp2(bus b1, bus b2){
    return b1.s < b2.s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        int s, e, c;
        cin >> s >> e >> c;
        v.push_back(bus(s, e, c));
    }
    sort(v.begin(), v.end(), cmp);
    vector<bus> answer;

    int l = v[0].s;
    int r = v[0].e;
    int nowcost = v[0].cost;
    if(n == 1){
        answer.push_back(bus(l, r, nowcost));
    }
    for(int i=1; i<v.size(); i++){
        if(v[i].s > r){
            answer.push_back(bus(l, r, nowcost));
            l = v[i].s;
            r = v[i].e, r;
            nowcost = v[i].cost;
        } else { // 겹침
            r = max(v[i].e, r);
            nowcost = min(nowcost, v[i].cost);
        }

        if(i == n-1){
            answer.push_back(bus(l, r, nowcost));
        }
    }
    sort(answer.begin(), answer.end(), cmp2);

    cout << answer.size() << '\n';
    for(int i=0; i<answer.size(); i++){
        cout << answer[i].s << " " << answer[i].e << " " << answer[i].cost << '\n';
    }
    return 0;
}
