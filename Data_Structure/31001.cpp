#include <iostream>
#include <map>
#include <vector>

using namespace std;
long long n, m, q;
map<long long, vector<string> > group;
map<string, long long> val;
map<string, long long> have;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for(long long i=0; i<n; i++){
        long long g, p;
        string h;
        cin >> g >> h >> p;
        group[g].push_back(h);
        val[h] = p;
        have[h] = 0;
    }
    for(long long i=0; i<q; i++){
        long long op;
        cin >> op;
        if(op == 1){
            string a;
            long long b;
            cin >> a >> b;

            if(m < val[a]*b) continue;
            m -= (val[a] * b);
            have[a] += b;
        } else if(op == 2){
            string a;
            long long b;
            cin >> a >> b;

            if(have[a] == 0) continue;
            if(have[a] <= b){
                m += val[a] * have[a];
                have[a] = 0;
            } else {
                m += val[a] * b;
                have[a] -= b;
            }
        } else if(op == 3){
            string a;
            long long c;
            cin >> a >> c;
            val[a] += c;
        } else if(op == 4){
            long long d, c;
            cin >> d >> c;

            for(auto it: group[d]){
                val[it] += c;
            }
        } else if(op == 5){
            long long d, e;
            cin >> d >> e;

            for(auto it: group[d]){
                val[it] = val[it] * (100+e) / 100;
                val[it] -= val[it] % 10;
            }
        } else if(op == 6){
            cout << m << '\n';
        } else {
            long long now = 0;
            for(auto it: have){
                now += it.second * val[it.first];
            }
            cout << m + now << '\n';
        }
    }
    return 0;
}
